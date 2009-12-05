/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
