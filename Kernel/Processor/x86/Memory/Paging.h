/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_PROCESSOR_X86_MEMORY_PAGING_H
#define _LKEY_PROCESSOR_X86_MEMORY_PAGING_H

#include <Interrupt/Interrupt.h>

namespace Kernel {

namespace Processor {

namespace Memory {

namespace Paging {

struct Page {
    Type::u32 present      : 1;  /*<< page present in memory */
    Type::u32 readWrite    : 1;  /*<< read-only if clear, readwrite if set */
    Type::u32 userMode     : 1;  /*<< supervisor level only if clear */
    Type::u32 writeThrough : 1;  /*<< controls whether write-through caching is enabled (set to 0 for write-back caching) */
    Type::u32 disableCache : 1;  /*<< caching is disabled if set */
    Type::u32 accessed     : 1;  /*<< has the page been accessed since last refresh? */
    Type::u32 dirty        : 1;  /*<< has the page been written to since last refresh? */
    Type::u32 size         : 1;  /*<< size of the page, if unset it's 4 kB */
    Type::u32 global       : 1;  /*<< is this page global (can be used to prevent flushing when i.e. task-switching occurs) */
    Type::u32              : 3;  /*<< unused */
    Type::u32 frame        : 20; /*<< frame address (shifted right 12 bits) */
};

struct Table {
    Page pages[1024];
};

struct Directory {
    Table*    tables[1024];         /*<< array of pointers to Tables */
    Type::u32 tablesPhysical[1024]; /*<< array of physical pointers to those tables, to be passed to CR3 */
    Type::u32 physicalAddress;      /*<< physical address of tablesPhysical */
};

extern Directory* _kernel;
extern Directory* _current;

void init (Type::u32 upperMemory);

void switchPage (Directory* directory);

Page* getPage (Directory* directory, Type::u32 address, bool make);

void fault (Interrupt::Registers& registers);

}

}

}

}

#endif
