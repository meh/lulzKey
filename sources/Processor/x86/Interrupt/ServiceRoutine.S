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

.macro ISRErrorCode number
.global __isr\number
.type __isr\number, @function
__isr\number:
    cli
    push $\number
    jmp ISRCommonStub
.endm

.macro ISRNoErrorCode number
.global __isr\number
.type __isr\number, @function
__isr\number:
    cli
    push $0
    push $\number
    jmp  ISRCommonStub
.endm

ISRNoErrorCode 0
ISRNoErrorCode 1
ISRNoErrorCode 2
ISRNoErrorCode 3
ISRNoErrorCode 4
ISRNoErrorCode 5
ISRNoErrorCode 6
ISRNoErrorCode 7
ISRErrorCode   8
ISRNoErrorCode 9
ISRErrorCode   10
ISRErrorCode   11
ISRErrorCode   12
ISRErrorCode   13
ISRErrorCode   14
ISRNoErrorCode 15
ISRNoErrorCode 16
ISRNoErrorCode 17
ISRNoErrorCode 18
ISRNoErrorCode 19
ISRNoErrorCode 20
ISRNoErrorCode 21
ISRNoErrorCode 22
ISRNoErrorCode 23
ISRNoErrorCode 24
ISRNoErrorCode 25
ISRNoErrorCode 26
ISRNoErrorCode 27
ISRNoErrorCode 28
ISRNoErrorCode 29
ISRNoErrorCode 30
ISRNoErrorCode 31

/* To 32-47 is IRQ handling */

ISRNoErrorCode 66

ISRCommonStub:
    pusha
    
    # Save the ring level
    movl $0, %eax
    movw %cs, %ax
    andl $3, %eax
    push %eax

    # Save the data segment
    movl $0, %eax
    movw %ds, %ax
    push %eax
    
    # load the kernel data segment descriptor
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    
    call __Interrupt_ISR_Handler
   
    # reload the original data segment descriptor
    pop %eax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    # Pop the ring level
    add $4, %esp
    
    popa
    add $8, %esp # Cleans up the pushed error code and pushed ISR number
    sti
    iret         # pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP

