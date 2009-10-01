#include <Memory.h>

void*
Memory::alloc (Type::ulong size)
{
    /* OverMe */
}

void
Memory::free (void* pointer)
{
    /* OverMe */
}

Memory::Memory (Type::ulong size)
{
    _size   = size;
    _memory = Memory::alloc(_size);
}

Memory::Memory (Memory& memory)
{
    void* data = memory.data();
    _size      = memory.size();
    _memory    = Memory::alloc(_size);

    for (Type::ulong i = 0; i < _size; i++) {
        _memory[i] = data[i];
    }
}

Memory::~Memory ()
{
    Memory::free(_memory);
}

Type::ulong
Memory::size (void)
{
    return _size;
}

void
Memory::size (Type::ulong size)
{
    _size = size;
}

const void*
Memory::data (void)
{
    return _memory;
}

void
Memory::data (Memory& memory, Type::ulong offset)
{
    void*       data = memory.data();
    Type::ulong size = memory.size();

    for (Type:ulong i = offset; i < size; i++) {
        _memory[i] = data[i];
    }
}

void
Memory::data (void* memory, Type::ulong size, Type::ulong offset)
{
    for (Type:ulong i = offset; i < size; i++) {
        _memory[i] = memory[i];
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

Memory::operator Type::ulong ()
{
    return _size;
}

/**
 * This looks weird, I mean, object construction?
 */
void*
operator new (Type::ulong size)
{
    return Memory::alloc(size);
}

void*
operator new[] (Type::ulong size)
{
    return Memory::alloc(size);
}

/**
 * This looks weird, I mean, object destruction?
 */
void
operator delete (void* pointer)
{
    Memory::free(pointer);
}

void
operator delete[] (void* pointer)
{
    Memory::free(pointer);
}
