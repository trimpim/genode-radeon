LX_CONTRIB_DIR := $(call select_from_ports,amdgpu)/src/drivers/framebuffer/amdgpu
#SRC_DIR        := $(REP_DIR)/src/drivers/framebuffer/amdgpu

#LIBS    += amdgpu_fb_include

SRC_C   :=
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/dma-buf/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/i2c/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/i2c/algos/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/gpu/drm/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/video/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/video/fbdev/core/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/lib/*.c))
SRC_C   += $(notdir $(wildcard $(LX_CONTRIB_DIR)/arch/x86/kernel/*.c))

#
# Linux sources are C89 with GNU extensions
#
CC_C_OPT += -std=gnu89

#
# Reduce build noise of compiling contrib code
#
CC_WARN = -Wall -Wno-uninitialized -Wno-unused-but-set-variable \
          -Wno-unused-variable -Wno-unused-function \
          -Wno-pointer-arith -Wno-pointer-sign \
          -Wno-int-to-pointer-cast

vpath %.c $(LX_CONTRIB_DIR)/drivers/dma-buf
vpath %.c $(LX_CONTRIB_DIR)/drivers/i2c
vpath %.c $(LX_CONTRIB_DIR)/drivers/i2c/algos
vpath %.c $(LX_CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu
vpath %.c $(LX_CONTRIB_DIR)/drivers/gpu/drm
vpath %.c $(LX_CONTRIB_DIR)/drivers/video
vpath %.c $(LX_CONTRIB_DIR)/drivers/video/fbdev/core
vpath %.c $(LX_CONTRIB_DIR)/lib
vpath %.c $(LX_CONTRIB_DIR)/arch/x86/kernel


CC_CXX_WARN_STRICT =
