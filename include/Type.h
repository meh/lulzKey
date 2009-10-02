/**
 * @file Type.h
 *
 * @brief Default kernel types.
 */

#ifndef _LKEY_TYPE_H
#define _LKEY_TYPE_H

namespace Type {
    typedef unsigned char      u8;
    typedef unsigned short     u16;
    typedef unsigned int       u32;
    typedef unsigned long long u64;

    struct MultiBoot {
        unsigned long magic;
        unsigned long flags;
        unsigned long checksum;
        unsigned long headerAddress;
        unsigned long loadAddress;
        unsigned long loadEndAddress;
        unsigned long bssEndAddress;
        unsigned long entryAddress;
    };
}

#define NULL ((void*) 0)

#endif
