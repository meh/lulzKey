/**
 * @file Boot/Boot.h
 *
 * @brief Boot class and structs.
 */

#ifndef _LKEY_BOOT_H
#define _LKEY_BOOT_H

#include <Type.h>

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
        unsigned long modulesAddress;

        struct {
            unsigned long num;
            unsigned long size;
            unsigned long address;
            unsigned long shndx;
        } ELF;

       unsigned long mmapLength;
       unsigned long mmapAddress;
    };

    struct Module {
        unsigned long start;
        unsigned long end;
        unsigned long string;
        unsigned long reserved;
    };

  private:
    Info* _info;

  public:
    Boot (void* information);

    const char* command (void);

  private:
    bool _checkFlag (unsigned long flags, char bit);
};

}

#endif
