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

#ifndef _LKEY_PROCESSOR_X86_MEMORY_FRAME_H
#define _LKEY_PROCESSOR_X86_MEMORY_FRAME_H

#include <Type.h>
#include <Processor/x86/Memory/Paging.h>

namespace Kernel {

namespace Processor {

namespace Memory {

namespace Frame {

extern Type::u32* frames;
extern Type::u32  frameNumber;

void alloc (Paging::Page* page, bool isKernel, bool isWriteable);

void free (Paging::Page* page);

void set (Type::u32 address);

void clear (Type::u32 address);

bool test (Type::u32 address);

Type::u32 findFirst (void);

}

}

}

}

#endif
