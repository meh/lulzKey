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

