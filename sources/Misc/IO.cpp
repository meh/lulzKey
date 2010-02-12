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

/**
 * @file Misc/IO.cpp
 *
 * @brief Low level input and output functions
 */

#include <Misc/IO.h>

namespace Kernel {

namespace Misc {

void
out (Type::u16 port, Type::u8 value)
{
    asm volatile ("outb %0, %1" :: "a" (value), "dN" (port));
}

Type::u8
in (Type::u16 port, Type::u8 type)
{
    asm volatile ("inb %1, %0" : "=a" (type) : "dN" (port));
    return type;
}

void
out (Type::u16 port, Type::u16 value)
{
    asm volatile ("outw %0, %1" :: "a" (value), "dN" (port));
}

Type::u16
in (Type::u16 port, Type::u16 type)
{
    asm volatile ("inw %1, %0" : "=a" (type) : "dN" (port));
    return type;
}

void
out (Type::u16 port, Type::u32 value)
{
    asm volatile ("outl %0, %1" :: "a" (value), "dN" (port));
}

Type::u32
in (Type::u16 port, Type::u32 type)
{
    asm volatile ("inl %1, %0" : "=a" (type) : "dN" (port));
    return type;
}

}

}

