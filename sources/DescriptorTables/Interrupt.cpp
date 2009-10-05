#include <DescriptorTables/Interrupt.h>
#include <Memory/Memory.h>

namespace Kernel {

namespace DescriptorTables {

Interrupt::Interrupt (void)
{
    _pointer.limit = (sizeof(Interrupt::Entry) * 256) - 1;
    _pointer.base  = (Type::u32) &_entries;

    Memory::set(_entries, 0, sizeof(Interrupt::Entry) * 256);

    this->flush();
}

void
Interrupt::set (Type::u8 index, Type::u32 base, Type::u16 segmentSelector, Type::u8 flags)
{
    _entries[index].baseLow  = base & 0xFFFF;
    _entries[index].baseHigh = (base >> 16) & 0xFFFF;
    
    _entries[index].segmentSelector = segmentSelector;
    _entries[index].always0         = 0;
    
    // We must uncomment the OR below when we get to using user-mode.
    // It sets the interrupt gate's privilege level to 3.
    _entries[index].flags = flags /* | 0x60 */;
}

void
Interrupt::flush (void)
{
    /* Load the Interrupt Descriptor Table. */
    asm volatile ("movl %0, %%eax" :: "r" (&_pointer) : "%eax");
    asm volatile ("lidt (%eax)");
}

}

}

