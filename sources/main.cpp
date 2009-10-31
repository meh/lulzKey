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

#include <Processor/Processor.h>
#include <Services/Services.h>

#include <Tools/Shell/Shell.h>
#include <Tools/Debug/Debug.h>

using namespace Kernel;

extern "C"
int
main (Type::u32 magic, void* information, Type::u32 initialStack)
{
    Kernel::shell << "O HAI! DIS BEE ";
    Kernel::shell << Shell::Color(Shell::Color::Red) << "LULZKEY-" << ___VERSION___ << Shell::Color();
    Kernel::shell << "! ENJOY YOUR " << Shell::Color(-1, -1, true) << "TRIPLE FAULTS" << Shell::Color() << "!" << Shell::endLine << Shell::endLine;

    if (magic != Multiboot::Magic) {
        shell << "What, it's not a Multiboot-compliant boot loader :(" << Shell::endLine;
        return 1;
    }

    Multiboot boot(information);

    Processor::init(boot);
    Services::init(boot);

    return 0;
}

