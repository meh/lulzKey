/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

/**
 * @file Type.h
 *
 * @brief Default kernel types.
 */

#ifndef _LKEY_TYPE_H
#define _LKEY_TYPE_H

namespace Type {
    typedef unsigned char      u8;
    typedef unsigned short     u16;
    typedef unsigned int       u32;
    typedef unsigned long long u64;

    typedef signed char      s8;
    typedef signed short     s16;
    typedef signed int       s32;
    typedef signed long long s64;
}

#define NULL 0

#define CHECK_FLAG(flags, bit) ((flags) & (1 << (bit)))

#endif
