/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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

void*
Multiboot::end (void)
{
    return (void*) (_info + sizeof(Info));
}

}
