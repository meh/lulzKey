/**
 * @file Memory.h
 *
 * @brief Memory management namespace.
 */

#include <Type.h>

namespace Memory {
    void* alloc (Type::ulong size);
    void* free (void* pointer);
}

// Kernel space new's
void* operator new (Type::ulong size);
void* operator new[] (Type::ulong size)

// Kernel space delete's
void operator delete (void* pointer)
void operator delete[] (void* pointer)
