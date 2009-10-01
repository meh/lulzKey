/**
 * @file Type.h
 *
 * @brief Default kernel types.
 */

#ifndef _LKEY_TYPE_H
#define _LKEY_TYPE_H

namespace Type {
    typedef unsigned char uchar;
    typedef unsigned int  uint;
    typedef unsigned long ulong;

    typedef struct MultiBoot {
        Type::ulong magic;
        Type::ulong flags;
        Type::ulong checksum;
        Type::ulong headerAddress;
        Type::ulong loadAddress;
        Type::ulong loadEndAddress;
        Type::ulong bssEndAddress;
        Type::ulong entryAddress;
    } MultiBoot;
}

#define NULL ((void*) 0)

#endif
