/*
 * \brief  Linux Intel framebuffer driver port
 * \author Alexander Boettcher
 * \date   2022-03-08
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <base/attached_rom_dataspace.h>
#include <base/component.h>
#include <timer_session/connection.h>
#include <capture_session/connection.h>
#include <os/pixel_rgb888.h>
#include <os/reporter.h>
#include <util/reconstructible.h>

/* emulation includes */
#include <lx_emul/init.h>
#include <lx_emul/fb.h>
#include <lx_emul/task.h>
#include <lx_kit/env.h>
#include <lx_kit/init.h>

/* local includes */
extern "C" {
#include "lx_i915.h"
}


extern struct task_struct * lx_user_task;


namespace Framebuffer {
	using namespace Genode;
	struct Driver;
}


struct Framebuffer::Driver
{
	Env                    &env;
	Timer::Connection       timer    { env };
	Attached_rom_dataspace  config   { env, "config" };
	Expanding_reporter      reporter { env, "connectors", "connectors" };

	Signal_handler<Driver>  config_handler { env.ep(), *this,
	                                        &Driver::config_update };
	Signal_handler<Driver>  timer_handler  { env.ep(), *this,
	                                        &Driver::handle_timer };
	Signal_handler<Driver>  scheduler_handler { env.ep(), *this,
	                                           &Driver::handle_scheduler };

	bool                    update_in_progress { false };
	bool                    new_config_rom     { false };

	class Fb
	{
		private:

			Capture::Connection         _capture;
			Capture::Area const         _size;
			Capture::Area const         _size_phys;
			Capture::Connection::Screen _captured_screen;
			void                      * _base;

			/*
			 * Non_copyable
			 */
			Fb(const Fb&);
			Fb & operator=(const Fb&);

		public:

			void paint()
			{
				using Pixel = Capture::Pixel;
				Surface<Pixel> surface((Pixel*)_base, _size_phys);
				_captured_screen.apply_to_surface(surface);
			}

			Fb(Env & env, void * base, Capture::Area size,
			   Capture::Area size_phys)
			:
				_capture(env),
				_size(size),
				_size_phys(size_phys),
				_captured_screen(_capture, env.rm(), _size),
				_base(base) {}

			bool same_setup(void * base, Capture::Area &size,
			                Capture::Area &size_phys)
			{
				return ((base == _base) && (size == _size) &&
				        (size_phys == _size_phys));
			}
	};

	Constructible<Fb> fb {};

	void config_update();
	void generate_report(void *);
	void lookup_config(char const *, struct genode_mode &mode);

	void handle_timer()
	{
		if (fb.constructed()) { fb->paint(); }
	}

	void handle_scheduler()
	{
		Lx_kit::env().scheduler.execute();
	}

	Driver(Env &env) : env(env)
	{
		Lx_kit::initialize(env, scheduler_handler);
		env.exec_static_constructors();

		config.sigh(config_handler);
	}

	void start()
	{
		log("--- Intel framebuffer driver started ---");

		lx_emul_start_kernel(nullptr);

		timer.sigh(timer_handler);
		timer.trigger_periodic(20*1000);
	}

	void report_updated()
	{
		bool apply_config = true;

		if (config.valid())
			apply_config = config.xml().attribute_value("apply_on_hotplug", apply_config);

		/* trigger re-read config on connector change */
		if (apply_config)
			Genode::Signal_transmitter(config_handler).submit();
	}

	template <typename T>
	void with_max_enforcement(T const &fn) const
	{
		unsigned max_width  = config.xml().attribute_value("max_width", 0u);
		unsigned max_height = config.xml().attribute_value("max_height",0u);

		if (max_width && max_height)
			fn(max_width, max_height);
	}

	template <typename T>
	void with_force(T const &fn) const
	{
		unsigned force_width  = config.xml().attribute_value("force_width",  0u);
		unsigned force_height = config.xml().attribute_value("force_height", 0u);

		if (force_width && force_height)
			fn(force_width, force_height);
	}
};


enum { MAX_BRIGHTNESS = 100u };


void Framebuffer::Driver::config_update()
{
	config.update();

	if (!config.valid() || !lx_user_task)
		return;

	if (update_in_progress)
		new_config_rom = true;
	else
		update_in_progress = true;

	lx_emul_task_unblock(lx_user_task);
	Lx_kit::env().scheduler.execute();
}


static Framebuffer::Driver & driver(Genode::Env & env)
{
	static Framebuffer::Driver driver(env);
	return driver;
}


void Framebuffer::Driver::generate_report(void *lx_data)
{
	if (!config.valid())
		return;

	/* check for report configuration option */
	config.xml().with_optional_sub_node("report", [&](auto const &node) {

		if (!node.attribute_value("connectors", false))
			return;

		reporter.generate([&] (Genode::Xml_generator &xml) {
			/* reflect force/max enforcement in report for user clarity */
			with_max_enforcement([&](unsigned width, unsigned height) {
				xml.attribute("max_width",  width);
				xml.attribute("max_height", height);
			});

			with_force([&](unsigned width, unsigned height) {
				xml.attribute("force_width",  width);
				xml.attribute("force_height", height);
			});

			lx_emul_i915_report(lx_data, &xml);
		});

		driver(Lx_kit::env().env).report_updated();
	});
}


void Framebuffer::Driver::lookup_config(char const * const name,
                                        struct genode_mode &mode)
{
	/* default settings, possibly overridden by explicit configuration below */
	mode.enabled    = true;
	mode.brightness = 70 /* percent */;

	if (!config.valid())
		return;

	/* iterate independently of force* ever to get brightness and hz */
	config.xml().for_each_sub_node("connector", [&] (Xml_node &node) {
		typedef String<32> Name;
		Name const con_policy = node.attribute_value("name", Name());
		if (con_policy != name)
			return;

		mode.enabled = node.attribute_value("enabled", true);
		if (!mode.enabled)
			return;

		mode.brightness = node.attribute_value("brightness",
		                                       unsigned(MAX_BRIGHTNESS + 1));

		mode.width  = node.attribute_value("width",  0U);
		mode.height = node.attribute_value("height", 0U);
		mode.hz     = node.attribute_value("hz", 0U);
		mode.id     = node.attribute_value("mode_id", 0U);
	});

	mode.preferred = false;
	with_force([&](unsigned const width, unsigned const height) {
		mode.preferred = true;
		mode.width     = width;
		mode.height    = height;
		mode.id        = 0;
	});

	with_max_enforcement([&](unsigned const width, unsigned const height) {
		mode.max_width  = width;
		mode.max_height = height;
	});
}


/**
 * Can be called already as side-effect of `lx_emul_start_kernel`,
 * that's why the Driver object needs to be constructed already here.
 */
extern "C" void lx_emul_framebuffer_ready(void * base, unsigned long,
                                          unsigned xres, unsigned yres,
                                          unsigned phys_width,
                                          unsigned phys_height)
{
	auto &env = Lx_kit::env().env;
	auto &drv = driver(env);
	auto &fb  = drv.fb;

	Capture::Area area(xres, yres);
	Capture::Area area_phys(phys_width, phys_height);

	if (fb.constructed()) {
		if (fb->same_setup(base, area, area_phys))
			return;

		fb.destruct();
	}

	/* clear artefacts */
	if (area != area_phys)
		Genode::memset(base, 0, area_phys.count() * 4);

	fb.construct(env, base, area, area_phys);

	Genode::log("framebuffer reconstructed - virtual=", xres, "x", yres,
	            " physical=", phys_width, "x", phys_height);
}


extern "C" void lx_emul_i915_hotplug_connector(void *data)
{
	Genode::Env &env = Lx_kit::env().env;
	driver(env).generate_report(data);
}


void lx_emul_i915_report_connector(void * lx_data, void * genode_xml,
                                   char const *name, char const connected,
                                   unsigned brightness)
{
	auto &xml = *reinterpret_cast<Genode::Xml_generator *>(genode_xml);

	xml.node("connector", [&] ()
	{
		xml.attribute("name", name);
		xml.attribute("connected", !!connected);

		/* insane values means no brightness support - we use percentage */
		if (brightness <= MAX_BRIGHTNESS)
			xml.attribute("brightness", brightness);

		lx_emul_i915_iterate_modes(lx_data, &xml);
	});
}


void lx_emul_i915_report_modes(void * genode_xml, struct genode_mode *mode)
{
	if (!genode_xml || !mode)
		return;

	auto &xml = *reinterpret_cast<Genode::Xml_generator *>(genode_xml);

	xml.node("mode", [&] ()
	{
		xml.attribute("width",     mode->width);
		xml.attribute("height",    mode->height);
		xml.attribute("hz",        mode->hz);
		xml.attribute("mode_id",   mode->id);
		xml.attribute("mode_name", mode->name);
		if (!mode->enabled)
			xml.attribute("unavailable", true);
		if (mode->preferred)
			xml.attribute("preferred", true);
	});
}


void lx_emul_i915_connector_config(char * name, struct genode_mode * mode)
{
	if (!mode || !name)
		return;

	Genode::Env &env = Lx_kit::env().env;
	driver(env).lookup_config(name, *mode);
}


int lx_emul_i915_config_done_and_block(void)
{
	auto &state = driver(Lx_kit::env().env);

	bool const new_config = state.new_config_rom;

	state.update_in_progress = false;
	state.new_config_rom     = false;

	/* true if linux task should block, otherwise continue due to new config */
	return !new_config;
}


void Component::construct(Genode::Env &env)
{
	driver(env).start();
}
