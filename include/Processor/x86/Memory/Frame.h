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

#ifdef  _LKEY_MEMORY_H
#ifdef  _LKEY_MEMORY_PAGING_H
#ifndef _LKEY_MEMORY_FRAME_H
#define _LKEY_MEMORY_FRAME_H

class Frame
{
  protected:
    Frame (void) {};

  public:
    static Type::u32* frames;
    static Type::u32  frameNumber;

  public:
    static void alloc (Page* page, bool isKernel, bool isWriteable);

    static void free (Page* page);

    static void set (Type::u32 address);

    static void clear (Type::u32 address);

    static bool test (Type::u32 address);

    static Type::u32 findFirst (void);
};

#endif
#endif
#endif
