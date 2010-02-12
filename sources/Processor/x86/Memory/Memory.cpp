/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Processor/x86/Memory/Memory.h>

namespace Kernel {

namespace Processor {

namespace Memory {

Type::u32 address = 0;

void*
alloc (Type::u32 size, bool aligned)
{
    if (size < 1) {
        return NULL;
    }

    return _alloc(size, NULL, aligned);
}

void*
alloc (Type::u32 size, void* physical, bool aligned)
{
    if (size < 1) {
        return NULL;
    }

    return _alloc(size, physical, aligned);
}

void
free (void* pointer)
{
    if (pointer == NULL) {

    }
}

void
copy (void* destination, void* source, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = ((Type::u8*) source)[i];
    }
}

void
set (void* destination, Type::u8 value, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = value;
    }
}

void*
_alloc (Type::u32 size, void* physical, bool align)
{
    if (align && (address & 0xFFFFF000)) {
        address &= 0xFFFFF000;
        address += 0x1000;
    }

    if (physical) {
        *(Type::u32*) physical = address;
    }

    void* tmp  = (void*) address;
    address   += size;

    return tmp;
}

}

}

}

