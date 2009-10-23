/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_PROCESSOR_X86_DESCRIPTORTABLES_GLOBAL_H
#define _LKEY_PROCESSOR_X86_DESCRIPTORTABLES_GLOBAL_H

#include <Type.h>

namespace Kernel {

namespace Processor {

namespace DescriptorTables {

class Global
{
  protected:
    Global (void) {};

  public:
    /**
     * Global Entry Descriptor
     */
    struct Entry {
        Type::u16 limitLow;     /*<< The lower 16 bits of the limit */
        Type::u16 baseLow;      /*<< The lower 16 bits of the base. */
        Type::u8  baseMiddle;   /*<< The next 8 bits of the base. */
        Type::u8  access;       /*<< Access flags, determine what ring this segment can be used in. */
        Type::u8  granularity;
        Type::u8  baseHigh;     /*<< The last 8 bits of the base. */
    } __attribute__ ((packed));

    /**
     * Global Descriptor Table pointer.
     */
    struct Pointer {
        Type::u16 limit; /*<< The upper 16 bits of all selector limits. */
        Type::u32 base;  /*<< The address of the first descriptor. */
    } __attribute__ ((packed));

  private:
    static Entry   _entries[7];
    static Pointer _pointer;

  public:
    static void init (void);

    static void set (Type::s32 index, Type::u32 base, Type::u32 limit, Type::u8 access, Type::u8 granularity);

    static void flush (void);
};

}

}

}

#endif
