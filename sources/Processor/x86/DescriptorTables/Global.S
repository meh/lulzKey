/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

.global __gdt_flush
.type __gdt_flush, @function

__gdt_flush:
    mov  4(%esp), %eax # Get the pointer to the GDT, passed as a parameter.
    lgdt (%eax)        # Load the new GDT pointer

    mov $0x10, %ax     # 0x10 is the offset in the GDT to our data segment

    mov %ax, %ds       # Load all data segment selectors
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss

    jmp $0x08, $_flush # 0x08 is the offset to our code segment: Far jump!
    
_flush:
    ret

