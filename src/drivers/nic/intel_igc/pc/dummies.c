/*
 * \brief  Dummy definitions of Linux Kernel functions - handled manually
 * \author Alexander Boettcher
 * \author Josef Soentgen
 * \author Pirmin Duss
 * \date   2022-01-10
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <lx_emul/debug.h>
#include <linux/math64.h>
#include <linux/jump_label.h>

struct static_key_false init_on_alloc;
