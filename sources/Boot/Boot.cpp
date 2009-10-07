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

bool
Boot::validMemory (void)
{
    return _checkFlag(_info->flags, 0);
}

bool
Boot::validDevice (void)
{
    return _checkFlag(_info->flags, 1);
}

bool
Boot::validModules (void)
{
    return _checkFlag(_info->flags, 3);
}

bool
Boot::validELF (void)
{
    return _checkFlag(_info->flags, 5);
}

bool
Boot::validMmap (void)
{
    return _checkFlag(_info->flags, 6);
}

bool
Boot::LOLNO (void)
{
    return _checkFlag(_info->flags, 4) && _checkFlag(_info->flags, 5);
}

const char*
Boot::command (void)
{
    if (_checkFlag(_info->flags, 2)) {
        return (const char*) _info->command;
    }
    else {
        return (const char*) NULL;
    }
}

Boot::Device*
Boot::device (void)
{
    return (Boot::Device*) _info->bootDevice;
}

Boot::Memory*
Boot::memory (void)
{
    return (Boot::Memory*) &_info->memLower;
}

Boot::Modules*
Boot::modules (void)
{
    return (Boot::Modules*) &_info->modulesCount;
}

bool
Boot::_checkFlag (Type::u32 flags, char bit)
{
    return (flags) & (1 << (bit));
}

}
