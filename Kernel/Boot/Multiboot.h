/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

/**
 * @file Boot/Multiboot.h
 *
 * @brief Multiboot-compliant class and structs.
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
 * Multiboot compliant class.
 *
 * Class used to simplify and abstract the multiboot specification:
 * http://www.gnu.org/software/grub/manual/multiboot/
 */
class Multiboot
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
        Type::u32 flags;          /*<< multiboot flags */

        Type::u32 memLower;       /*<< low memory size in KB */
        Type::u32 memUpper;       /*<< high memory size in KB */

        Type::u32 bootDevice;     /*<< boot device informations */ 

        Type::u32 command;        /*<< command line passed through the boot loader */

        Type::u32 modulesCount;   /*<< modules count */
        Type::u32 modulesAddress; /*<< modules array address */

        /**
         * ELF symbols table.
         */
        struct {
            Type::u32 num;
            Type::u32 size;
            Type::u32 address;
            Type::u32 shndx;
        } ELF;

        Type::u32 mmapLength;     /*<< memory map structures length */
        Type::u32 mmapAddress;    /*<< memory map structures address */

        Type::u32 drivesLength;   /*<< drives array length */
        Type::u32 drivesAddress;  /*<< drives array address */

        Type::u32 configTable;    /*<< address of the ROM configuration table returned by the GET CONFIGURATION bios  call */

        Type::u32 bootLoader;     /*<< boot loader name */

        Type::u32 APMTable;       /*<< Advanced Power Management table */

        Type::u32 graphicsTable;  /*<< VESA BIOS Extensions table */
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
     *
     * Dump of the whole file in memory.
     * So basically just read with the ELF header the init symbol and call it.
     */
    struct Module {
        Type::u32 start;    /*<< start address */
        Type::u32 end;      /*<< end address */
        Type::u32 string;   /*<< string associated with the module */
        Type::u32 reserved;
    };

    /**
     * Multiboot Modules list
     */
    struct Modules {
        Type::u32 length; /*<< modules list length */
        Module**  item;   /*<< modules list items */
    };

    /**
     * Memory map abstraction.
     */
    struct MemoryMap {
        Type::u32 baseAddressLow;
        Type::u32 baseAddressHigh;
        Type::u32 lengthLow;
        Type::u32 lengthHigh;
        Type::u32 type;
    };

    /**
     * Memory map list.
     */
    struct MemoryMaps {
        Type::u32   length;
        MemoryMap** item;
    };

    /**
     * Drive abstraction.
     */
    struct Drive {
        Type::u32 size;      /*<< size of the struct */
        Type::u8  number;    /*<< BIOS drive numbe */

        /**
         * Access mode:
         * 0: CHS mode (traditional cylinder/head/sector addressing mode). 
         * 1: LBA mode (Logical Block Addressing mode).
         */
        Type::u8 mode;

        Type::u16 cylinders; /*<< drive's cylinders */
        Type::u8  heads;     /*<< drive's heads */
        Type::u8  sectors;   /*<< drive's sectors */

        Type::u16* ports;    /*<< I/O ports array, ends with a 0 */
    };

    /**
     * Drive list.
     */
    struct Drives {
        Type::u32 size;
        Drive*    first;
    };

    /**
     * Advanced Power Management table
     */
    struct APM {
        Type::u16 version;             /*<< version number */
        Type::u16 codeSegment;         /*<< protected mode 32-bit code segment */
        Type::u32 offset;              /*<< offset of the entry point */
        Type::u16 codeSegment16;       /*<< protected mode 16-bit code segment */
        Type::u16 dataSegment;         /*<< protected mode 16-bit data segment */
        Type::u16 flags;               /*<< flags? */
        Type::u16 codeSegmentLength;   /*<< length of the protected mode 32-bit code segment */
        Type::u16 codeSegment16Length; /*<< length of the protected mode 16-bit code segment */
        Type::u16 dataSegmentLength;   /*<< ength of the protected mode 16-bit data segment */
    };

    /**
     * VESA BIOS Extensions table
     */
    struct VBE {
        Type::u32 controlInfo;      /*<< physical addresses of VBE control information returned by the VBE Function 00h */
        Type::u32 modeInfo;         /*<< VBE mode information returned by the VBE Function 01h */
        Type::u16 mode;             /*<< current video mode in the format specified in vbe 3.0 */
        Type::u16 interfaceSegment; /*<< segment of a protected mode interface defined in VBE 2.0+ */
        Type::u16 interfaceOffset;  /*<< offset of a protected mode interface defined in VBE 2.0+ */
        Type::u16 interfaceLength;  /*<< length of a protected mode interface defined in VBE 2.0+ */
    };

  private:
    Info* _info;

  public:
    /**
     * Create the Boot object.
     *
     * @param   information     Address to the Multiboot header.
     */
    Multiboot (void* information);

    /**
     * Memory bounds.
     */
    Memory* memory (void);

    /**
     * Device from where we're booting.
     */
    Device* device (void);

    /**
     * Command line passed at boot time.
     */
    const char* command (void);

    /**
     * Boot modules.
     */
    Modules* modules (void);
    void     modules (void (*function)(Module*));

    /**
     * Memory maps infos.
     */
    MemoryMaps* memoryMaps (void);

    /**
     * Drives list.
     */
    Drives* drives (void);
    void    drives (void (*function)(Drive*));

    /**
     * BIOS config table.
     */
    void* configTable (void);

    /**
     * Boot loader name.
     */
    const char* bootLoader (void);

    /**
     * APM table.
     */
    APM* APMTable (void);

    /**
     * VBE table.
     */
    VBE* graphicsTable (void);
};

}

#endif
