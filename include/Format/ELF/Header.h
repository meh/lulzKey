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

class Header
{
  public:
    static const int IdentSize = 16;

    static const int IdentArch      = 4;
    static const int IdentEndianess = 5;

    static const int      MagicLength = 4;
    static const Type::u8 Magic[MagicLength]; /* "\x7f" "ELF" */

    static const Type::u8 ArchInvalid = 0;
    static const Type::u8 Arch32      = 1;
    static const Type::u8 Arch64      = 2;

    static const Type::u8 EndianessInvalid = 0;
    static const Type::u8 EndianessLittle  = 1;
    static const Type::u8 EndianessBig     = 2;

  public:
    struct _32 {
        Type::u8  ident[IdentSize];
        Type::u16 type;
        Type::u16 machine;
        Type::u32 version;
        Type::u32 entry;
        Type::u32 programHeaderOffset;
        Type::u32 sectionHeaderOffset;
        Type::u32 flags;
        Type::u16 headerSize;
        Type::u16 programHeaderSize;
        Type::u16 programHeaderLength;
        Type::u16 sectionHeaderSize;
        Type::u16 sectionHeaderLength;
        Type::u16 sectionHeaderTableIndex;
    };

    struct _64 {
        Type::u8  ident[IdentSize];
        Type::u16 type;
        Type::u16 machine;
        Type::u32 version;
        Type::u64 entry;
        Type::u64 programHeaderOffset;
        Type::u64 sectionHeaderOffset;
        Type::u32 flags;
        Type::u16 headerSize;
        Type::u16 programHeaderSize;
        Type::u16 programHeaderLength;
        Type::u16 sectionHeaderSize;
        Type::u16 sectionHeaderLength;
        Type::u16 sectionHeaderTableIndex;
    };

  private:
    Arch  _arch;
    void* _data;

  public:
    Header (void* data);
    Header (_32*  data);
    Header (_64*  data);

    Arch arch (void);

    Endianess endianess (void);

  private:
    void _init (void* data);
};

#endif
