/**
 * @file Boot/Boot.h
 *
 * @brief Boot class and structs.
 *
 * I'd go with this:
 * kernel /boot/kernel
 * module /services/deviceDriver
 * module /services/filesystem
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

  public:
    /**
     * Multiboot compliant boot information struct.
     */
    struct Info {
        Type::u32 flags;            /*<< multiboot flags */

        Type::u32 memLower;         /*<< low memory size */
        Type::u32 memUpper;         /*<< high memory size */

        Type::u32 bootDevice;       /*<< boot device informations */ 

        Type::u32 command;          /*<< command line passed through the boot loader */

        Type::u32 modulesCount;     /*<< modules count */
        Type::u32 modulesAddress;   /*<< modules array address */

        /**
         * ELF symbols table.
         */
        struct {
            Type::u32 num;
            Type::u32 size;
            Type::u32 address;
            Type::u32 shndx;
        } ELF;

       Type::u32 mmapLength;    /*<< memory map structures length */
       Type::u32 mmapAddress;   /*<< memory map structures address */

       Type::u32 drivesLength;  /*<< */
       Type::u32 drivesAddress; /*<< */
    };

    /**
     * Multiboot memory simplifaction.
     */
    struct Memory {
        Type::u32 lower; /*<< lower memory size in KB */
        Type::u32 upper; /*<< upper memory size in KB */
    };

    /**
     * Device abstraction.
     */
    struct Device {
        /**
         * Partition table abstraction.
         */
        struct Partition {
            Type::u8 subSubLevel; /*<< third level */
            Type::u8 subLevel;    /*<< second level */
            Type::u8 topLevel;    /*<< first level */
        } partition;

        Type::u8 BIOS; /*<< BIOS drive number */
    };

    /**
     * Module abstraction.
     */
    struct Module {
        Type::u32 start;
        Type::u32 end;
        Type::u32 string;
        Type::u32 reserved;
    };

    /**
     * Multiboot Modules list
     */
    struct Modules {
        Type::u32 length; /*<< modules list length */
        Module*   item;   /*<< modules list items */
    };

    /**
     *
     */
    struct Drive {};

  private:
    Boot::Info* _info;

  public:
    Boot (void* information);

    /**
     * Check if the memory addresses are valid.
     */
    bool validMemory (void);

    /**
     * Check if the boot device is valid.
     */
    bool validDevice (void);

    /**
     * Check if the modules list is valid.
     */
    bool validModules (void);

    /**
     * Check if the ELF symbol table is valid.
     */
    bool validELF (void);

    /**
     * Check if the mmap is valid.
     */
    bool validMmap (void);

    /**
     * If this is true, something went deeply wrong.
     */
    bool LOLNO (void);

    /**
     * Command line passed at boot time.
     */
    const char* command (void);

    /**
     * Device from where we're booting.
     */
    Boot::Device* device (void);

    /**
     * Boot memory bounds.
     */
    Boot::Memory* memory (void);

    /**
     * Boot modules.
     */
    Boot::Modules* modules (void);

  private:
    /**
     * Simple flag checking implementation.
     *
     * @param   flags   Flags variable.
     * @param   bit     Bit to check.
     *
     * @return  Flags' bit value.
     */
    bool _checkFlag (Type::u32 flags, char bit);
};

}

#endif
