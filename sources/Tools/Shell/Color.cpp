/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Tools/Shell/Shell.h>

namespace Kernel {

Shell::Color::Color (char foreground, char background, bool blinking)
{
    if (foreground < 0) {
        _foreground = White;
    }
    else {
        _foreground = foreground;
    }

    if (background < 0) {
        _background = Black;
    }
    else {
        _background = background;
    }

    _blinking = blinking;
}

char
Shell::Color::foreground (void)
{
    return _foreground;
}

void
Shell::Color::foreground (char color)
{
    _foreground = color;
}

char
Shell::Color::background (void)
{
    return _background;
}

void
Shell::Color::background (char color)
{
    _background = color;
}

bool
Shell::Color::blinking (void)
{
    return _blinking;
}

void
Shell::Color::blinking (bool blinking)
{
    _blinking = blinking;
}

unsigned char
Shell::Color::value (void)
{
    return (this->background() * 16) + this->foreground() | (this->blinking() ? 0x80 : 0);
}

}
