/**
 * @file Misc/IO.cpp
 *
 * @brief Low level input and output functions
 */

#include <Misc/IO.h>

namespace Kernel {

namespace Misc {

void
out (Type::u16 port, Type::u8 value)
{
    asm volatile ("outb %0, %1" :: "a" (value), "dN" (port));
}

Type::u8
in (Type::u16 port, Type::u8 type)
{
    asm volatile ("inb %1, %0" : "=a" (type) : "dN" (port));
    return type;
}

void
out (Type::u16 port, Type::u16 value)
{
    asm volatile ("outw %0, %1" :: "a" (value), "dN" (port));
}

Type::u16
in (Type::u16 port, Type::u16 type)
{
    asm volatile ("inw %1, %0" : "=a" (type) : "dN" (port));
    return type;
}

void
out (Type::u16 port, Type::u32 value)
{
    asm volatile ("outl %0, %1" :: "a" (value), "dN" (port));
}

Type::u32
in (Type::u16 port, Type::u32 type)
{
    asm volatile ("inl %1, %0" : "=a" (type) : "dN" (port));
    return type;
}

}

}

