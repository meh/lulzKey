#include <DescriptorTables/Interrupt.h>
#include <Interrupt/ServiceRoutine.h>
#include <Memory/Memory.h>

namespace Kernel {

namespace DescriptorTables {

Interrupt::Interrupt (void)
{
    _pointer.limit = (sizeof(Interrupt::Entry) * 256) - 1;
    _pointer.base  = (Type::u32) &_entries;

    Memory::set(_entries, 0, sizeof(Interrupt::Entry) * 256);

#if 0
    this->set(0,  (Type::u32) __ISR(0),  0x08, 0x8E);
    this->set(1,  (Type::u32) __ISR(1),  0x08, 0x8E);
    this->set(2,  (Type::u32) __ISR(2),  0x08, 0x8E);
    this->set(3,  (Type::u32) __ISR(3),  0x08, 0x8E);
    this->set(4,  (Type::u32) __ISR(4),  0x08, 0x8E);
    this->set(5,  (Type::u32) __ISR(5),  0x08, 0x8E);
    this->set(6,  (Type::u32) __ISR(6),  0x08, 0x8E);
    this->set(7,  (Type::u32) __ISR(7),  0x08, 0x8E);
    this->set(8,  (Type::u32) __ISR(8),  0x08, 0x8E);
    this->set(9,  (Type::u32) __ISR(9),  0x08, 0x8E);
    this->set(10, (Type::u32) __ISR(10), 0x08, 0x8E);
    this->set(11, (Type::u32) __ISR(11), 0x08, 0x8E);
    this->set(12, (Type::u32) __ISR(12), 0x08, 0x8E);
    this->set(13, (Type::u32) __ISR(13), 0x08, 0x8E);
    this->set(14, (Type::u32) __ISR(14), 0x08, 0x8E);
    this->set(15, (Type::u32) __ISR(15), 0x08, 0x8E);
    this->set(16, (Type::u32) __ISR(16), 0x08, 0x8E);
    this->set(17, (Type::u32) __ISR(17), 0x08, 0x8E);
    this->set(18, (Type::u32) __ISR(18), 0x08, 0x8E);
    this->set(19, (Type::u32) __ISR(19), 0x08, 0x8E);
    this->set(20, (Type::u32) __ISR(20), 0x08, 0x8E);
    this->set(21, (Type::u32) __ISR(21), 0x08, 0x8E);
    this->set(22, (Type::u32) __ISR(22), 0x08, 0x8E);
    this->set(23, (Type::u32) __ISR(23), 0x08, 0x8E);
    this->set(24, (Type::u32) __ISR(24), 0x08, 0x8E);
    this->set(25, (Type::u32) __ISR(25), 0x08, 0x8E);
    this->set(26, (Type::u32) __ISR(26), 0x08, 0x8E);
    this->set(27, (Type::u32) __ISR(27), 0x08, 0x8E);
    this->set(28, (Type::u32) __ISR(28), 0x08, 0x8E);
    this->set(29, (Type::u32) __ISR(29), 0x08, 0x8E);
    this->set(30, (Type::u32) __ISR(30), 0x08, 0x8E);
    this->set(31, (Type::u32) __ISR(31), 0x08, 0x8E);
#endif

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

