/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

.global __idt_flush
.type __idt_flush, @function

__idt_flush:
    mov  4(%esp), %eax # Get the pointer to the idt, passed as a parameter.
    lidt (%eax)        # Load the new idt pointer
    ret

