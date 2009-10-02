#include <Type.h>
#include <Memory/Memory.h>

#include <Tools/Shell.h>

using namespace Kernel;

extern "C"
void
kmain (Type::MultiBoot* multiBoot, Type::uint magic)
{
    /* the magic number is wrong */
    if (magic != 0x2BADB002) {
        return;
    }

    Shell shell;

    shell.clear();

    shell.color(Shell::FGYellow);
    shell << "giallo" << Shell::endLine << Shell::endLine;
    shell.color(Shell::FGPink);
    shell << "vagina" << Shell::endLine;
}
