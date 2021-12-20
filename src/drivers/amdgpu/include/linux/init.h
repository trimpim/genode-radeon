
#ifndef _SRC_DRIVERS_AMDGPU_INCLUDE_LINUX_INIT_H_
#define _SRC_DRIVERS_AMDGPU_INCLUDE_LINUX_INIT_H_

#include_next <linux/init.h>

#include <lx_emul/initcall_order.h>

#undef ___define_initcall
#undef __define_initcall

#define __define_initcall(fn, id) \
static void __initcall_##fn##id(void)__attribute__((constructor)); \
static void __initcall_##fn##id() { \
      lx_emul_register_initcall(fn, __func__); };

#endif

