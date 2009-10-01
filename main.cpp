#include <Type.h>

void
clear (void)
{
    Type::uchar* vr = (Type::uchar*) 0xb8000;

    for (Type::uint i = 0; i < 25*80; i += 2) {
        vr[i]   = 0x20;
        vr[i+1] = 0x00;
    }
}

extern "C"
void
kmain (Type::MultiBoot* multiBoot, Type::uint magic)
{
    /* the magic number is wrong */
    if (magic != 0x2BADB002) {
        return;
    }

    clear();

    Type::uchar* videoram = (Type::uchar*) 0xb8000;
    videoram[0]  = 103;
    videoram[1]  = 0xE;
    videoram[2]  = 105;
    videoram[3]  = 0xE;
    videoram[4]  = 97;
    videoram[5]  = 0xE;
    videoram[6]  = 108;
    videoram[7]  = 0xE;
    videoram[8]  = 108;
    videoram[9]  = 0xE;
    videoram[10] = 111;
    videoram[11] = 0xE;
}
