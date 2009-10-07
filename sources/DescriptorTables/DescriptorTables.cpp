#include <DescriptorTables/DescriptorTables.h>

namespace Kernel {

namespace DescriptorTables {

void
init (void)
{
    Global::init();
    Interrupt::init();
}

}

}

