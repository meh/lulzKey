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
    Type::u32 ds;   /*<< data segment selector */
    Type::u32 ring; /*<< ring level */
    
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
