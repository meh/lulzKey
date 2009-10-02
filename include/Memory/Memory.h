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
    static void* alloc (unsigned int size);
    static void  free  (void* pointer);
    static void  copy  (void* source, void* dest, unsigned int size);

  private:
    void*       _memory;
    unsigned int _size;

  public:
    Memory (unsigned int size);
    Memory (Memory& memory);

    virtual ~Memory ();

    unsigned int size (void);
    void         size (unsigned int size);

    const void* data (void);
          void  data (Memory& memory, unsigned int offset = 0);
          void  data (void* memory, unsigned int size, unsigned int offset = 0);

    void* pointer (void);

  public:
    operator void*        ();
    operator unsigned int ();
};

}

// Kernel space new's
void* operator new   (unsigned int size);
void* operator new[] (unsigned int size);

// Kernel space delete's
void operator delete   (void* pointer);
void operator delete[] (void* pointer);

#endif
