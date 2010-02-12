/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Processor/x86/Interrupt/Interrupts.h>
#include <Processor/x86/Memory/Paging.h>

namespace Kernel {

namespace Processor {

namespace Interrupts {

void
init (void)
{
    Interrupt::define(0x42, &system);
}

void
system (Interrupt::Registers& regs)
{
    if (regs.ring <= 1) {
        switch (regs.eax) {
            case 1: // disable paging
            asm volatile (
                "mov %%cr0, %%edx \n"
                "and $0x7fffffff, %%edx \n"
                "mov %%edx, %%cr0 \n"
            ::: "edx");
            break;

            case 2: // enable paging
            asm volatile (
                "movl %%cr0, %%edx \n"
                "orl $0x80000000, %%edx \n"
                "movl %%edx, %%cr0 \n"
            ::: "edx");
            break;

            case 3: // set paging directory to ebx
            asm volatile (
                "movl %0, %%cr3 \n" :: "r" (((Memory::Paging::Directory*) regs.ebx)->tablesPhysical)
            );
            break;

            case 4: // flush TLB
            asm volatile (
                "mov %%cr3, %%edx \n"
                "mov %%edx, %%cr3 \n"
            ::: "edx");
        }
    }
}

}

}

}

