#include <Type.h>

extern "C"
void
kmain (Type::MultiBoot* multiBoot, Type::uint magic)
{
    /* the magic number is wrong */
    if (magic != 0x2BADB002) {
        return;
    }

    Type::uchar* videoram = (Type::uchar*) 0xb8000;
    videoram[0] = 65;
    videoram[1] = 0x07;
}
