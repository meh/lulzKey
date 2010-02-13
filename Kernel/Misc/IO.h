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
 * @file Misc/IO.h
 *
 * @brief Low level input and output functions.
 */

#ifndef _LKEY_MISC_IO_H
#define _LKEY_MISC_IO_H

#include <Type.h>

namespace Kernel {

namespace Misc {

static const Type::u8  Byte = 0x1;
static const Type::u16 Word = 0x2;
static const Type::u32 Long = 0x4;

void     out (Type::u16 port, Type::u8 value);
Type::u8 in  (Type::u16 port, Type::u8 type);

void      out (Type::u16 port, Type::u16 value);
Type::u16 in  (Type::u16 port, Type::u16 type);

void      out (Type::u16 port, Type::u32 value);
Type::u32 in  (Type::u16 port, Type::u32 type);

}

}

#endif
