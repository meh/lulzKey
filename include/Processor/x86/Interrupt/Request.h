/****************************************************************************
 * lulzKey. Let's close those effin Windows so penguins won't enter.        *
 *                                                                          *
 * Copyright (C) 2009  meh. [http://meh.doesntexist.org]                    *
 *                                                                          *
 * This program is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 ****************************************************************************/

#ifndef _LKEY_INTERRUPT_REQUEST_H
#define _LKEY_INTERRUPT_REQUEST_H

#define IRQ(n) __irq## n
#define DEFINE_IRQ(n) extern "C" void __irq##n ()

DEFINE_IRQ(0);
DEFINE_IRQ(1);
DEFINE_IRQ(2);
DEFINE_IRQ(3);
DEFINE_IRQ(4);
DEFINE_IRQ(5);
DEFINE_IRQ(6);
DEFINE_IRQ(7);
DEFINE_IRQ(8);
DEFINE_IRQ(9);
DEFINE_IRQ(10);
DEFINE_IRQ(11);
DEFINE_IRQ(12);
DEFINE_IRQ(13);
DEFINE_IRQ(14);
DEFINE_IRQ(15);

#endif
