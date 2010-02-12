/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifdef _LKEY_FORMAT_ELF_H

class Dynamic 
{
  public:
    struct _32 {
        Type::s32 tag;

        union {
            Type::u32 value;
            Type::u32 pointer;
        } un;
    };

    struct _64 {
        Type::s64 tag;

        union {
            Type::u64 value;
            Type::u64 pointer;
        } un;
    };

  private:
    Type::u8 _arch;
    void*    _data;

  public:
    Dynamic(_32* data);
    Dynamic(_64* data);
};

#endif
