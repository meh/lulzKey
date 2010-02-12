/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

.macro IRQ number, ISR
.global __irq\number
.type __irq\number, @function
__irq\number:
    cli
    push $0
    push $\ISR
    jmp IRQCommonStub
.endm

IRQ 0,  32
IRQ 1,  33
IRQ 2,  34
IRQ 3,  35
IRQ 4,  36
IRQ 5,  37
IRQ 6,  38
IRQ 7,  39
IRQ 8,  40
IRQ 9,  41
IRQ 10, 42
IRQ 11, 43
IRQ 12, 44
IRQ 13, 45
IRQ 14, 46
IRQ 15, 47

IRQCommonStub:
    pusha
    
    mov  %ds, %ax     # Lower 16-bits of eax = ds.
    push %eax         # save the data segment descriptor
    
    mov  $0x10, %ax   # load the kernel data segment descriptor
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    
    call __Interrupt_IRQ_Handler
    
    pop %eax         # reload the original data segment descriptor
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    
    popa
    add $8, %esp     # Cleans up the pushed error code and pushed ISR number
    sti
    iret             # pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP

