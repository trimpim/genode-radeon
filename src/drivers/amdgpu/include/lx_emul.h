


#ifndef AMDGPU_LX_EMUL_H
#define AMDGPU_LX_EMUL_H


/*
 *  include/linux/types.h
 */
typedef  int                 int32_t;
typedef  unsigned int        uint32_t;
typedef  _Bool               bool;
typedef  long long           int64_t;
typedef  unsigned long long  uint64_t;

typedef  int32_t             s32;
typedef  int64_t             s64;

struct list_head {
	struct list_head *next, *prev;
};


/*
 *  include/asm-generic/atomic64.h
 */
typedef struct {
	s64 counter;
} atomic64_t;


/*
 *  include/asm-generic/atomic-long.h
 */
#ifdef CONFIG_64BIT
typedef atomic64_t atomic_long_t;
#define ATOMIC_LONG_INIT(i)		ATOMIC64_INIT(i)
#define atomic_long_cond_read_acquire	atomic64_cond_read_acquire
#define atomic_long_cond_read_relaxed	atomic64_cond_read_relaxed
#else
typedef atomic_t atomic_long_t;
#define ATOMIC_LONG_INIT(i)		ATOMIC_INIT(i)
#define atomic_long_cond_read_acquire	atomic_cond_read_acquire
#define atomic_long_cond_read_relaxed	atomic_cond_read_relaxed
#endif


/*
 *  include/linux/workqueue.h
 */
struct work_struct;
typedef void (*work_func_t)(struct work_struct *work);

struct work_struct {
	atomic_long_t data;
	struct list_head entry;
	work_func_t func;
	#ifdef CONFIG_LOCKDEP
	struct lockdep_map lockdep_map;
	#endif
};


/*
 *  include/linux/tracepoint.h
 */
#define TP_PROTO(args...)    args

#define __DECLARE_TRACE_RCU(name, proto, args, cond, data_proto, data_args)

#define __DECLARE_TRACE(name, proto, args, cond, data_proto, data_args) \
	extern int __traceiter_##name(data_proto);			\
	DECLARE_STATIC_CALL(tp_func_##name, __traceiter_##name);	\
	extern struct tracepoint __tracepoint_##name;			\
	static inline void trace_##name(proto)				\
	{								\
		if (static_key_false(&__tracepoint_##name.key))		\
			__DO_TRACE(name,				\
				TP_PROTO(data_proto),			\
				TP_ARGS(data_args),			\
				TP_CONDITION(cond), 0);			\
		if (IS_ENABLED(CONFIG_LOCKDEP) && (cond)) {		\
			rcu_read_lock_sched_notrace();			\
			rcu_dereference_sched(__tracepoint_##name.funcs);\
			rcu_read_unlock_sched_notrace();		\
		}							\
	}								\
	__DECLARE_TRACE_RCU(name, PARAMS(proto), PARAMS(args),		\
		PARAMS(cond), PARAMS(data_proto), PARAMS(data_args))	\
	static inline int						\
	register_trace_##name(void (*probe)(data_proto), void *data)	\
	{								\
		return tracepoint_probe_register(&__tracepoint_##name,	\
						(void *)probe, data);	\
	}								\
	static inline int						\
	register_trace_prio_##name(void (*probe)(data_proto), void *data,\
				   int prio)				\
	{								\
		return tracepoint_probe_register_prio(&__tracepoint_##name, \
					      (void *)probe, data, prio); \
	}								\
	static inline int						\
	unregister_trace_##name(void (*probe)(data_proto), void *data)	\
	{								\
		return tracepoint_probe_unregister(&__tracepoint_##name,\
						(void *)probe, data);	\
	}								\
	static inline void						\
	check_trace_callback_type_##name(void (*cb)(data_proto))	\
	{								\
	}								\
	static inline bool						\
	trace_##name##_enabled(void)					\
	{								\
		return static_key_false(&__tracepoint_##name.key);	\
	}


/*
 * include/linux/trace_events.h
 */
struct trace_entry {
	unsigned short    type;
	unsigned char     flags;
	unsigned char     preempt_count;
	int               pid;
};


/*
 *  include/trace/trace_events.h
 */
#define DECLARE_EVENT_CLASS(name, proto, args, tstruct, assign, print)  \
	struct trace_event_raw_##name {                                     \
		struct trace_entry   ent;                                       \
		tstruct                                                         \
		char                 __data[0];                                 \
	};                                                                  \
                                                                        \
	static struct trace_event_class event_class_##name;

#define DEFINE_EVENT(template, call, proto, args)                            \
	static inline void ftrace_test_probe_##call(void)                        \
	{                                                                        \
		check_trace_callback_type_##call(trace_event_raw_event_##template);  \
	}

#define TP_STRUCT__entry(args...)   args
#define __field(type, item)         type   item;


/*
 *  drivers/gpu/drm/amd/display/dc/irq_types.h
 */
/* The order of the IRQ sources is important and MUST match the one's
of base driver */
enum dc_irq_source {
	/* Use as mask to specify invalid irq source */
	DC_IRQ_SOURCE_INVALID = 0,

	DC_IRQ_SOURCE_HPD1,
	DC_IRQ_SOURCE_HPD2,
	DC_IRQ_SOURCE_HPD3,
	DC_IRQ_SOURCE_HPD4,
	DC_IRQ_SOURCE_HPD5,
	DC_IRQ_SOURCE_HPD6,

	DC_IRQ_SOURCE_HPD1RX,
	DC_IRQ_SOURCE_HPD2RX,
	DC_IRQ_SOURCE_HPD3RX,
	DC_IRQ_SOURCE_HPD4RX,
	DC_IRQ_SOURCE_HPD5RX,
	DC_IRQ_SOURCE_HPD6RX,

	DC_IRQ_SOURCE_I2C_DDC1,
	DC_IRQ_SOURCE_I2C_DDC2,
	DC_IRQ_SOURCE_I2C_DDC3,
	DC_IRQ_SOURCE_I2C_DDC4,
	DC_IRQ_SOURCE_I2C_DDC5,
	DC_IRQ_SOURCE_I2C_DDC6,

	DC_IRQ_SOURCE_DPSINK1,
	DC_IRQ_SOURCE_DPSINK2,
	DC_IRQ_SOURCE_DPSINK3,
	DC_IRQ_SOURCE_DPSINK4,
	DC_IRQ_SOURCE_DPSINK5,
	DC_IRQ_SOURCE_DPSINK6,

	DC_IRQ_SOURCE_TIMER,

	DC_IRQ_SOURCE_PFLIP_FIRST,
	DC_IRQ_SOURCE_PFLIP1 = DC_IRQ_SOURCE_PFLIP_FIRST,
	DC_IRQ_SOURCE_PFLIP2,
	DC_IRQ_SOURCE_PFLIP3,
	DC_IRQ_SOURCE_PFLIP4,
	DC_IRQ_SOURCE_PFLIP5,
	DC_IRQ_SOURCE_PFLIP6,
	DC_IRQ_SOURCE_PFLIP_UNDERLAY0,
	DC_IRQ_SOURCE_PFLIP_LAST = DC_IRQ_SOURCE_PFLIP_UNDERLAY0,

	DC_IRQ_SOURCE_GPIOPAD0,
	DC_IRQ_SOURCE_GPIOPAD1,
	DC_IRQ_SOURCE_GPIOPAD2,
	DC_IRQ_SOURCE_GPIOPAD3,
	DC_IRQ_SOURCE_GPIOPAD4,
	DC_IRQ_SOURCE_GPIOPAD5,
	DC_IRQ_SOURCE_GPIOPAD6,
	DC_IRQ_SOURCE_GPIOPAD7,
	DC_IRQ_SOURCE_GPIOPAD8,
	DC_IRQ_SOURCE_GPIOPAD9,
	DC_IRQ_SOURCE_GPIOPAD10,
	DC_IRQ_SOURCE_GPIOPAD11,
	DC_IRQ_SOURCE_GPIOPAD12,
	DC_IRQ_SOURCE_GPIOPAD13,
	DC_IRQ_SOURCE_GPIOPAD14,
	DC_IRQ_SOURCE_GPIOPAD15,
	DC_IRQ_SOURCE_GPIOPAD16,
	DC_IRQ_SOURCE_GPIOPAD17,
	DC_IRQ_SOURCE_GPIOPAD18,
	DC_IRQ_SOURCE_GPIOPAD19,
	DC_IRQ_SOURCE_GPIOPAD20,
	DC_IRQ_SOURCE_GPIOPAD21,
	DC_IRQ_SOURCE_GPIOPAD22,
	DC_IRQ_SOURCE_GPIOPAD23,
	DC_IRQ_SOURCE_GPIOPAD24,
	DC_IRQ_SOURCE_GPIOPAD25,
	DC_IRQ_SOURCE_GPIOPAD26,
	DC_IRQ_SOURCE_GPIOPAD27,
	DC_IRQ_SOURCE_GPIOPAD28,
	DC_IRQ_SOURCE_GPIOPAD29,
	DC_IRQ_SOURCE_GPIOPAD30,

	DC_IRQ_SOURCE_DC1UNDERFLOW,
	DC_IRQ_SOURCE_DC2UNDERFLOW,
	DC_IRQ_SOURCE_DC3UNDERFLOW,
	DC_IRQ_SOURCE_DC4UNDERFLOW,
	DC_IRQ_SOURCE_DC5UNDERFLOW,
	DC_IRQ_SOURCE_DC6UNDERFLOW,

	DC_IRQ_SOURCE_DMCU_SCP,
	DC_IRQ_SOURCE_VBIOS_SW,

	DC_IRQ_SOURCE_VUPDATE1,
	DC_IRQ_SOURCE_VUPDATE2,
	DC_IRQ_SOURCE_VUPDATE3,
	DC_IRQ_SOURCE_VUPDATE4,
	DC_IRQ_SOURCE_VUPDATE5,
	DC_IRQ_SOURCE_VUPDATE6,

	DC_IRQ_SOURCE_VBLANK1,
	DC_IRQ_SOURCE_VBLANK2,
	DC_IRQ_SOURCE_VBLANK3,
	DC_IRQ_SOURCE_VBLANK4,
	DC_IRQ_SOURCE_VBLANK5,
	DC_IRQ_SOURCE_VBLANK6,

	DC_IRQ_SOURCE_DC1_VLINE0,
	DC_IRQ_SOURCE_DC2_VLINE0,
	DC_IRQ_SOURCE_DC3_VLINE0,
	DC_IRQ_SOURCE_DC4_VLINE0,
	DC_IRQ_SOURCE_DC5_VLINE0,
	DC_IRQ_SOURCE_DC6_VLINE0,

	DC_IRQ_SOURCE_DC1_VLINE1,
	DC_IRQ_SOURCE_DC2_VLINE1,
	DC_IRQ_SOURCE_DC3_VLINE1,
	DC_IRQ_SOURCE_DC4_VLINE1,
	DC_IRQ_SOURCE_DC5_VLINE1,
	DC_IRQ_SOURCE_DC6_VLINE1,


	DAL_IRQ_SOURCES_NUMBER
};

enum irq_type
{
	IRQ_TYPE_PFLIP = DC_IRQ_SOURCE_PFLIP1,
	IRQ_TYPE_VUPDATE = DC_IRQ_SOURCE_VUPDATE1,
	IRQ_TYPE_VBLANK = DC_IRQ_SOURCE_VBLANK1,
};


#endif  /* AMDGPU_LX_EMUL_H */
