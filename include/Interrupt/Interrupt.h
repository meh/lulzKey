#ifndef _LKEY_INTERRUPT_H
#define _LKEY_INTERRUPT_H

#include <Type.h>

namespace Kernel {

class Interrupt
{
  public:
    struct Registers {
        Type::u32 ds; /*<< data segment selector */
        
        // Pushed by pusha.
        Type::u32 edi;
        Type::u32 esi;
        Type::u32 ebp;
        Type::u32 esp;
        Type::u32 ebx;
        Type::u32 edx;
        Type::u32 ecx;
        Type::u32 eax;

        Type::u32 number;    /*<< interrupt number */
        Type::u32 errorCode; /*<< interrupt error code (if applicable) */

        // Pushed by the processor automatically.
        Type::u32 eip;
        Type::u32 cs;
        Type::u32 eflags;
        Type::u32 useresp;
        Type::u32 ss;
    };

  public:
    static void Handler (Registers registers);

  private:
    Registers _registers;

  public:
    Interrupt (Registers registers);
};

}

#endif
