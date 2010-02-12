/****************************************************************************
* lulzKey. Let's close those effin Windows so penguins won't enter.         *
*                                                                           *
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* lulzKey is free software: you can redistribute it and/or modify           *
* it under the terms of the GNU Affero General Public License as published  *
* by the Free Software Foundation, either version 3 of the License, or      *
* (at your option) any later version.                                       *
*                                                                           *
* lulzKey is distributed in the hope that it will be useful,                *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with lulzKey.  If not, see <http://www.gnu.org/licenses/>.          *
****************************************************************************/

#include <Interrupt/Interrupt.h>
#include <Misc/IO.h>

namespace Kernel {

Interrupt::Handler Interrupt::_handlers[256] = {0};

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


