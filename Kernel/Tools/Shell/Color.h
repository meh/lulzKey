/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
    static const char LightGray  = 0x7;
    static const char Gray       = 0x8;
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
    bool _blinking;

  public:
    Color (char foreground = White, char background = Black, bool blinking = false);

    char foreground (void);
    void foreground (char color);

    char background (void);
    void background (char color);

    bool blinking (void);
    void blinking (bool);

    unsigned char value (void);
};

#endif
