#include <DescriptorTables/DescriptorTables.h>

namespace Kernel {

namespace DescriptorTables {

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

