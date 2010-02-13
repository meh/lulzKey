/****************************************************************************
* lulzKey. Let's close those effin Windows so penguins won't enter.         *
*                                                                           *
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* lulzKey is free software: you can redistribute it and/or modify           *
* it under the terms of the GNU Affero General Public License as published  *
* by the Free Software Foundation, either version 3 of the License, or      *
* (at your option) any later version.                                       *
*                                                                           *
* lulzKey is distributed in the hope that it will be useful,                *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with lulzKey.  If not, see <http://www.gnu.org/licenses/>.          *
****************************************************************************/

/**
 * @file Format/ELF.h
 *
 * @brief ELF
 */

#ifndef _LKEY_FORMAT_ELF_H
#define _LKEY_FORMAT_ELF_H

#include <Type.h>

namespace Format {

/**
 * ELF headers.
 */
class ELF
{
  public:
    typedef Type::u8 Arch;
    typedef Type::u8 Endianess;

  public:
    #include <Format/ELF/Header.h>
    #include <Format/ELF/ProgramHeader.h>
    #include <Format/ELF/SectionHeader.h>
    #include <Format/ELF/Symbol.h>
    #include <Format/ELF/Relocation.h>
    #include <Format/ELF/Dynamic.h>

  private:
    int   _arch;
    void* _start;
    void* _end;

  public:
    ELF (void* start, void* end);

    void* find (const char* symbol);
};

}

#endif
