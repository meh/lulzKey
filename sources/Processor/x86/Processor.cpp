/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_X86
#   error "Why is this compiling? :)"
#endif

#include <Kernel.h>

#include <Processor/Processor.h>
#include <Processor/x86/DescriptorTables/DescriptorTables.h>
#include <Processor/x86/Memory/Memory.h>
#include <Processor/x86/Memory/Paging.h>

#include <Interrupt/Interrupt.h>

namespace Kernel {

namespace Processor {

extern "C" int __end;

void
init (Multiboot& boot)
{
    DescriptorTables::init();

    Memory::address = (Type::u32) &__end; // boot.end();
    Memory::Paging::init(boot.memory()->upper);
}

}

}
