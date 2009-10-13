/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

/**
 * @file Memory.h
 *
 * @brief Memory management namespace.
 */

#ifndef _LKEY_MEMORY_H
#define _LKEY_MEMORY_H

#include <Type.h>

namespace Kernel {

class Memory
{
  public:
    static void copy (void* destination, void* source, Type::u32 size);
    static void set  (void* destination, Type::u8 value, Type::u32 size); 
};

}

#endif
