/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_PROCESSOR_X86_DESCRIPTORTABLES_INTERRUPT_H
#define _LKEY_PROCESSOR_X86_DESCRIPTORTABLES_INTERRUPT_H

#include <Type.h>

namespace Kernel {

namespace Processor {

namespace DescriptorTables {

class Interrupt
{
  protected:
    Interrupt (void) {};

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

  private:
    static Entry   _entries[256];
    static Pointer _pointer;

  public:
    static void init (void);

    static void set (Type::u8 index, Type::u32 base, Type::u16 segmentSelector, Type::u8 flags);

    static void flush (void);
};

}

}

}

#endif
