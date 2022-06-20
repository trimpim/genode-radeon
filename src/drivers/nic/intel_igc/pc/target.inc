REQUIRES    := x86

TARGET      := pc_intel_igc_nic_drv

LIBS        := base
LIBS        += pc_lx_emul

REL_PRG_DIR := $(realpath $(PRG_DIR)/../..)
PC_DIR      := $(realpath $(dir $(call select_from_repositories,src/include/lx_emul/initcall_order.h))/../../..)
DDE_DIR     := $(realpath $(dir $(call select_from_repositories,src/lib/lxip/include/nic.h))/../../../..)
OS_DIR      := $(realpath $(dir $(call select_from_repositories,src/lib/genode_c_api/uplink.cc))/../../..)
LX_SRC_DIR  := $(call select_from_ports,linux)/src/linux


INC_DIR     += $(REL_PRG_DIR)
INC_DIR     += $(PC_DIR)/src/include
INC_DIR     += $(DDE_DIR)/src/include
INC_DIR     += $(LX_SRC_DIR)/drivers/net/ethernet/intel/igc


SRC_CC      += component.cc
#SRC_CC      += socket_call.cc

SRC_C       += generated_dummies.c
SRC_C       += dummies.c
SRC_C       += timeout.c
SRC_C       += uplink.c
SRC_C       += lx_user.c
SRC_C       += lx_socket_call.c
#SRC_C       += lx_emul.c

# lx_emul sources
SRC_C   += lx_emul/common_dummies.c
SRC_C   += lx_emul/spec/x86/pci.c
SRC_C   += lx_emul/shadow/mm/page_alloc.c
SRC_C   += lx_emul/shadow/drivers/char/random.c

# Genode C-API backends sources
SRC_CC  += genode_c_api/uplink.cc


# sources from program directory
vpath %.c  $(REL_PRG_DIR)
vpath %.cc $(REL_PRG_DIR)

# sources form the pc repository
vpath %.c  $(PC_DIR)/src/lib/pc
vpath %.cc $(PC_DIR)/src/lib/pc

# sources form the dde_linux repository
vpath %.c  $(DDE_DIR)/src/lib
vpath %.cc $(DDE_DIR)/src/lib

# sources from the os repository
vpath %.cc $(OS_DIR)/src/lib


CC_C_OPT += -Wno-unused-label
CC_OPT_lx_socket_call += -DKBUILD_MODNAME='"lx_socket_call"'


#
# Original symbol is renamed to __real_* and references to original symbol
# are replaced by __wrap_*. Used to shadow schedule_timeout, see timeout.c
#
LD_OPT += --wrap=schedule_timeout

# vim : ft=make
