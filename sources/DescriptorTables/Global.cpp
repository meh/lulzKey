#include <DescriptorTables/Global.h>

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
    /**
     * Load the Global Descriptor Table.
     */
    asm volatile ("movl %0, %%eax" :: "r" (&_pointer) : "%eax");
    asm volatile ("lgdt (%eax)");

    asm volatile ("mov %ax, 0x10");

    /* Load all data segment selectors */
    asm volatile ("mov %ds, %ax");
    asm volatile ("mov %es, %ax");
    asm volatile ("mov %fs, %ax");
    asm volatile ("mov %gs, %ax");
    asm volatile ("mov %ss, %ax");
    asm volatile ("jmp 0x08");
}

}

}

