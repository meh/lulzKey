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
 * @file Tools/Shell.h
 *
 * @brief Kernel shell header
 */

#ifndef _LKEY_TOOLS_SHELL_H
#define _LKEY_TOOLS_SHELL_H

#include <stdarg.h>

#include <Type.h>

namespace Kernel {

class Shell
{
  public:
    #include <Tools/Shell/Color.h>
    #include <Tools/Shell/OutputMode.h>

  public:
    static const Type::u16 VGA = 0x3D4;

    static const int Default = -1;

    static const Type::u8 lines   = 25;
    static const Type::u8 columns = 80;

    static const Type::u8 endLine = '\n';

  private:
    static Shell* _object;

  private:
    Type::u8* _video;
    Type::u8  _y;
    Type::u8  _x;
    Color     _color;

  public:
    Shell (const void* address = (void*) 0xb8000);

    void clear (void);

    void scroll (Type::u32 lines = 1);

    void moveCursor (char x, char y);

    Type::u32 printf (const char* message, ...);
    Type::u32 printf (const char* message, va_list args);

    void   color (Color& color);
    void   color (char foreground, char background = Shell::Color::Black, bool blinking = false);
    Color& color (void);

    Type::u32 print (char out);
    Type::u32 print (unsigned char out);

    Type::u32 print (short out);
    Type::u32 print (unsigned short out);

    Type::u32 print (int out);
    Type::u32 print (unsigned int out);

    Type::u32 print (long out);
    Type::u32 print (unsigned long out);

    Type::u32 print (const void* out);

    Type::u32 print (const char* out);

    Type::u32 _binary      (unsigned long out);
    Type::u32 _octal       (unsigned long out);
    Type::u32 _hexadecimal (unsigned long out);

  public:
    Shell& operator << (Color color);

    Shell& operator << (char out);
    Shell& operator << (unsigned char out);

    Shell& operator << (short out);
    Shell& operator << (unsigned short out);

    Shell& operator << (int out);
    Shell& operator << (unsigned int out);

    Shell& operator << (long out);
    Shell& operator << (unsigned long out);

    Shell& operator << (const void* out);

    friend Shell& operator << (Shell& shell, const char* out);
};

}

#endif
