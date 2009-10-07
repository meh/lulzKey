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

#ifndef _LKEY_DESCRIPTORS_INTERRUPT_H
#define _LKEY_DESCRIPTORS_INTERRUPT_H

#include <Type.h>

namespace Kernel {

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

#endif
