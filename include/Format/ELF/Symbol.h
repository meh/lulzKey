/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifdef _LKEY_FORMAT_ELF_H

class Symbol 
{
  public:
    struct _32 {
        Type::u32 name;
        Type::u32 value;
        Type::u32 size;
        Type::u8  info;
        Type::u8  other;
        Type::u16 sectionHeaderIndex;
    };

    struct _64 {
        Type::u32 name;
        Type::u8  info;
        Type::u8  other;
        Type::u16 sectionHeaderIndex;
        Type::u64 value;
        Type::u64 size;
    };

  private:
    Type::u8 _arch;
    void*    _data;

  public:
    Symbol(_32* data);
    Symbol(_64* data);
};

#endif
