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
#include <Kernel.h>

namespace Kernel {

namespace Debug {

void _dumpBootDrives (Multiboot::Drive* drive);

void
dump (Multiboot& boot)
{
    Kernel::shell << "Boot dump..." << Shell::endLine;

    Kernel::shell << "Boot end:     " << boot.end() << Shell::endLine;

    Kernel::shell << "Booting from: ";
    if (boot.bootLoader()) {
        Kernel::shell << boot.bootLoader();
    }
    else {
        Kernel::shell << "Unknown";
    }
    Kernel::shell << Shell::endLine;

    Kernel::shell << "Boot options: " << boot.command() << Shell::endLine;

    Kernel::shell << "Memory:       ";
    if (boot.memory()) {
        Kernel::shell << "lower=" << boot.memory()->lower << "KB; upper=" << boot.memory()->upper << "KB;";
    }
    else {
        Kernel::shell << "Invalid memory bounds.";
    }
    Kernel::shell << Shell::endLine;

    Kernel::shell << "Boot device:  ";
    if (boot.device()) {
        Kernel::shell << "BIOS=" << (void*) boot.device()->BIOS << "; ";
        Kernel::shell << "Partition=" << (Type::u32) boot.device()->partition.topLevel;

        if (boot.device()->partition.subLevel != 0xFF) {
            Kernel::shell << "," << (Type::u32) boot.device()->partition.subLevel;

            if (boot.device()->partition.subSubLevel != 0xFF) {
                Kernel::shell << "," << (Type::u32) boot.device()->partition.subSubLevel;
            }
        }
        Kernel::shell << ";"; 
    }
    else {
        Kernel::shell << "Invalid device.";
    }
    Kernel::shell << Shell::endLine;

    Kernel::shell << "Drives: ";
    if (boot.drives()->size == 0) {
        Kernel::shell << "      None.";
    }
    else {
        Kernel::shell << Shell::endLine;
        boot.drives(&_dumpBootDrives);
    }
    Kernel::shell << Shell::endLine;
}

void
_dumpBootDrives (Multiboot::Drive* drive)
{
    Kernel::shell << "    ";
    Kernel::shell << (Type::u32) drive->number;
    Kernel::shell << " [C=" << drive->cylinders << ", H=" << (Type::u32) drive->heads << ", S=" << (Type::u32) drive->sectors << "]";
    Kernel::shell << " {" << (drive->mode == 0 ? "CHS" : "LBA") << "} ";

    if (drive->size > 10) {
        Type::u16* ports  = drive->ports;
        Type::u16  offset = 0;

        Kernel::shell << "(" << (void*) *ports;
        ports++;
        offset++;

        while (((Type::u32) (10 + (offset * 2))) < drive->size) {
            Kernel::shell << ", " << (void*) *ports;
            ports++;
            offset++;
        }
        Kernel::shell << ")";
    }
    else {
        Kernel::shell << "(N/A)";
    }

    Kernel::shell << Shell::endLine;
}

}

}

