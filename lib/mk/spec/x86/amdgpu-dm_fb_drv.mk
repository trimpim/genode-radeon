LX_CONTRIB_DIR := $(call select_from_ports,amdgpu)/src/drivers/amdgpu
LX_INC_BASE    := $(call select_from_ports,amdgpu)

LX_DM_SRC_DIR  := $(LX_CONTRIB_DIR)/drivers/gpu/drm/amd/display/amdgpu_dm

LIBS           += amdgpu_fb_include

INC_DIR        += $(REP_DIR)/src/drivers/amdgpu/include

INC_DIR        += $(LX_INC_BASE)/arch/x86/include
INC_DIR        += $(LX_INC_BASE)/arch/x86/include/uapi

INC_DIR        += $(LX_INC_BASE)/include
INC_DIR        += $(LX_INC_BASE)/include/uapi

INC_DIR        += $(LX_CONTRIB_DIR)/drivers/gpu/drm/amd/amdgpu
INC_DIR        += $(LX_CONTRIB_DIR)/drivers/gpu/drm/amd/display/dc

SRC_C          :=
SRC_C          += $(notdir $(wildcard $(LX_DM_SRC_DIR)/amdgpu_dm.c))
#SRC_C          += $(notdir $(wildcard $(LX_CONTRIB_DIR)/drivers/i2c/*.c))

CC_C_OPT       += -std=gnu89 -DNOTRACE -DCONFIG_64BIT

CC_WARN        := -Wall -Wno-uninitialized
CC_WARN        += -Wno-unused-but-set-variable
CC_WARN        += -Wno-unused-variable
CC_WARN        += -Wno-unused-function
CC_WARN        += -Wno-pointer-arith
CC_WARN        += -Wno-pointer-sign
CC_WARN        += -Wno-int-to-pointer-cast

vpath %.c $(LX_DM_SRC_DIR)
