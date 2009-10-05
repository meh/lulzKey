#ifndef _LKEY_DESCRIPTORS_INTERRUPT_H
#define _LKEY_DESCRIPTORS_INTERRUPT_H

#include <Type.h>

namespace Kernel {

namespace DescriptorTables {

class Interrupt
{
  public:
    /**
     * Interrupt Entry Descriptor
     */

    struct Entry {
        Type::u16 baseLow;         /*<< The lower 16 bits of the address to jump to when this interrupt fires. */
        Type::u16 segmentSelector; /*<< Kernel segment selector. */
        Type::u8  always0;         /*<< This must always be zero. */
        Type::u8  flags;           /*<< More flags. See documentation. */
        Type::u16 baseHigh;        /*<< The upper 16 bits of the address to jump to. */
    } __attribute__ ((packed));

    /**
     * Interrupt Descriptor Table pointer.
     */
    struct Pointer {
        Type::u16 limit; /*<< The upper 16 bits of all selector limits. */
        Type::u32 base;  /*<< The address of the first descriptor. */
    } __attribute__ ((packed));

  public:
    Interrupt (void);
};

}

}

#endif
