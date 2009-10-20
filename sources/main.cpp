/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Type.h>
#include <Kernel.h>
#include <Boot/Multiboot.h>

#if 0
#include <Processor/Processor.h>
#include <Interrupt/Interrupt.h>
#include <Services/Services.h>
#endif

#include <Tools/Shell/Shell.h>
#include <Tools/Debug/Debug.h>

using namespace Kernel;

extern "C"
void
main (Type::u32 magic, void* information)
{
    Kernel::shell << "O HAI! DIS BEE ";
    Kernel::shell << Shell::Color(Shell::Color::Red) << "LULZKEY-" << ___VERSION___ << Shell::Color();
    Kernel::shell << "! ENJOY YOUR " << Shell::Color(-1, -1, true) << "TRIPLE FAULTS" << Shell::Color() << "!" << Shell::endLine << Shell::endLine;

    if (magic != Multiboot::Magic) {
        shell << "What, it's not a Multiboot-compliant boot loader :(" << Shell::endLine;
        return;
    }

    Multiboot boot(information);
    Debug::dump(boot);

#if 0
    Processor::init(boot);
    Interrupt::init();
    Services::init(boot);

    Type::u32 *ptr = (Type::u32*)0xA0000000;
    Type::u32 do_page_fault = *ptr;
#endif
}

