.global loader                 # making entry point visible to linker

# setting up the Multiboot header - see GRUB docs for details
.set ALIGN,    1 << 0           # align loaded modules on page boundaries
.set MEMINFO,  1 << 1           # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum required

.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# reserve initial kernel stack space
.set STACKSIZE, 0x4000          # that is, 16k.
.comm stack, STACKSIZE, 32      # reserve 16k stack on a quadword boundary

loader:
   mov  $(stack + STACKSIZE), %esp # set up the stack
   push %eax                       # Multiboot magic number
   push %ebx                       # Multiboot data structure

   # calling static constructors
   mov  $start_ctors, %ebx
   jmp  _2
_1:
   call *(%ebx)
   add  $4, %ebx
_2:
   cmp  $end_ctors, %ebx
   jb   _1

   call kmain

   # calling static destructors
   mov  $start_dtors, %ebx
   jmp  _4
_3:
   call *(%ebx)
   add  $4, %ebx
_4:
   cmp  $end_dtors, %ebx
   jb   _3

hang:
   hlt         # halt machine should kernel return
   jmp   hang

