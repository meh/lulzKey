/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Interrupt/Interrupt.h>
#include <Misc/IO.h>

namespace Kernel {

Interrupt::Handler Interrupt::_handlers[256] = {0};

void
system (Interrupt::Registers& regs)
{
    if (regs.ring == 1) {

    }
}

void
Interrupt::init (void)
{
    Interrupt::define(0x42, &system);
}

void
Interrupt::handle (Interrupt::Type type, Interrupt::Registers& registers)
{
    if (type == ServiceRoutine) {
        if (_handlers[registers.number]) {
            _handlers[registers.number](registers);
        }
    }
    else {
        if (registers.number >= 40) {
            Misc::out(0xA0, (Type::u8) 0x20);
        }

        Misc::out(0x20, (Type::u8) 0x20);

        if (_handlers[registers.number]) {
            _handlers[registers.number](registers);
        }
    }
}

void
Interrupt::define (Type::u8 number, Interrupt::Handler handler)
{
    _handlers[number] = handler;
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


