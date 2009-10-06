#include <DescriptorTables/Global.h>

extern void __gdt_flush (Type::u32 address);

namespace Kernel {

namespace DescriptorTables {

Global::Global (void)
{
    _pointer.limit = (sizeof(Global::Entry) * 5) - 1;
    _pointer.base  = (Type::u32) &_entries;

    this->set(0, 0, 0, 0, 0);

    this->flush();
}

void
Global::set (Type::s32 index, Type::u32 base, Type::u32 limit, Type::u8 access, Type::u8 granularity)
{
    _entries[index].baseLow    = (base & 0xFFFF);
    _entries[index].baseMiddle = (base >> 16) & 0xFF;
    _entries[index].baseHigh   = (base >> 24) & 0xFF;
    
    _entries[index].limitLow   = (limit & 0xFFFF);
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

