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

#include <Boot/Boot.h>

namespace Kernel {

Boot::Boot (void* information)
{
    _info = (Info*) information;


}

Boot::Memory*
Boot::memory (void)
{
    return CHECK_FLAG(_info->flags, 0)
        ? (Boot::Memory*) &_info->memLower
        : NULL;
}

Boot::Device*
Boot::device (void)
{
    return CHECK_FLAG(_info->flags, 1)
        ? (Boot::Device*) _info->bootDevice
        : NULL;
}

const char*
Boot::command (void)
{
    return CHECK_FLAG(_info->flags, 2)
        ? (const char*) _info->command
        : NULL;
}

Boot::Modules*
Boot::modules (void)
{
    return CHECK_FLAG(_info->flags, 3)
        ? (Boot::Modules*) &_info->modulesCount
        : NULL;
}

void
Boot::modules (void (*function)(Boot::Module* module))
{
    Boot::Modules* modules = this->modules();

    for (Type::u32 i = 0; i < modules->length; i++) {
        function(modules->item[i]);
    }
}

Boot::MemoryMaps*
Boot::memoryMaps (void)
{
    return CHECK_FLAG(_info->flags, 6)
        ? (Boot::MemoryMaps*) &_info->mmapLength
        : NULL;
}

Boot::Drives*
Boot::drives (void)
{
    return CHECK_FLAG(_info->flags, 7)
        ? (Boot::Drives*) &_info->drivesLength
        : NULL;
}

void
Boot::drives (void (*function)(Boot::Drive*))
{
    Type::u32    size   = this->drives()->size;
    Boot::Drive* first  = this->drives()->first;
    Type::u32    offset = 0;
    
    while (offset < size) {
        Boot::Drive* drive = (Boot::Drive*) (((Type::u8*) first) + offset);
        offset            += drive->size;

        function(drive);
    }
}

void*
Boot::configTable (void)
{
    return CHECK_FLAG(_info->flags, 8)
        ? (void*) _info->configTable
        : NULL;
}

const char*
Boot::bootLoader (void)
{
    return CHECK_FLAG(_info->flags, 9)
        ? (const char*) _info->bootLoader
        : NULL;
}

Boot::APM*
Boot::APMTable (void)
{
    return CHECK_FLAG(_info->flags, 10)
        ? (Boot::APM*) _info->APMTable
        : NULL;
}

Boot::VBE*
Boot::graphicsTable (void)
{
    return CHECK_FLAG(_info->flags, 11)
        ? (Boot::VBE*) &_info->graphicsTable
        : NULL;
}

}
