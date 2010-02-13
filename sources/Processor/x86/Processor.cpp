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

#ifndef _ARCH_X86
#   error "Why is this compiling? :)"
#endif

#include <Kernel.h>

#include <Processor/Processor.h>
#include <Processor/x86/DescriptorTables/DescriptorTables.h>
#include <Processor/x86/Interrupt/Interrupts.h>
#include <Processor/x86/Memory/Memory.h>
#include <Processor/x86/Memory/Paging.h>

namespace Kernel {

namespace Processor {

extern "C" int __end;

void
init (Multiboot& boot)
{
    DescriptorTables::init();
    Interrupts::init();

    Memory::address = (Type::u32) &__end; // boot.end();
    Memory::Paging::init(boot.memory()->upper);
}

}

}
