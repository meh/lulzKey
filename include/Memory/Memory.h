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
    static void* alloc (Type::u32 size);
    static void  free  (void* pointer);

    static void copy (void* destination, void* source, Type::u32 size);
    static void set  (void* destination, Type::u8 value, Type::u32 size); 

  private:
    void*       _memory;
    Type::u32 _size;

  public:
    Memory (Type::u32 size);
    Memory (Memory& memory);

    virtual ~Memory ();

    Type::u32 size (void);
    void      size (Type::u32 size);

    const void* data (void);
    void        data (Memory& memory, Type::u32 offset = 0);
    void        data (void* memory, Type::u32 size, Type::u32 offset = 0);

    void* pointer (void);

  public:
    operator void*     ();
    operator Type::u32 ();
};

}

// Kernel space new's
void* operator new   (Type::u32 size);
void* operator new[] (Type::u32 size);

// Kernel space delete's
void operator delete   (void* pointer);
void operator delete[] (void* pointer);

#endif
