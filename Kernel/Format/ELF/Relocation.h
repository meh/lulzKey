/****************************************************************************
* lulzKey. Let's close those effin Windows so penguins won't enter.         *
*                                                                           *
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* lulzKey is free software: you can redistribute it and/or modify           *
* it under the terms of the GNU Affero General Public License as published  *
* by the Free Software Foundation, either version 3 of the License, or      *
* (at your option) any later version.                                       *
*                                                                           *
* lulzKey is distributed in the hope that it will be useful,                *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with lulzKey.  If not, see <http://www.gnu.org/licenses/>.          *
****************************************************************************/

#ifdef _LKEY_FORMAT_ELF_H

class Relocation 
{
  public:
    struct _32 {
        Type::u32 offset;
        Type::u32 info;
    };

    struct _32b {
        Type::u32 offset;
        Type::u32 info;
        Type::s32 addend;
    };

    struct _64 {
        Type::u64 offset;
        Type::u64 info;
    };

    struct _64b {
        Type::u64 offset;
        Type::u64 info;
        Type::s64 addend;
    };

  private:
    Type::u8 _arch;
    void*    _data;

  public:
    Relocation(_32* data, Type::s32 addend = 0);
    Relocation(_64* data, Type::s64 addend = 0);
};

#endif
