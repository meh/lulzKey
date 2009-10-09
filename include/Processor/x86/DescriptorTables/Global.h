/****************************************************************************
 * lulzKey. Let's close those effin Windows so penguins won't enter.        *
 *                                                                          *
 * Copyright (C) 2009  meh. [http://meh.doesntexist.org]                    *
 *                                                                          *
 * This program is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
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
