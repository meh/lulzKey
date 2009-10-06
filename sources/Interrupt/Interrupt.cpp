#include <Interrupt/Interrupt.h>

namespace Kernel {

void
Interrupt::Handler (Interrupt::Registers registers)
{
}

Interrupt::Interrupt (Interrupt::Registers registers)
{
    _registers = registers;
}

}

extern "C"
void
__Interrupt_Handler (Kernel::Interrupt::Registers registers)
{
    Kernel::Interrupt::Handler(registers);
}

