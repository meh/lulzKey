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

#include <Tools/Shell/Shell.h>

namespace Kernel {

Shell::Color::Color (char foreground, char background)
{
    _foreground = foreground;
    _background = background;
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

unsigned char
Shell::Color::value (void)
{
    return (this->background() * 16) + this->foreground();
}

}
