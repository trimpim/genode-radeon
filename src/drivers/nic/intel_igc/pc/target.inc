TARGET  := pc_intel_igc_nic_drv

LIBS    := base
LIBS    += igc_lx_emul
LIBS    += jitterentropy

INC_DIR += $(PRG_DIR)/../..
INC_DIR += $(REP_DIR)/../dde_linux/src/include

SRC_CC  += component.cc
SRC_CC  += genode_c_api/mac_address_reporter.cc
SRC_CC  += genode_c_api/uplink.cc

SRC_C   += dummies.c
SRC_C   += generated_dummies.c
SRC_C   += lx_emul.c
SRC_C   += lx_emul/common_dummies.c
SRC_C   += lx_user.c

vpath %.c  $(REP_DIR)/src/lib/pc
vpath %.cc $(REP_DIR)/src/lib/pc

vpath %.c $(PRG_DIR)/../..
vpath %.cc $(PRG_DIR)/../..

vpath generated_dummies.c $(PRG_DIR)

vpath lx_emul/common_dummies.c $(REP_DIR)/../pc/src/lib/pc

vpath genode_c_api/uplink.cc $(dir $(call select_from_repositories,src/lib/genode_c_api))

vpath genode_c_api/mac_address_reporter.cc $(dir $(call select_from_repositories,src/lib/genode_c_api))

# vim: ft=make
