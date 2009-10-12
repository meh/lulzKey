/****************************************************************************
 * lulzKey. Let's close those effin Windows so penguins won't enter.        *
 *                                                                          *
 * Copyright (C) 2009  meh. [http://meh.doesntexist.org]                    *
 *                                                                          *
 * This program is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 ****************************************************************************/

#include <Kernel.h>
#include <Processor/x86/Memory/Memory.h>
#include <Processor/x86/Memory/Paging.h>
#include <Processor/x86/Memory/Frame.h>
#include <Interrupt/Interrupt.h>

#define INDEX_FROM_BIT(x)  (x / (8 * 4))
#define OFFSET_FROM_BIT(x) (x % (8 * 4))

namespace Kernel {

namespace Processor {

namespace Memory {

namespace Paging {

Directory* _kernel  = NULL;
Directory* _current = NULL;

void
init (Type::u32 upperMemory)
{
    Frame::frameNumber = (upperMemory * 1024) / 0x1000;
    Frame::frames      = (Type::u32*) Memory::alloc(INDEX_FROM_BIT(Frame::frameNumber));
    Memory::set(Frame::frames, 0, INDEX_FROM_BIT(Frame::frameNumber));

    _kernel = (Directory*) Memory::alloc(sizeof(Directory), true);
    Memory::set(_kernel, 0, sizeof(Directory));

    _current = _kernel;

    Type::u32 i = 0;
    while (i < Memory::_address) {
        Frame::alloc(Paging::getPage(_kernel, i, true), false, false);
        i += 0x1000;
    }

    Interrupt::define(14, &Paging::fault);

    Paging::switchPage(Paging::_kernel);
}

void
switchPage (Directory* directory)
{
    _current = directory;

    asm volatile("movl %0, %%cr3" :: "r" (&directory->tablesPhysical));

    // Enable paging
    asm volatile("movl %%cr0, %%eax" ::: "eax");
    asm volatile("orl $0x80000000, %%eax" ::: "eax");
    asm volatile("movl %%eax, %%cr0" ::: "eax");
}

Page*
getPage (Directory* directory, Type::u32 address, bool make)
{
    address /= 0x1000;

    Type::u32 index = address / 1024;
    if (directory->tables[index]) {
        return &directory->tables[index]->pages[address % 1024];
    }
    else if (make) {
        Type::u32 tmp = 0;

        directory->tables[index] = (Table*) Memory::alloc(sizeof(Table), (void*) &tmp, true);
        Memory::set(directory->tables[index], 0, 0x1000);

        directory->tablesPhysical[index] = tmp | 0x7;

        return &directory->tables[index]->pages[address % 1024];
    }
    else {
        return NULL;
    }
}

#define PAGE_NOT_PRESENT(flags)   (!CHECK_FLAG(flags, 0))
#define WRITE_FAULT(flags)        ( CHECK_FLAG(flags, 1))
#define READ_FAULT(flags)         (!CHECK_FLAG(flags, 1))
#define IN_KERNEL(flags)          (!CHECK_FLAG(flags, 2))
#define IN_USERMODE(flags)        ( CHECK_FLAG(flags, 2))
#define REWRITTEN_RESERVED(flags) ( CHECK_FLAG(flags, 3))
#define INSTRUCTION_FETCH(flags)  ( CHECK_FLAG(flags, 4))

void
fault (Interrupt::Registers& registers)
{
    Kernel::panic("OMG PAGEFAULT!1!");
}

}

}

}

}

