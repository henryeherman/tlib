/*
 *  RISC-V interface functions
 *
 *  Copyright (c) Antmicro
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
#include <stdint.h>
#include "cpu.h"

void tlib_set_mip(uint32_t value)
{
   cpu->mip = value;
}

uint32_t tlib_get_mip()
{
   return cpu->mip;
}

void tlib_allow_feature(uint32_t feature_bit)
{
   cpu->misa_mask |= (1L << feature_bit);
   cpu->misa |= (1L << feature_bit);
}

uint32_t tlib_is_feature_enabled(uint32_t feature_bit)
{
   return (cpu->misa & (1L << feature_bit)) != 0;
}

uint32_t tlib_is_feature_allowed(uint32_t feature_bit)
{
   return (cpu->misa_mask & (1L << feature_bit)) != 0;
}

void tlib_set_privilege_mode_1_09(uint32_t enable)
{
   cpu->privilege_mode_1_10 = enable ? 0 : 1;
}