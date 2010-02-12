/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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

    #ifdef _NAZI
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

