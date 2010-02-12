/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
