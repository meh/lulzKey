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
    asm volatile ("outb %0, %1" :: "dN" (port), "a" (value));
}

Type::u8
in (Type::u16 port, Type::u8 type)
{
    Type::u8 returned;

    asm volatile ("inb %1, %0" :: "=a" (ret), "dN" (port));

    return returned;
}

void
out (Type::u16 port, Type::u16 value)
{
    asm volatile ("inw
}

Type::u16 in  (Type::u16 port, Type::u16 type);

void      out (Type::u16 port, Type::u32 value);
Type::u32 in  (Type::u16 port, Type::u32 type);

}

}

