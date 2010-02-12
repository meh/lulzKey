/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
