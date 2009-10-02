#include <Memory/Memory.h>

namespace Kernel {

void*
Memory::alloc (unsigned int size)
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
Memory::copy (void* source, void* destination, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) {
        ((unsigned char*) destination)[i] = ((unsigned char*) source)[i];
    }
}

Memory::Memory (unsigned int size)
{
    _size   = size;
    _memory = Memory::alloc(_size);
}

Memory::Memory (Memory& memory)
{
    const void* data = memory.data();

    _size   = memory.size();
    _memory = Memory::alloc(_size);

    for (unsigned int i = 0; i < _size; i++) {
        ((unsigned char*) _memory)[i] = ((unsigned char*) data)[i];
    }
}

Memory::~Memory ()
{
    Memory::free(_memory);
}

unsigned int
Memory::size (void)
{
    return _size;
}

void
Memory::size (unsigned int size)
{
    _size = size;
}

const void*
Memory::data (void)
{
    return _memory;
}

void
Memory::data (Memory& memory, unsigned int offset)
{
    const void* data = memory.data();
    unsigned int size = memory.size();

    for (unsigned int i = offset; i < size; i++) {
        ((unsigned char*) _memory)[i] = ((unsigned char*) data)[i];
    }
}

void
Memory::data (void* memory, unsigned int size, unsigned int offset)
{
    for (unsigned int i = offset; i < size; i++) {
        ((unsigned char*) _memory)[i] = ((unsigned char*) memory)[i];
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

Memory::operator unsigned int ()
{
    return _size;
}

}

/* kernel space new/delete */

void*
operator new (unsigned int size)
{
    return Kernel::Memory::alloc(size);
}

void*
operator new[] (unsigned int size)
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
