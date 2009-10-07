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

#include <DescriptorTables/Interrupt.h>

#include <Interrupt/ServiceRoutine.h>
#include <Interrupt/Request.h>

#include <Memory/Memory.h>
#include <Misc/IO.h>

extern "C" void __idt_flush (Type::u32 address);

namespace Kernel {

namespace DescriptorTables {

Interrupt::Entry   Interrupt::_entries[256];
Interrupt::Pointer Interrupt::_pointer;

void
Interrupt::init (void)
{
    Interrupt::_pointer.limit = (sizeof(Interrupt::Entry) * 256) - 1;
    Interrupt::_pointer.base  = (Type::u32) &Interrupt::_entries;

    Memory::set(Interrupt::_entries, 0, sizeof(Interrupt::Entry) * 256);

    Interrupt::set(0,  (Type::u32) ISR(0),  0x08, 0x8E);
    Interrupt::set(1,  (Type::u32) ISR(1),  0x08, 0x8E);
    Interrupt::set(2,  (Type::u32) ISR(2),  0x08, 0x8E);
    Interrupt::set(3,  (Type::u32) ISR(3),  0x08, 0x8E);
    Interrupt::set(4,  (Type::u32) ISR(4),  0x08, 0x8E);
    Interrupt::set(5,  (Type::u32) ISR(5),  0x08, 0x8E);
    Interrupt::set(6,  (Type::u32) ISR(6),  0x08, 0x8E);
    Interrupt::set(7,  (Type::u32) ISR(7),  0x08, 0x8E);
    Interrupt::set(8,  (Type::u32) ISR(8),  0x08, 0x8E);
    Interrupt::set(9,  (Type::u32) ISR(9),  0x08, 0x8E);
    Interrupt::set(10, (Type::u32) ISR(10), 0x08, 0x8E);
    Interrupt::set(11, (Type::u32) ISR(11), 0x08, 0x8E);
    Interrupt::set(12, (Type::u32) ISR(12), 0x08, 0x8E);
    Interrupt::set(13, (Type::u32) ISR(13), 0x08, 0x8E);
    Interrupt::set(14, (Type::u32) ISR(14), 0x08, 0x8E);
    Interrupt::set(15, (Type::u32) ISR(15), 0x08, 0x8E);
    Interrupt::set(16, (Type::u32) ISR(16), 0x08, 0x8E);
    Interrupt::set(17, (Type::u32) ISR(17), 0x08, 0x8E);
    Interrupt::set(18, (Type::u32) ISR(18), 0x08, 0x8E);
    Interrupt::set(19, (Type::u32) ISR(19), 0x08, 0x8E);
    Interrupt::set(20, (Type::u32) ISR(20), 0x08, 0x8E);
    Interrupt::set(21, (Type::u32) ISR(21), 0x08, 0x8E);
    Interrupt::set(22, (Type::u32) ISR(22), 0x08, 0x8E);
    Interrupt::set(23, (Type::u32) ISR(23), 0x08, 0x8E);
    Interrupt::set(24, (Type::u32) ISR(24), 0x08, 0x8E);
    Interrupt::set(25, (Type::u32) ISR(25), 0x08, 0x8E);
    Interrupt::set(26, (Type::u32) ISR(26), 0x08, 0x8E);
    Interrupt::set(27, (Type::u32) ISR(27), 0x08, 0x8E);
    Interrupt::set(28, (Type::u32) ISR(28), 0x08, 0x8E);
    Interrupt::set(29, (Type::u32) ISR(29), 0x08, 0x8E);
    Interrupt::set(30, (Type::u32) ISR(30), 0x08, 0x8E);
    Interrupt::set(31, (Type::u32) ISR(31), 0x08, 0x8E);

    Interrupt::set(66, (Type::u32) ISR(66), 0x08, 0x8E);

    // Remap the IRQ table
    Misc::out(0x20, (Type::u8) 0x11);
    Misc::out(0xA0, (Type::u8) 0x11);
    Misc::out(0x21, (Type::u8) 0x20);
    Misc::out(0xA1, (Type::u8) 0x28);
    Misc::out(0x21, (Type::u8) 0x04);
    Misc::out(0xA1, (Type::u8) 0x02);
    Misc::out(0x21, (Type::u8) 0x01);
    Misc::out(0xA1, (Type::u8) 0x01);
    Misc::out(0x21, (Type::u8) 0x00);
    Misc::out(0xA1, (Type::u8) 0x00);

    Interrupt::set(32, (Type::u32) IRQ(0),  0x08, 0x8E);
    Interrupt::set(33, (Type::u32) IRQ(1),  0x08, 0x8E);
    Interrupt::set(34, (Type::u32) IRQ(2),  0x08, 0x8E);
    Interrupt::set(35, (Type::u32) IRQ(3),  0x08, 0x8E);
    Interrupt::set(36, (Type::u32) IRQ(4),  0x08, 0x8E);
    Interrupt::set(37, (Type::u32) IRQ(5),  0x08, 0x8E);
    Interrupt::set(38, (Type::u32) IRQ(6),  0x08, 0x8E);
    Interrupt::set(39, (Type::u32) IRQ(7),  0x08, 0x8E);
    Interrupt::set(40, (Type::u32) IRQ(8),  0x08, 0x8E);
    Interrupt::set(41, (Type::u32) IRQ(9),  0x08, 0x8E);
    Interrupt::set(42, (Type::u32) IRQ(10), 0x08, 0x8E);
    Interrupt::set(43, (Type::u32) IRQ(11), 0x08, 0x8E);
    Interrupt::set(44, (Type::u32) IRQ(12), 0x08, 0x8E);
    Interrupt::set(45, (Type::u32) IRQ(13), 0x08, 0x8E);
    Interrupt::set(46, (Type::u32) IRQ(14), 0x08, 0x8E);
    Interrupt::set(47, (Type::u32) IRQ(15), 0x08, 0x8E);

    Interrupt::flush();
}

void
Interrupt::set (Type::u8 index, Type::u32 base, Type::u16 segmentSelector, Type::u8 flags)
{
    Interrupt::_entries[index].baseLow  = base & 0xFFFF;
    Interrupt::_entries[index].baseHigh = (base >> 16) & 0xFFFF;
    
    Interrupt::_entries[index].segmentSelector = segmentSelector;
    Interrupt::_entries[index].always0         = 0;
    
    // We must uncomment the OR below when we get to using user-mode.
    // It sets the interrupt gate's privilege level to 3.
    Interrupt::_entries[index].flags = flags /* | 0x60 */;
}

void
Interrupt::flush (void)
{
    ::__idt_flush((Type::u32) &Interrupt::_pointer);
}

}

}

