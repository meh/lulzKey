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

#include <Tools/Debug/Debug.h>

#include <Tools/Shell/Shell.h>

namespace Kernel {

namespace Debug {

void
dump (Boot& boot)
{
    Shell shell;

    shell << "Booting from: ";
    if (boot.bootLoader()) {
        shell << boot.bootLoader();
    }
    else {
        shell << "Unknown";
    }
    shell << Shell::endLine;

    shell << "Boot options: " << boot.command() << Shell::endLine;

    shell << "Boot device:  ";
    if (boot.device()) {
        shell << "BIOS=" << (Type::u32) boot.device()->BIOS << "; ";
        shell << "Partition=" << (Type::u32) boot.device()->partition.topLevel << "; ";
    }
    else {
        shell << "Invalid device.";
    }
    shell << Shell::endLine;

    shell << "Memory:       ";
    if (boot.memory()) {
        shell << "lower=" << boot.memory()->lower << "; upper=" << boot.memory()->upper;
    }
    else {
        shell << "Invalid memory bounds.";
    }
    shell << Shell::endLine;
}

}

}

