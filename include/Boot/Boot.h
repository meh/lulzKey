/**
 * @file Boot/Boot.h
 *
 * @brief Boot class and structs.
 */

#ifndef _LKEY_BOOT_H
#define _LKEY_BOOT_H

namespace Kernel {

class Boot
{
  public:
    static const Type::u32 Magic = 0x2BADB002;

  private:
    struct Info {
        unsigned long flags;
        unsigned long memLower;
        unsigned long memUpper;
        unsigned long bootDevice;
        unsigned long command;
        unsigned long modulesCount;
        unsigned long modulesAddr;

        struct {
            unsigned long num;
            unsigned long size;
            unsigned long addr;
            unsigned long shndx;
        } ELF;

       unsigned long mmap_length;
       unsigned long mmap_addr;
    };

    struct Module {
        unsigned long start;
        unsigned long end;
        unsigned long string;
        unsigned long reserved;
    };

  private:
    Info _info;

  public:
    Boot (void* information);

  private:
    bool _checkFlag (unsigned long flags, char bit);
};

}

#endif
