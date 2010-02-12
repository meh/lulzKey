/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
