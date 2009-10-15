/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <Kernel.h>
#include <Tools/Shell/Shell.h>

namespace Kernel {

Shell shell;

#define PADDING    "                        "
#define BORDER     Shell::Color(Shell::Color::White, Shell::Color::Red, true)
#define BACKGROUND Shell::Color(Shell::Color::White, Shell::Color::White)
#define CONTENT    Shell::Color(Shell::Color::White, Shell::Color::Black)
#define VOID       Shell::Color()

void
NAZI (void)
{
    shell.clear();

    shell << Shell::endLine;
    shell << PADDING << BORDER << "             " << "KERNEL" << "             " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "                            " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "              " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "              " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "            " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "            " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "            " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "                        " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "                        " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "            " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "            " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "    " << BACKGROUND << "            " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "              " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "  " << CONTENT << "    " << BACKGROUND << "      " << CONTENT << "              " << BACKGROUND << "  " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "  " << BACKGROUND << "                            " << BORDER << "  " << VOID << Shell::endLine;
    shell << PADDING << BORDER << "           " << "HOLOCAUST!" << "           " << VOID << Shell::endLine;
}

void
panic (const char* message)
{
    asm volatile ("cli");

    NAZI();

    shell << Shell::endLine << message << Shell::endLine;

    while (true);
}

}

