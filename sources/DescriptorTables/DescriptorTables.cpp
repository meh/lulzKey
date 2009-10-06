#include <DescriptorTables/DescriptorTables.h>

namespace Kernel {

namespace DescriptorTables {

Global*    GDT = 0;
Interrupt* IDT = 0;

void
init (void)
{
    if (!GDT && !IDT) {
        Global gdt;
        GDT = &gdt;

        Interrupt idt;
        IDT = &idt;
    }
}

}

}

