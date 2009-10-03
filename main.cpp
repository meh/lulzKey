#include <Type.h>
#include <Memory/Memory.h>

#include <Tools/Shell/Shell.h>

using namespace Kernel;

extern "C"
void
main (Type::MultiBoot* multiBoot, unsigned int magic)
{
    /* the magic number is wrong */
    if (magic != 0x2BADB002) {
        return;
    }

    Shell shell;

    shell.clear();

    shell << Shell::Color(Shell::Color::Yellow) << "giallo" << Shell::endLine;
    shell << Shell::Color(Shell::Color::Pink)   << "vagina" << Shell::endLine;
    shell << 23 << Shell::endLine;
}
