/**
 * @file Memory.h
 *
 * @brief Memory management namespace.
 */

#include <Type.h>

class Memory
{
  public:
    static void* alloc (Type::ulong size);
    static void  free  (void* pointer);

  private:
    void*       _memory;
    Type::ulong _size;

  public:
    Memory (Type::ulong size);
    Memory (Memory& memory);

    virtual ~Memory ();

    inline Type::ulong size (void);
    inline void        size (Type::ulong size);

    inline const void* data (void);
                 void  data (Memory& memory, Type::ulong offset = 0);
                 void  data (void* memory, Type::ulong size, Type::ulong offset = 0);

    void* pointer (void);

  public:
    operator void*       () const;
    operator Type::ulong () const;
}

// Kernel space new's
void* operator new   (Type::ulong size);
void* operator new[] (Type::ulong size)

// Kernel space delete's
void operator delete   (void* pointer)
void operator delete[] (void* pointer)
