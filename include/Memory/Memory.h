/**
 * @file Memory.h
 *
 * @brief Memory management namespace.
 */

#ifndef _LKEY_MEMORY_H
#define _LKEY_MEMORY_H

#include <Type.h>

class Memory
{
  public:
    static void* alloc (Type::uint size);
    static void  free  (void* pointer);

  private:
    void*       _memory;
    Type::uint _size;

  public:
    Memory (Type::uint size);
    Memory (Memory& memory);

    virtual ~Memory ();

    inline Type::uint size (void);
    inline void        size (Type::uint size);

    inline const void* data (void);
                 void  data (Memory& memory, Type::uint offset = 0);
                 void  data (void* memory, Type::uint size, Type::uint offset = 0);

    void* pointer (void);

  public:
    operator void*       ();
    operator Type::uint ();
};

// Kernel space new's
void* operator new   (Type::uint size);
void* operator new[] (Type::uint size);

// Kernel space delete's
void operator delete   (void* pointer);
void operator delete[] (void* pointer);

#endif
