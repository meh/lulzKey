#include <Type.h>
#include <Boot/Boot.h>
#include <Memory/Memory.h>

#include <Tools/Shell/Shell.h>

using namespace Kernel;

extern "C"
void
main (Type::u32 magic, void* information)
{
    if (magic != Boot::Magic) {
        return;
    }

    Boot boot = Boot(information);

    Shell shell;

    shell.clear();

    shell << Shell::Color(Shell::Color::Yellow) << "giallo" << Shell::endLine;
    shell << Shell::Color(Shell::Color::Pink)   << "vagina" << Shell::endLine;
    shell << 23 << Shell::endLine;
}
