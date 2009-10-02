#include <Memory/Memory.h>

namespace Kernel {

void*
Memory::alloc (Type::uint size)
{
    /* OverMe */

    return NULL;
}

void
Memory::free (void* pointer)
{
    /* OverMe */
}

void
Memory::copy (void* source, void* destination, Type::uint size)
{
    for (Type::uint i = 0; i < size; i++) {
        ((Type::uchar*) destination)[i] = ((Type::uchar*) source)[i];
    }
}

Memory::Memory (Type::uint size)
{
    _size   = size;
    _memory = Memory::alloc(_size);
}

Memory::Memory (Memory& memory)
{
    const void* data = memory.data();

    _size   = memory.size();
    _memory = Memory::alloc(_size);

    for (Type::uint i = 0; i < _size; i++) {
        ((Type::uchar*) _memory)[i] = ((Type::uchar*) data)[i];
    }
}

Memory::~Memory ()
{
    Memory::free(_memory);
}

Type::uint
Memory::size (void)
{
    return _size;
}

void
Memory::size (Type::uint size)
{
    _size = size;
}

const void*
Memory::data (void)
{
    return _memory;
}

void
Memory::data (Memory& memory, Type::uint offset)
{
    const void* data = memory.data();
    Type::uint size = memory.size();

    for (Type::uint i = offset; i < size; i++) {
        ((Type::uchar*) _memory)[i] = ((Type::uchar*) data)[i];
    }
}

void
Memory::data (void* memory, Type::uint size, Type::uint offset)
{
    for (Type::uint i = offset; i < size; i++) {
        ((Type::uchar*) _memory)[i] = ((Type::uchar*) memory)[i];
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

Memory::operator Type::uint ()
{
    return _size;
}

}

/* kernel space new/delete */

void*
operator new (Type::uint size)
{
    return Kernel::Memory::alloc(size);
}

void*
operator new[] (Type::uint size)
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
