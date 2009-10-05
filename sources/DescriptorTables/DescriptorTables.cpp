#include <DescriptorTables/DescriptorTables.h>

namespace Kernel {

namespace DescriptorTables {

Global*    GDT;
Interrupt* IDT;

void
init (void)
{
    Global gdt;
    GDT = &gdt;

    Interrupt idt;
    IDT = &idt;
}

}

}

