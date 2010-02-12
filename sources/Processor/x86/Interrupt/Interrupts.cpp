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

