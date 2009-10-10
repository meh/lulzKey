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
 * @file Format/ELF.h
 *
 * @brief ELF
 */

#ifndef _LKEY_FORMAT_ELF_H

#include <Type.h>

namespace Format {

/**
 * ELF headers.
 */
class ELF
{
  public:
    static const int IdentSize = 16;

  private:
    class _32 {
      public:
        struct ElfHeader {
            Type::u8  ident[IdentSize];
            Type::u16 type;
            Type::u16 machine;
            Type::u32 version;
            Type::u32 entry;
            Type::u32 programHeaderOffset;
            Type::u32 sectionHeaderOffset;
            Type::u32 flags;
            Type::u16 elfHeaderSize;
            Type::u16 programHeaderSize;
            Type::u16 programHeaderLength;
            Type::u16 sectionHeaderSize;
            Type::u16 sectionHeaderLength;
            Type::u16 sectionHeaderTableIndex;
        };

        struct ProgramHeader {
            Type::u32 type;
            Type::u32 offset;
            Type::u32 virtualAddress;
            Type::u32 physicalAddress;
            Type::u32 fileSize;
            Type::u32 memorySize;
            Type::u32 flags;
            Type::u32 align;
        };

        struct SectionHeader {
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

        struct Symbol {
            Type::u32 name;
            Type::u32 value;
            Type::u32 size;
            Type::u8  info;
            Type::u8  other;
            Type::u16 sectionHeaderIndex;
        };

        struct Relocation {
            Type::u32 offset;
            Type::u32 info;
        };

        struct RelocationAddend {
            Type::u32 offset;
            Type::u32 info;
            Type::s32 addend;
        };

        struct Dynamic {
            Type::s32 tag;

            union {
                Type::u32 value;
                Type::u32 pointer;
            } un;
        };
    };

    class _64 {
      public:
         struct ElfHeader {
            Type::u8  ident[IdentSize];
            Type::u16 type;
            Type::u16 machine;
            Type::u32 version;
            Type::u64 entry;
            Type::u64 programHeaderOffset;
            Type::u64 sectionHeaderOffset;
            Type::u32 flags;
            Type::u16 elfHeaderSize;
            Type::u16 programHeaderSize;
            Type::u16 programHeaderLength;
            Type::u16 sectionHeaderSize;
            Type::u16 sectionHeaderLength;
            Type::u16 sectionHeaderTableIndex;
        };
       
        struct ProgramHeader {
            Type::u32 type;
            Type::u32 flags;
            Type::u64 offset;
            Type::u64 virtualAddress;
            Type::u64 physicalAddress;
            Type::u64 fileSize;
            Type::u64 memorySize;
            Type::u64 align;
        };

        struct SectionHeader {
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

        struct Symbol {
            Type::u32 name;
            Type::u8  info;
            Type::u8  other;
            Type::u16 sectionHeaderIndex;
            Type::u64 value;
            Type::u64 size;
        };

        struct Relocation {
            Type::u64 offset;
            Type::u64 info;
        };

        struct RelocationAddend {
            Type::u64 offset;
            Type::u64 info;
            Type::u64 addend;
        };

        struct Dynamic {
            Type::s64 tag;

            union {
                Type::u64 value;
                Type::u64 pointer;
            } un;
        };
    };

  private:
    int   _arch;
    void* _start;
    void* _end;

  public:
    ELF (void* start, void* end, int arch);

    void* find (const char* symbol);
};

}

#endif
