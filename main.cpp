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

    Boot boot(information);
    Shell shell;

    shell << "Boot options: " << boot.command() << Shell::endLine;
    shell << "Boot device:  " << (void*) boot.device() << Shell::endLine;
}
