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

#ifdef _LKEY_FORMAT_ELF_H

class SectionHeader 
{
  public:
    struct _32 {
        Type::u32 name;
        Type::u32 type;
        Type::u32 flags;
        Type::u32 address;
        Type::u32 offset;
        Type::u32 size;
        Type::u32 link;
        Type::u32 info;
        Type::u32 addressAlign;
        Type::u32 entrySize;
    };

    struct _64 {
        Type::u32 name;
        Type::u32 type;
        Type::u64 flags;
        Type::u64 address;
        Type::u64 offset;
        Type::u64 size;
        Type::u32 link;
        Type::u32 info;
        Type::u64 addressAlign;
        Type::u64 entrySize;
    };

  private:
    Type::u8 _arch;
    void*    _data;

  public:
    SectionHeader(_32* data);
    SectionHeader(_64* data);
};

#endif
