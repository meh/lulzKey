#ifndef _LKEY_DESCRIPTORTABLES_H
#define _LKEY_DESCRIPTORTABLES_H

#include <DescriptorTables/Global.h>
#include <DescriptorTables/Interrupt.h>

namespace Kernel {

namespace DescriptorTables {

Global*    GDT;
Interrupt* IDT;

void init (void);

}

}

#endif
