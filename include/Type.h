/**
 * @file Type.h
 *
 * @brief Default kernel types.
 */

#ifndef _LKEY_TYPE_H
#define _LKEY_TYPE_H

namespace Type {
    typedef u8  unsigned char;
    typedef u16 unsigned short;
    typedef u32 unsigned int;
    typedef u64 unsigned long long;

    struct MultiBoot {
        Type::ulong magic;
        Type::ulong flags;
        Type::ulong checksum;
        Type::ulong headerAddress;
        Type::ulong loadAddress;
        Type::ulong loadEndAddress;
        Type::ulong bssEndAddress;
        Type::ulong entryAddress;
    };
}

#define NULL ((void*) 0)

#endif
