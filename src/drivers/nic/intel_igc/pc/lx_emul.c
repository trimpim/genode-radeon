/*
 * \brief  Linux emulation environment specific to this driver
 * \author Josef Soentgen
 * \author Pirmin Duss
 * \date   2022-02-09
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#include <lx_emul.h>


void lx_backtrace(void)
{
}

void lx_emul_time_udelay(unsigned long usec)
{
}
