/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

/**
 * @file Misc/IO.h
 *
 * @brief Low level input and output functions.
 */

#ifndef _LKEY_MISC_IO_H
#define _LKEY_MISC_IO_H

#include <Type.h>

namespace Kernel {

namespace Misc {

static const Type::u8  Byte = 0x1;
static const Type::u16 Word = 0x2;
static const Type::u32 Long = 0x4;

void     out (Type::u16 port, Type::u8 value);
Type::u8 in  (Type::u16 port, Type::u8 type);

void      out (Type::u16 port, Type::u16 value);
Type::u16 in  (Type::u16 port, Type::u16 type);

void      out (Type::u16 port, Type::u32 value);
Type::u32 in  (Type::u16 port, Type::u32 type);

}

}

#endif
