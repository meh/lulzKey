/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Kernel.h>
#include <Tools/Shell/Shell.h>

namespace Kernel {

Shell shell;

void
panic (const char* message)
{
    asm volatile ("cli");

    Kernel::shell << "PANIC: " << message << Shell::endLine;

    while (true);
}

}

