#include <Type.h>

extern Type::ulong start_ctors;
extern Type::ulong end_ctors;
extern Type::ulong start_dtors;
extern Type::ulong end_dtors;

extern "C" void kmain (Type::MultiBoot* multiBoot, Type::uint magic);
  
extern "C"
void
loader (Type::MultiBoot* multiBoot, Type::uint magic)
{
    for (Type::ulong* call = &start_ctors; call < &end_ctors; call++) {
        ((void (*)(void))* call)();
    }

    kmain(multiBoot, magic);

    for (Type::ulong* call = &start_dtors; call < &end_dtors; call++) {
        ((void (*)(void))* call)();
    }

    __asm__("hlt");
}

