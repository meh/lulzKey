/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Kernel.h>
#include <Memory/Memory.h>

#include <Processor/x86/DescriptorTables/Global.h>

extern "C" void __gdt_flush (Type::u32 address);

namespace Kernel {

namespace Processor {

namespace DescriptorTables {

Global::Entry   Global::_entries[8];
Global::Pointer Global::_pointer;
Global::TSS     Global::_tss;

void
Global::init (void)
{
    Global::_pointer.limit = (sizeof(Global::Entry) * 8) - 1;
    Global::_pointer.base  = (Type::u32) &Global::_entries;

    Global::set(0, 0, 0, 0, 0);                // Null segment              @ 0x00
    Global::set(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Kernel code segment       @ 0x08
    Global::set(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Kernel data segment       @ 0x10
    Global::set(3, 0, 0xFFFFFFFF, 0xBA, 0xCF); // God service code segment  @ 0x18
    Global::set(4, 0, 0xFFFFFFFF, 0xB2, 0xCF); // God service data segment  @ 0x20
    Global::set(5, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment    @ 0x28
    Global::set(6, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment    @ 0x30

    Global::_initTSS(7, 0x10, 0x0); // @ 0x38

    Global::flush();
    Global::_flushTSS();
}

void
Global::_initTSS (Type::u32 index, Type::u16 ss0, Type::u32 esp0)
{
    Type::u32 base  = (Type::u32) &Global::_tss;
    Type::u32 limit = base + sizeof(Global::TSS);

    Global::set(index, base, limit, 0xE9, 0x00);
    Memory::set(&Global::_tss, 0, sizeof(Global::TSS));

    Global::_tss.ss0  = ss0;  // set the kernel stack segment
    Global::_tss.esp0 = esp0; // set the kernel stack pointer
    Global::_tss.cs   = (0x08 | USER_LEVEL);
    Global::_tss.ss   =
    Global::_tss.ds   =
    Global::_tss.es   =
    Global::_tss.fs   =
    Global::_tss.gs   = (0x10 | USER_LEVEL);
}

void
Global::_flushTSS (bool service)
{
    if (service) {
        asm volatile ("movw $(0x38 | 1), %dx");
    }
    else {
        asm volatile ("movw $(0x38 | 3), %dx");
    }

    asm volatile ("ltr %dx");
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

