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

#include <stdarg.h>

#include <Kernel.h>
#include <Tools/Shell/Shell.h>

namespace Kernel {

Shell shell;

#define PADDING    "                        "
#define BORDER     Shell::Color(Shell::Color::White, Shell::Color::Red, true)
#define BACKGROUND Shell::Color(Shell::Color::White, Shell::Color::White)
#define CONTENT    Shell::Color(Shell::Color::White, Shell::Color::Black)
#define VOID       Shell::Color()

// Weird shell attitude here, someone find out why we need to clean after the VOID.
void
_panicImage (void)
{
    shell.clear();

    #ifdef _PANIC_NAZI
    shell << Shell::endLine;
    shell << PADDING << BORDER << "             " << "KERNEL" << "             " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "                            " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "              " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "              " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "            " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "            " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "            " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "                        " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "                        " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "            " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "            " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "            " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "              " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "              " << BACKGROUND << "  " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "                            " << BORDER << "  " << VOID << " " << Shell::endLine;
    shell << PADDING << BORDER << "           " << "HOLOCAUST!" << "           " << VOID << " " << Shell::endLine;
    shell << Shell::endLine;
    #endif
}

void
panic (const char* message, ...)
{
    asm volatile ("cli");

    _panicImage();

    va_list args;
    va_start(args, message);

    shell.printf(message, args);

    va_end(args);

    while (true) {
        // HARBL HARBL HARBL
    }
}

}

