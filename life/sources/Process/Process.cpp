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

/**
 * @file Process/Process.cpp
 *
 * @brief Process implementation
 */

#include <Process/Process.h>

Process::Process (void)
{

}

void
Process::pid (Type::u32 pid)
{
    _pid = pid;
}

Type::u32
Process::pid (void)
{
    return _pid;
}

void
Process::context (Process::Context context)
{
    _context = context;
}

Process::Context
Process::context (void)
{
    return _context;
}

Type::u32
Process::hash (const char* string)
{
    Type::u32 hash = 5381;
    int ch;

    while (ch = *str++) {
        hash = ((hash << 5) + hash) + ch;
    }

    return hash;
}

