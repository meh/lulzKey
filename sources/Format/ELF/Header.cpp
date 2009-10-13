/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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

