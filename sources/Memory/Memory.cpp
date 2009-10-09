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

#include <Memory/Memory.h>

namespace Kernel {

void
Memory::copy (void* destination, void* source, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = ((Type::u8*) source)[i];
    }
}

void
Memory::set (void* destination, Type::u8 value, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = value;
    }
}

}

