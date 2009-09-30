.data ALIGN (0x1000) : {
    start_ctors = .;
    *(.ctor*)
    end_ctors = .;
    start_dtors = .;
    *(.dtor*)
    end_dtors = .;
    *(.data)
}

.text 0x100000 {
    *(.text)
    *(.rodata*)
}

ENTRY(loader)
