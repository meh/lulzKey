.global __idt_flush
.type __idt_flush, @function

__idt_flush:
    mov  4(%esp), %eax # Get the pointer to the idt, passed as a parameter.
    lidt (%eax)        # Load the new idt pointer
    ret

