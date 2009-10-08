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

void _dumpBootDrives (Boot::Drive* drive);

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

    shell << "Memory:       ";
    if (boot.memory()) {
        shell << "lower=" << boot.memory()->lower << "KB; upper=" << boot.memory()->upper << "KB;";
    }
    else {
        shell << "Invalid memory bounds.";
    }
    shell << Shell::endLine;

    shell << "Boot device:  ";
    if (boot.device()) {
        shell << "BIOS=" << (void*) boot.device()->BIOS << "; ";
        shell << "Partition=" << (void*) boot.device()->partition.topLevel;

        if (boot.device()->partition.subLevel != 0xFF) {
            shell << "," << (void*) boot.device()->partition.subLevel;

            if (boot.device()->partition.subSubLevel != 0xFF) {
                shell << "," << (void*) boot.device()->partition.subSubLevel;
            }
        }
        shell << ";"; 
    }
    else {
        shell << "Invalid device.";
    }
    shell << Shell::endLine;

    shell << Shell::endLine;
    shell << "Drives: ";
    if (boot.drives()->size == 0) {
        shell << "None.";
    }
    else {
        shell << Shell::endLine;
        boot.drives(&_dumpBootDrives);
    }
    shell << Shell::endLine;
}

void
_dumpBootDrives (Boot::Drive* drive)
{
    Shell shell;

    shell << "    ";
    shell << (Type::u32) drive->number;
    shell << " [C=" << drive->cylinders << ", H=" << (Type::u32) drive->heads << ", S=" << (Type::u32) drive->sectors << "]";
    shell << " {" << (drive->mode == 0 ? "CHS" : "LBA") << "} ";

    if (drive->size > 10) {
        Type::u16* ports  = drive->ports;
        Type::u16  offset = 0;

        shell << "(" << (void*) *ports;
        ports++;
        offset++;

        while (((Type::u32) (10 + (offset * 2))) < drive->size) {
            shell << ", " << (void*) *ports;
            ports++;
            offset++;
        }
        shell << ")";
    }
    else {
        shell << "(N/A)";
    }

    shell << Shell::endLine;
}

}

}

