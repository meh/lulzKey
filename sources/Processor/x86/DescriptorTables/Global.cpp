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

#include <DescriptorTables/Global.h>

extern "C" void __gdt_flush (Type::u32 address);

namespace Kernel {

namespace DescriptorTables {

Global::Entry   Global::_entries[7];
Global::Pointer Global::_pointer;

void
Global::init (void)
{
    Global::_pointer.limit = (sizeof(Global::Entry) * 7) - 1;
    Global::_pointer.base  = (Type::u32) &Global::_entries;

    Global::set(0, 0, 0, 0, 0);                // Null segment
    Global::set(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    Global::set(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    Global::set(3, 0, 0xFFFFFFFF, 0xBA, 0xCF); // Service code segment
    Global::set(4, 0, 0xFFFFFFFF, 0xBA, 0xCF); // Service data segment
    Global::set(5, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    Global::set(6, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    Global::flush();
}

void
Global::set (Type::s32 index, Type::u32 base, Type::u32 limit, Type::u8 access, Type::u8 granularity)
{
    Global::_entries[index].baseLow    = (base & 0xFFFF);
    Global::_entries[index].baseMiddle = (base >> 16) & 0xFF;
    Global::_entries[index].baseHigh   = (base >> 24) & 0xFF;
    
    Global::_entries[index].limitLow    = (limit & 0xFFFF);
    Global::_entries[index].granularity = (limit >> 16) & 0x0F;
    
    Global::_entries[index].granularity |= granularity & 0xF0;
    Global::_entries[index].access       = access;
}

void
Global::flush (void)
{
    ::__gdt_flush((Type::u32) &Global::_pointer);
}

}

}

