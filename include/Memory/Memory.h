/**
 * @file Memory.h
 *
 * @brief Memory management namespace.
 */

#ifndef _LKEY_MEMORY_H
#define _LKEY_MEMORY_H

#include <Type.h>

namespace Kernel {

class Memory
{
  public:
    static void* alloc (Type::u32 size);
    static void  free  (void* pointer);

    static void copy (void* destination, void* source, Type::u32 size);
    static void set  (void* destination, Type::u8 value, Type::u32 size); 

  private:
    void*       _memory;
    Type::u32 _size;

  public:
    Memory (Type::u32 size);
    Memory (Memory& memory);

    virtual ~Memory ();

    Type::u32 size (void);
    void      size (Type::u32 size);

    const void* data (void);
    void        data (Memory& memory, Type::u32 offset = 0);
    void        data (void* memory, Type::u32 size, Type::u32 offset = 0);

    void* pointer (void);

  public:
    operator void*     ();
    operator Type::u32 ();
};

}

// Kernel space new's
void* operator new   (Type::u32 size);
void* operator new[] (Type::u32 size);

// Kernel space delete's
void operator delete   (void* pointer);
void operator delete[] (void* pointer);

#endif
