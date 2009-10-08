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

#include <Memory/Memory.h>

namespace Kernel {

extern "C" Type::u32 __end;
Type::u32 Memory::_address = (Type::u32) &__end;

void*
Memory::alloc (Type::u32 size, bool aligned)
{
    if (size < 1) {
        return NULL;
    }

    return Memory::_alloc(size, NULL, aligned);
}

void*
Memory::alloc (Type::u32 size, void** physical, bool aligned)
{
    if (size < 1) {
        return NULL;
    }

    return Memory::_alloc(size, physical, aligned);
}

void
Memory::free (void* pointer)
{
    if (pointer == NULL) {

    }
}

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

void*
Memory::_alloc (Type::u32 size, void** physical, bool align)
{
    if (align && (Memory::_address & 0xFFFFF000)) {
        Memory::_address &= 0xFFFFF000;
        Memory::_address += 0x1000;
    }

    if (physical) {
        *physical = (void*) Memory::_address;
    }

    void* tmp = (void*) Memory::_address;
    Memory::_address += size;

    return tmp;
}

Memory::Memory (Type::u32 size)
{
    _size   = size;
    _memory = Memory::alloc(_size);
}

Memory::Memory (Memory& memory)
{
    const void* data = memory.data();

    _size   = memory.size();
    _memory = Memory::alloc(_size);

    for (Type::u32 i = 0; i < _size; i++) {
        ((Type::u8*) _memory)[i] = ((Type::u8*) data)[i];
    }
}

Memory::~Memory ()
{
    Memory::free(_memory);
}

Type::u32
Memory::size (void)
{
    return _size;
}

void
Memory::size (Type::u32 size)
{
    _size = size;
}

const void*
Memory::data (void)
{
    return _memory;
}

void
Memory::data (Memory& memory, Type::u32 offset)
{
    const void* data = memory.data();
    Type::u32   size = memory.size();

    for (Type::u32 i = offset; i < size; i++) {
        ((Type::u8*) _memory)[i] = ((Type::u8*) data)[i];
    }
}

void
Memory::data (void* memory, Type::u32 size, Type::u32 offset)
{
    for (Type::u32 i = offset; i < size; i++) {
        ((Type::u8*) _memory)[i] = ((Type::u8*) memory)[i];
    }
}

void*
Memory::pointer (void)
{
    return _memory;
}

/* operators */

Memory::operator void* ()
{
    return _memory;
}

Memory::operator Type::u32 ()
{
    return _size;
}

}

/* kernel space new/delete */

void*
operator new (Type::u32 size)
{
    return Kernel::Memory::alloc(size);
}

void*
operator new[] (Type::u32 size)
{
    return Kernel::Memory::alloc(size);
}

void
operator delete (void* pointer)
{
    Kernel::Memory::free(pointer);
}

void
operator delete[] (void* pointer)
{
    Kernel::Memory::free(pointer);
}
