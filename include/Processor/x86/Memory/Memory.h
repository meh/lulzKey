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
 * @file Processor/x86/Memory/Memory.h
 *
 * @brief Memory management namespace.
 */

#ifndef _LKEY_PROCESSOR_X86_MEMORY_H
#define _LKEY_PROCESSOR_X86_MEMORY_H

#include <Type.h>

namespace Kernel {

namespace Processor {

namespace Memory {

extern Type::u32 address;

void* alloc (Type::u32 size, bool aligned = false);
void* alloc (Type::u32 size, void* physical, bool aligned = false);

void free  (void* pointer);

void copy (void* destination, void* source, Type::u32 size);
void set  (void* destination, Type::u8 value, Type::u32 size); 

void* _alloc (Type::u32 size, void* physical, bool align);

}

}

}

#endif
