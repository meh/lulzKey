/**
 * @file Boot/Boot.h
 *
 * @brief Boot class and structs.
 */

#ifndef _LKEY_BOOT_H
#define _LKEY_BOOT_H

#include <Type.h>

namespace Kernel {

/**
 * MultiBoot compliant class.
 *
 * Class used to simplify and abstract the multiboot specification:
 * http://www.gnu.org/software/grub/manual/multiboot/
 */
class Boot
{
  public:
    /**
     * Multiboot magic number, used to understand if the booting system follows the specification.
     */
    static const Type::u32 Magic = 0x2BADB002;

  private:
    /**
     * Multiboot compliant boot information struct.
     */
    struct Info {
        Type::u32 flags;            /*<< multiboot flags */
        Type::u32 memLower;         /*<< low memory address */
        Type::u32 memUpper;         /*<< high memory address */
        Type::u32 bootDevice;       /*<< boot device */
        Type::u32 command;          /*<< command line passed through the boot loader */
        Type::u32 modulesCount;     /*<< modules count */
        Type::u32 modulesAddress;   /*<< modules array address */

        struct {
            Type::u32 num;
            Type::u32 size;
            Type::u32 address;
            Type::u32 shndx;
        } ELF;

       Type::u32 mmapLength;
       Type::u32 mmapAddress;
    };

    struct Module {
        Type::u32 start;
        Type::u32 end;
        Type::u32 string;
        Type::u32 reserved;
    };

  private:
    Info* _info;

  public:
    Boot (void* information);

    const char* command (void);

  private:
    bool _checkFlag (Type::u32 flags, char bit);
};

}

#endif
