/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifdef _LKEY_PROCESSOR_H

#include <Boot/Multiboot.h>

namespace Kernel {

namespace Processor {

struct Registers {
    Type::u32 eax;
    Type::u32 ecx;
    Type::u32 edx;
    Type::u32 ebx;

    Type::u32 esp;
    Type::u32 ebp;
    Type::u32 esi;
    Type::u32 edi;

    Type::u32 eflags;
    Type::u32 eip;

    Type::u16 cs;
    Type::u16 ds;
    Type::u16 ss;
    Type::u16 es;
    Type::u16 fs;
    Type::u16 gs;
};

struct InterruptRegisters {
    Type::u32 ring; /*<< ring level */
    Type::u32 ds;   /*<< data segment selector */
    
    // Pushed by pusha.
    Type::u32 edi;
    Type::u32 esi;
    Type::u32 ebp;
    Type::u32 esp;
    Type::u32 ebx;
    Type::u32 edx;
    Type::u32 ecx;
    Type::u32 eax;

    Type::u32 number;    /*<< interrupt number */
    Type::u32 errorCode; /*<< interrupt error code (if applicable) */

    // Pushed by the processor automatically.
    Type::u32 eip;
    Type::u32 cs;
    Type::u32 eflags;
    Type::u32 useresp;
    Type::u32 ss;
};

void init (Multiboot& boot);

}

}

#endif
