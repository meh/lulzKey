/****************************************************************************
* lulzKey. Let's close those effin Windows so penguins won't enter.         *
*                                                                           *
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* lulzKey is free software: you can redistribute it and/or modify           *
* it under the terms of the GNU Affero General Public License as published  *
* by the Free Software Foundation, either version 3 of the License, or      *
* (at your option) any later version.                                       *
*                                                                           *
* lulzKey is distributed in the hope that it will be useful,                *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with lulzKey.  If not, see <http://www.gnu.org/licenses/>.          *
****************************************************************************/

#ifndef _LKEY_INTERRUPT_SERVICEROUTINE_H
#define _LKEY_INTERRUPT_SERVICEROUTINE_H

#define ISR(n) __isr## n
#define DEFINE_ISR(n) extern "C" void __isr##n ()

DEFINE_ISR(0);
DEFINE_ISR(1);
DEFINE_ISR(2);
DEFINE_ISR(3);
DEFINE_ISR(4);
DEFINE_ISR(5);
DEFINE_ISR(6);
DEFINE_ISR(7);
DEFINE_ISR(8);
DEFINE_ISR(9);
DEFINE_ISR(10);
DEFINE_ISR(11);
DEFINE_ISR(12);
DEFINE_ISR(13);
DEFINE_ISR(14);
DEFINE_ISR(15);
DEFINE_ISR(16);
DEFINE_ISR(17);
DEFINE_ISR(18);
DEFINE_ISR(19);
DEFINE_ISR(20);
DEFINE_ISR(21);
DEFINE_ISR(22);
DEFINE_ISR(23);
DEFINE_ISR(24);
DEFINE_ISR(25);
DEFINE_ISR(26);
DEFINE_ISR(27);
DEFINE_ISR(28);
DEFINE_ISR(29);
DEFINE_ISR(30);
DEFINE_ISR(31);

DEFINE_ISR(66);

#endif
