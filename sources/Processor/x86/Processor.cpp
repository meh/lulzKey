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

/**
 * System interrupts, only the god service can call them.
 *
 * 1 - disable paging                   { void (void) }
 * 2 - enable paging                    { void (void) }
 * 3 - set paging directory to the ebx  { void (physycal table address) }
 */
void
system (Interrupt::Registers& regs)
{
    if (regs.ring == 1) {
        switch (regs.eax) {
            case 1:
            asm volatile (
                "mov %%cr0, %%eax \n"
                "and $0x7fffffff, %%eax \n"
                "mov %%eax, %%cr0 \n"
            ::: "eax");
            break;

            case 2:
            asm volatile(
                "movl %%cr0, %%eax \n"
                "orl $0x80000000, %%eax \n"
                "movl %%eax, %%cr0 \n"
            ::: "eax");
            break;

            case 3:
            asm volatile(
                "movl %0, %%cr3 \n" :: "r" (regs.ebx)
            );
            break;
        }
    }
}

void
init (Multiboot& boot)
{
    DescriptorTables::init();
    Interrupt::init(&system);

    Memory::address = (Type::u32) &__end; // boot.end();
    Memory::Paging::init(boot.memory()->upper);
}

}

}
