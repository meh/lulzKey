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

#ifdef _LKEY_TOOLS_SHELL_H

class Color
{
  public:
    static const char Black      = 0x0;
    static const char Blue       = 0x1;
    static const char Green      = 0x2;
    static const char Cyan       = 0x3;
    static const char Red        = 0x4;
    static const char Magenta    = 0x5;
    static const char Brown      = 0x6;
    static const char Gray       = 0x7;
    static const char LightGray  = 0x8;
    static const char LightBlue  = 0x9;
    static const char LightGreen = 0xA;
    static const char LightCyan  = 0xB;
    static const char LightRed   = 0xC;
    static const char Pink       = 0xD;
    static const char Yellow     = 0xE;
    static const char White      = 0xF;

  private:
    char _foreground;
    char _background;

  public:
    Color (char foreground = White, char background = Black);

    char foreground (void);
    void foreground (char color);

    char background (void);
    void background (char color);

    unsigned char value (void);
};

#endif
