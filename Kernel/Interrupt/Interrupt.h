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

#ifndef _LKEY_INTERRUPT_H
#define _LKEY_INTERRUPT_H

#include <Type.h>

#include <Processor/Processor.h>

namespace Kernel {

class Interrupt
{
  protected:
    Interrupt (void) {}

  public:
    typedef Processor::InterruptRegisters Registers;

    enum Type {
        ServiceRoutine,
        Request
    };

    typedef void (*Handler)(Registers&);

  public:
    static void handle (Type type, Registers& registers);

    static void define (Type::u8 number, Handler handler);

  private:
    static Handler _handlers[256];
};

}

#endif
