/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
