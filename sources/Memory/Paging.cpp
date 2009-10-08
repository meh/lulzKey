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

#include <Memory/Memory.h>
#include <Interrupt/Interrupt.h>

#include <Tools/Shell/Shell.h>

#define INDEX_FROM_BIT(x)  (x / (8 * 4))
#define OFFSET_FROM_BIT(x) (x % (8 * 4))

namespace Kernel {

Memory::Paging::Directory* Memory::Paging::_kernel  = NULL;
Memory::Paging::Directory* Memory::Paging::_current = NULL;

void
Memory::Paging::init (Type::u32 upperMemory)
{
    Memory::Paging::Frame::frameNumber = (upperMemory * 1024) / 0x1000;
    Memory::Paging::Frame::frames      = (Type::u32*) Memory::alloc(INDEX_FROM_BIT(Memory::Paging::Frame::frameNumber));
    Memory::set(Memory::Paging::Frame::frames, 0, INDEX_FROM_BIT(Memory::Paging::Frame::frameNumber));

    Memory::Paging::_kernel  = (Memory::Paging::Directory*) Memory::alloc(sizeof(Memory::Paging::Directory));
    Memory::Paging::_current = Memory::Paging::_kernel;

    for (Type::u32 i = 0; i < Memory::_address; i += 0x1000) {
        Memory::Paging::Frame::alloc(Memory::Paging::getPage(Memory::Paging::_kernel, i, true), false, false);
    }

    Interrupt::define(14, &Memory::Paging::fault);

    Memory::Paging::switchPage(Memory::Paging::_kernel);
}

void
Memory::Paging::switchPage (Memory::Paging::Directory* directory)
{
    Memory::Paging::_current = directory;

    asm volatile("movl %0, %%cr3" :: "r" (&directory->tablesPhysical));

    // Enable paging
    asm volatile("movl %%cr0, %%eax" ::: "eax");
    asm volatile("orl $0x80000000, %%eax" ::: "eax");
    asm volatile("movl %eax, %cr0");
}

Memory::Paging::Page*
Memory::Paging::getPage (Memory::Paging::Directory* directory, Type::u32 address, bool make)
{
    address /= 0x1000;

    Type::u32 index = address / 1024;
    if (directory->tables[index]) {
        return &directory->tables[index]->pages[address % 1024];
    }
    else if (make) {
        Type::u32 tmp = 0;
        directory->tables[index] = (Memory::Paging::Table*) Memory::alloc(sizeof(Memory::Paging::Table), (void**) &tmp);
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
Memory::Paging::fault (Interrupt::Registers& registers)
{
    Shell shell;

    shell << registers.errorCode << Shell::endLine;
}

}

