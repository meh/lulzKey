/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Processor/x86/DescriptorTables/Global.h>

extern "C" void __gdt_flush (Type::u32 address);

namespace Kernel {

namespace Processor {

namespace DescriptorTables {

Global::Entry   Global::_entries[9];
Global::Pointer Global::_pointer;

void
Global::init (void)
{
    Global::_pointer.limit = (sizeof(Global::Entry) * 9) - 1;
    Global::_pointer.base  = (Type::u32) &Global::_entries;

    Global::set(0, 0, 0, 0, 0);                // Null segment              @ 0x00
    Global::set(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment              @ 0x08
    Global::set(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment              @ 0x10
    Global::set(3, 0, 0xFFFFFFFF, 0xBA, 0xCF); // Core service code segment @ 0x18
    Global::set(4, 0, 0xFFFFFFFF, 0xB2, 0xCF); // Core service data segment @ 0x20
    Global::set(5, 0, 0xFFFFFFFF, 0xDA, 0xCF); // Service code segment      @ 0x28
    Global::set(6, 0, 0xFFFFFFFF, 0xD2, 0xCF); // Service data segment      @ 0x30
    Global::set(7, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment    @ 0x38
    Global::set(8, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment    @ 0x40

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

}

