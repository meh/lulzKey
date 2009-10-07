#include <Interrupt/Interrupt.h>
#include <Misc/IO.h>

namespace Kernel {

Interrupt::Handler Interrupt::_handlers[256] = {0};

void
Interrupt::handle (Interrupt::Type type, Interrupt::Registers registers)
{
    if (type == Interrupt::ServiceRoutine) {
        if (Interrupt::_handlers[registers.number]) {
            Interrupt::_handlers[registers.number](registers);
        }
    }
    else {
        if (registers.number >= 40) {
            Misc::out(0xA0, (Type::u8) 0x20);
        }

        Misc::out(0x20, (Type::u8) 0x20);

        if (Interrupt::_handlers[registers.number]) {
            Interrupt::_handlers[registers.number](registers);
        }
    }
}

void
Interrupt::define (Type::u8 number, Handler handler)
{
    Interrupt::_handlers[number] = handler;
}

}

using namespace Kernel;

extern "C"
void
__Interrupt_ISR_Handler (Interrupt::Registers registers)
{
    Interrupt::handle(Interrupt::ServiceRoutine, registers);
}

extern "C"
void
__Interrupt_IRQ_Handler (Interrupt::Registers registers)
{
    Interrupt::handle(Interrupt::Request, registers);
}


