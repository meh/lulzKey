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

