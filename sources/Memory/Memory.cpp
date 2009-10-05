#include <Memory/Memory.h>

namespace Kernel {

void*
Memory::alloc (Type::u32 size)
{
    if (size < 1) {
        return NULL;
    }

    return NULL;
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
