/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Memory/Memory.h>

namespace Kernel {

void
Memory::copy (void* destination, void* source, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = ((Type::u8*) source)[i];
    }
}

void
Memory::set (void* destination, Type::u8 value, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = value;
    }
}

}

