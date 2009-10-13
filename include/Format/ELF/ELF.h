/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
