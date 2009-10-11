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

#include <Format/ELF/ELF.h>

namespace Format {

const Type::u8 ELF::Header::Magic[ELF::Header::MagicLength] = { '\x7f', 'E', 'L', 'F' };

ELF::Header::Header (void* data)
{
    _init(data);
}

ELF::Header::Header (ELF::Header::_32* data)
{
    _init(data);
}

ELF::Header::Header (ELF::Header::_64* data)
{
    _init(data);
}

void
ELF::Header::_init (void* data)
{
    Type::u8* ident = (Type::u8*) data;

    if (ident[IdentArch] == Arch32) {
        _arch = 32;
    }
    else if (ident[IdentArch] == Arch64) {
        _arch = 64;
    }

    _data = data;
}

ELF::Arch
ELF::Header::arch (void)
{
    return _arch;
}

ELF::Endianess
ELF::Header::endianess (void)
{
    return ((Type::u8*) _data)[IdentEndianess];
}

}

