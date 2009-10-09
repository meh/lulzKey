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

#include <Boot/Multiboot.h>

namespace Kernel {

Multiboot::Multiboot (void* information)
{
    _info = (Info*) information;
}

Multiboot::Memory*
Multiboot::memory (void)
{
    return CHECK_FLAG(_info->flags, 0)
        ? (Memory*) &_info->memLower
        : NULL;
}

Multiboot::Device*
Multiboot::device (void)
{
    return CHECK_FLAG(_info->flags, 1)
        ? (Device*) _info->bootDevice
        : NULL;
}

const char*
Multiboot::command (void)
{
    return CHECK_FLAG(_info->flags, 2)
        ? (const char*) _info->command
        : NULL;
}

Multiboot::Modules*
Multiboot::modules (void)
{
    return CHECK_FLAG(_info->flags, 3)
        ? (Modules*) &_info->modulesCount
        : NULL;
}

void
Multiboot::modules (void (*function)(Multiboot::Module* module))
{
    Modules* modules = this->modules();

    for (Type::u32 i = 0; i < modules->length; i++) {
        function(modules->item[i]);
    }
}

Multiboot::MemoryMaps*
Multiboot::memoryMaps (void)
{
    return CHECK_FLAG(_info->flags, 6)
        ? (MemoryMaps*) &_info->mmapLength
        : NULL;
}

Multiboot::Drives*
Multiboot::drives (void)
{
    return CHECK_FLAG(_info->flags, 7)
        ? (Drives*) &_info->drivesLength
        : NULL;
}

void
Multiboot::drives (void (*function)(Multiboot::Drive*))
{
    Type::u32 size   = this->drives()->size;
    Drive*    first  = this->drives()->first;
    Type::u32 offset = 0;
    
    while (offset < size) {
        Drive* drive = (Drive*) (((Type::u8*) first) + offset);
        offset      += drive->size;

        function(drive);
    }
}

void*
Multiboot::configTable (void)
{
    return CHECK_FLAG(_info->flags, 8)
        ? (void*) _info->configTable
        : NULL;
}

const char*
Multiboot::bootLoader (void)
{
    return CHECK_FLAG(_info->flags, 9)
        ? (const char*) _info->bootLoader
        : NULL;
}

Multiboot::APM*
Multiboot::APMTable (void)
{
    return CHECK_FLAG(_info->flags, 10)
        ? (APM*) _info->APMTable
        : NULL;
}

Multiboot::VBE*
Multiboot::graphicsTable (void)
{
    return CHECK_FLAG(_info->flags, 11)
        ? (VBE*) &_info->graphicsTable
        : NULL;
}

}
