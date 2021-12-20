REQUIRES     = x86

TARGET       = amdgpu_fb_drv
LIBS        := base

CONTRIB_DIR := $(call select_from_ports,amdgpu)/src/drivers/amdgpu

CC_C_OPT += -nostdinc
CC_C_OPT += -isystem /usr/lib/gcc/x86_64-linux-gnu/9/include
CC_C_OPT += -include $(CONTRIB_DIR)/include/linux/kconfig.h
CC_C_OPT += -include $(CONTRIB_DIR)/include/linux/compiler_types.h

CC_C_OPT += -std=gnu89 -O2 -pg
#CC_C_OPT += -m64 -mcmodel=kernel -mfentry -mindirect-branch-register -mindirect-branch=thunk-extern
#CC_C_OPT += -mno-3dnow -mno-80387 -mno-avx -mno-fp-ret-in-387 -mno-mmx -mno-red-zone
#CC_C_OPT += -mno-sse -mno-sse2 -mpreferred-stack-boundary=3 -mrecord-mcount -mskip-rax-setup
#CC_C_OPT += -mtune=generic

CC_C_OPT += -Wall -Wdeclaration-after-statement -Werror=date-time -Werror=designated-init
CC_C_OPT += -Werror=implicit-function-declaration -Werror=implicit-int
#CC_C_OPT += -Werror=incompatible-pointer-types
CC_C_OPT += -Werror=return-type -Werror=strict-prototypes -Wframe-larger-than=2048 -Wimplicit-fallthrough
CC_C_OPT += -Wno-array-bounds -Wno-format-overflow -Wno-format-security
CC_C_OPT += -Wno-format-truncation -Wno-frame-address -Wno-maybe-uninitialized -Wno-packed-not-aligned
CC_C_OPT += -Wno-pointer-sign -Wno-restrict -Wno-sign-compare -Wno-stringop-overflow
CC_C_OPT += -Wno-stringop-truncation -Wno-trigraphs -Wno-unused-but-set-variable -Wno-unused-const-variable
CC_C_OPT += -Wundef -Wvla
CC_C_OPT += -Wno-shift-count-overflow

#CC_C_OPT += -falign-functions=32 -falign-jumps=1 -falign-loops=1 -fasan-shadow-offset=0xdffffc0000000000
#CC_C_OPT += -fcf-protection=none -fconserve-stack -fmacro-prefix-map=./= -fno-PIE
#CC_C_OPT += -fno-asynchronous-unwind-tables -fno-common -fno-delete-null-pointer-checks
#CC_C_OPT += -fno-inline-functions-called-once -fno-ipa-cp-clone -fno-jump-tables -fno-partial-inlining
#CC_C_OPT += -fno-reorder-blocks -fno-stack-check -fno-strict-aliasing -fno-strict-overflow
#CC_C_OPT += -fsanitize-coverage=trace-cmp -fsanitize-coverage=trace-pc -fsanitize=bool -fsanitize=bounds
#CC_C_OPT += -fsanitize=enum -fsanitize=integer-divide-by-zero -fsanitize=kernel-address -fsanitize=shift
#CC_C_OPT += -fsanitize=signed-integer-overflow -fshort-wchar -fstack-protector-strong

#CC_C_OPT += -DBUILD_FEATURE_TIMING_SYNC=0 -DCC_USING_FENTRY -DCONFIG_X86_X32_ABI
#CC_C_OPT += -DKBUILD_BASENAME='"amdgpu_drv"' -DKBUILD_MODFILE='"drivers/gpu/drm/amd/amdgpu/amdgpu"'
CC_C_OPT += -DKBUILD_MODFILE='"amdgpu"' -DKBUILD_MODNAME='"amdgpu"'
CC_C_OPT += -D__KERNEL__ -DCONFIG_MTRR -DCONFIG_X86_PAT


#  --param=allow-store-data-races=0
#  --param asan-globals=1
#  --param asan-instrumentation-with-call-threshold=0
#  --param asan-stack=1
#  --param asan-instrument-allocas=1


INC_DIR  += $(REP_DIR)/src/drivers/amdgpu/include

INC_DIR  += $(CONTRIB_DIR)/arch/x86/include
INC_DIR  += $(CONTRIB_DIR)/arch/x86/include/generated
INC_DIR  += $(CONTRIB_DIR)/arch/x86/include/generated/uapi
INC_DIR  += $(CONTRIB_DIR)/arch/x86/include/uapi
INC_DIR  += $(CONTRIB_DIR)/arch/x86/include/uapi/uapi
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../acp/include
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../amdgpu
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../amdkfd
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/amdgpu_dm
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/dc
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/dc/clk_mgr
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/dc/inc/
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/dc/inc/hw
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/dmub/inc
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/include
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/modules/color
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/modules/freesync
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/modules/hdcp
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/modules/inc
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/modules/info_packet
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../display/modules/power
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../include
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../include/asic_reg
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/inc
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/inc/
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/powerplay
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/powerplay/hwmgr
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/powerplay/smumgr
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/swsmu
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/swsmu/smu11
INC_DIR  += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/../pm/swsmu/smu12
INC_DIR  += $(CONTRIB_DIR)/include -I./arch/x86/include/uapi
INC_DIR  += $(CONTRIB_DIR)/include/generated/uapi
INC_DIR  += $(CONTRIB_DIR)/include/uapi

UNBUILT_C := $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/amdgpu_ioc32.c
UNBUILT_C += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/amdgpu_mn.c
UNBUILT_C += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/amdgpu_amdkfd_fence.c
UNBUILT_C += $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/amdgpu_amdkfd_gpuvm.c

LX_OBJECTS  = $(wildcard $(CONTRIB_DIR)/drivers/gpu/drm/amd/*.c)
LX_OBJECTS += $(wildcard $(CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/*.c))
LX_OBJECTS := $(filter-out $(UNBUILT_C), $(LX_OBJECTS))
SRC_C       = $(LX_OBJECTS:$(CONTRIB_DIR)/%=%)

SRC_CC     := $(REP_DIR)/src/drivers/amdgpu/component.cc

#SRC_C      += $(LX_REL_OBJ:%.o=%.c))
#

vpath %.c  $(CONTRIB_DIR)

all:
#	@echo "========================================================================="
#	@echo "$(LX_OBJECTS)"
#	@echo "========================================================================="
#	@echo "$(LX_OBJECTS)"
#	@echo "========================================================================="
#	@echo "$(LX_REL_OBJ)"
#	@echo "========================================================================="
