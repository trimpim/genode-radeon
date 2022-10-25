/*
 * \brief  Linux Intel IGC network driver port
 * \author Pirmin Duss
 * \date   2022-06-22
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <base/component.h>
#include <base/env.h>
#include <base/heap.h>

/* linux includes */
//#include <linux/kthread.h>
//#include <linux/netdevice.h>
//#include <linux/sched.h>

/* emulation includes */
#include <lx_emul/init.h>
#include <lx_emul/task.h>
#include <lx_kit/env.h>
#include <lx_kit/init.h>
//#include <lx_user/init.h>

/* Genode C-API includes */
#include <genode_c_api/uplink.h>


//extern struct task_struct * lx_user_task;
//
//struct task_struct *uplink_task_struct_ptr;  /* used by 'Main' for lx_emul_task_unblock */


namespace Intel_igc {

	using namespace Genode;

	class Main;
}


class Intel_igc::Main : private Entrypoint::Io_progress_handler
{
	private:

		Env                   &_env;
		Signal_handler<Main>   _signal_handler { _env.ep(), *this, &Main::_handle_signal };
//		Sliced_heap            _sliced_heap    { env.ram(), env.rm()  };

		/**
		 * Entrypoint::Io_progress_handler
		 */
		void handle_io_progress() override
		{
//			genode_usb_notify_peers();
		}

		void _handle_signal()
		{
//			lx_user_handle_io();
//			Lx_kit::env().scheduler.schedule();
		}

	public:

		Main(Env &env) :
			_env(env)
		{
			log("--- Intel IGC nic driver started ---");

			Lx_kit::initialize(env);
			env.exec_static_constructors();

			lx_emul_start_kernel(nullptr);

			env.ep().register_io_progress_handler(*this);
		}

};


void Component::construct(Genode::Env &env)
{
	static Intel_igc::Main main(env);
}
