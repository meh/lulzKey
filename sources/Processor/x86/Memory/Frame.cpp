/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Kernel.h>
#include <Processor/x86/Memory/Frame.h>

#define INDEX_FROM_BIT(x)  (x / (8 * 4))
#define OFFSET_FROM_BIT(x) (x % (8 * 4))

namespace Kernel {

namespace Processor {

namespace Memory {

namespace Frame {

Type::u32* frames      = 0;
Type::u32  frameNumber = 0;

void
alloc (Paging::Page* page, bool isKernel, bool isWriteable)
{
    if (page->frame != 0) {
        return;
    }

    Type::u32 index = Frame::findFirst();

    // No more pages, we're fucked lol
    if (index == (Type::u32) -1) {
        Kernel::panic("OH GOD WHERE ARE ALL MY MEMORIES?!?!?!?");
    }

    Frame::set(index * 0x1000);
    page->present   = true;
    page->readWrite = isWriteable;
    page->userMode  = !isKernel;
    page->frame     = index;
}

void
free (Paging::Page* page)
{
    Type::u32 frame;

    // No allocated frame, you're just an idiot eh?
    if (!(frame = page->frame)) {
        return;
    }

    Frame::clear(frame);
    page->frame = NULL;
}

void
set (Type::u32 address)
{
    Type::u32 frame  = address / 0x1000;
    Type::u32 index  = INDEX_FROM_BIT(frame);
    Type::u32 offset = OFFSET_FROM_BIT(frame);

    frames[index] |= (0x1 << offset);
}

void
clear (Type::u32 address)
{
    
    Type::u32 frame  = address / 0x1000;
    Type::u32 index  = INDEX_FROM_BIT(frame);
    Type::u32 offset = OFFSET_FROM_BIT(frame);

    frames[index] &= ~(0x1 << offset);
}

bool
test (Type::u32 address)
{
    Type::u32 frame  = address / 0x1000;
    Type::u32 index  = INDEX_FROM_BIT(frame);
    Type::u32 offset = OFFSET_FROM_BIT(frame);

    return (frames[index] & (0x1 << offset));
}

Type::u32
findFirst (void)
{
    for (Type::u32 i = 0; i < INDEX_FROM_BIT(frameNumber); i++) {
        if (frames[i] == 0xFFFFFFFF) {
            continue;
        }

        // at least one bit is free
        for (Type::u32 h = 0; h < 32; h++) {
            if (!(frames[i] & (0x1 << h))) {
                return h + (i * 4 * 8);
            }
        }
    }

    return 0;
}

}

}

}

}

