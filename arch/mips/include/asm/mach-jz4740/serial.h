/*
* Copyright (c) 2015 Imagination Technologies
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston,
* MA 02111-1307 USA
*/

#ifndef __JZ4740_SERIAL_H__
#define __JZ4740_SERIAL_H__

#ifdef CONFIG_MACH_JZ4740
# define BASE_BAUD (12000000 / 16)
#endif

#ifdef CONFIG_MACH_JZ4780
# define BASE_BAUD (48000000 / 16)
#endif

#endif /* __JZ4740_SERIAL_H__ */
