/****************************************************************************
 * lulzKey. Let's close those effin Windows so penguins won't enter.        *
 *                                                                          *
 * Copyright (C) 2009  meh. [http://meh.doesntexist.org]                    *
 *                                                                          *
 * This program is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 ****************************************************************************/

#include <Type.h>
#include <Boot/Boot.h>
#include <Memory/Memory.h>
#include <DescriptorTables/DescriptorTables.h>
#include <Interrupt/Interrupt.h>

#include <Tools/Shell/Shell.h>
#include <Tools/Debug/Debug.h>

using namespace Kernel;

extern "C"
void
main (Type::u32 magic, void* information)
{
    Shell shell; 

    if (magic != Boot::Magic) {
        shell << "What, it's not a Multiboot-compliant boot loader :(" << Shell::endLine;
        return;
    }

    Boot boot(information);
    Debug::dump(boot);

    DescriptorTables::init();
    Memory::Paging::init(boot.memory()->upper);
}

