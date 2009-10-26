/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <string.h>

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
    while (i < Memory::address) {
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
    asm volatile(
        "movl %%cr0, %%eax \n"
        "orl $0x80000000, %%eax \n"
        "movl %%eax, %%cr0"
    ::: "eax");
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
    char error[51]    = {0};
    Type::u32 address = 0;

    asm volatile("mov %%cr2, %0" : "=r" (address));

    if (PAGE_NOT_PRESENT(registers.errorCode)) {
        strcat(error, "!present ");
    }

    if (WRITE_FAULT(registers.errorCode)) {
        strcat(error, "read-only ");
    }

    if (IN_USERMODE(registers.errorCode)) {
        strcat(error, "user-mode ");
    }
    else {
        strcat(error, "kernel-mode ");
    }

    if (REWRITTEN_RESERVED(registers.errorCode)) {
        strcat(error, "reserved ");
    }

    if (INSTRUCTION_FETCH(registers.errorCode)) {
        strcat(error, "executing ");
    }

    Kernel::panic("Pagefault happened, well, you're fucked :(\n\nAddress: 0x%x { %s}", address, error);
}

}

}

}

}

