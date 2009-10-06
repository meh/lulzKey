#include <Interrupt/Interrupt.h>
#include <Tools/Shell/Shell.h>

namespace Kernel {

void
Interrupt::Handler (Interrupt::Registers registers)
{
    Shell shell;
    shell << registers.number << Shell::endLine;
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

