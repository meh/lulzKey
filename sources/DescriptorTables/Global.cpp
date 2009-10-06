#include <DescriptorTables/Global.h>

extern "C" void __gdt_flush (Type::u32 address);

namespace Kernel {

namespace DescriptorTables {

Global::Global (void)
{
    _pointer.limit = (sizeof(Global::Entry) * 7) - 1;
    _pointer.base  = (Type::u32) &_entries;

    this->set(0, 0, 0, 0, 0);                // Null segment
    this->set(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    this->set(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    this->set(3, 0, 0xFFFFFFFF, 0xBA, 0xCF); // Service code segment
    this->set(4, 0, 0xFFFFFFFF, 0xBA, 0xCF); // Service data segment
    this->set(5, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    this->set(6, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    this->flush();
}

void
Global::set (Type::s32 index, Type::u32 base, Type::u32 limit, Type::u8 access, Type::u8 granularity)
{
    _entries[index].baseLow    = (base & 0xFFFF);
    _entries[index].baseMiddle = (base >> 16) & 0xFF;
    _entries[index].baseHigh   = (base >> 24) & 0xFF;
    
    _entries[index].limitLow    = (limit & 0xFFFF);
    _entries[index].granularity = (limit >> 16) & 0x0F;
    
    _entries[index].granularity |= granularity & 0xF0;
    _entries[index].access       = access;
}

void
Global::flush (void)
{
    ::__gdt_flush((Type::u32) &_pointer);
}

}

}

