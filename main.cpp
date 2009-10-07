#include <Type.h>
#include <Boot/Boot.h>
#include <Memory/Memory.h>
#include <DescriptorTables/DescriptorTables.h>
#include <Interrupt/Interrupt.h>

#include <Tools/Shell/Shell.h>

using namespace Kernel;

void FORTYTWO (Interrupt::Registers registers)
{
    Shell shell;

    shell << "LOL YOU'RE A FAGGOT!1!" << Shell::endLine;
}

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

    shell << "Boot device:  ";
    if (boot.validDevice()) {
        shell << "BIOS=" << (Type::u32) boot.device()->BIOS << "; ";
        shell << "Partition=" << (Type::u32) boot.device()->partition.topLevel << "; ";
    }
    else {
        shell << "Invalid device.";
    }
    shell << Shell::endLine;

    shell << "Memory:       ";
    if (boot.validMemory()) {
        shell << "lower=" << boot.memory()->lower << "; upper=" << boot.memory()->upper;
    }
    else {
        shell << "Invalid memory bounds.";
    }
    shell << Shell::endLine;

    DescriptorTables::init();

    Interrupt::define(0x42, &FORTYTWO);

    asm volatile ("int $0x42");
}

