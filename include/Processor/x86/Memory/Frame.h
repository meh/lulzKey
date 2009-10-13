/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
