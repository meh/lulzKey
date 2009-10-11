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

class ProgramHeader
{
  public:
    struct _32 {
        Type::u32 type;
        Type::u32 offset;
        Type::u32 virtualAddress;
        Type::u32 physicalAddress;
        Type::u32 fileSize;
        Type::u32 memorySize;
        Type::u32 flags;
        Type::u32 align;
    };

    struct _64 {
        Type::u32 type;
        Type::u32 flags;
        Type::u64 offset;
        Type::u64 virtualAddress;
        Type::u64 physicalAddress;
        Type::u64 fileSize;
        Type::u64 memorySize;
        Type::u64 align;
    };

  private:
    Type::u8 _arch;
    void*    _data;

  public:
    ProgramHeader(_32* data);
    ProgramHeader(_64* data);
};

#endif
