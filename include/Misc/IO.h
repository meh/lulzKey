/**
 * @file Misc/IO.h
 *
 * @brief Low level input and output functions.
 */

#ifndef _LKEY_MISC_IO_H
#define _LKEY_MISC_IO_H

#include <Type.h>

namespace Kernel {

namespace Misc {

static const Type::u8  Byte = 0x1;
static const Type::u16 Word = 0x2;
static const Type::u32 Long = 0x4;

static inline void     out (Type::u16 port, Type::u8 value);
static inline Type::u8 in  (Type::u16 port, Type::u8 type);

static inline void      out (Type::u16 port, Type::u16 value);
static inline Type::u16 in  (Type::u16 port, Type::u16 type);

static inline void      out (Type::u16 port, Type::u32 value);
static inline Type::u32 in  (Type::u16 port, Type::u32 type);

}

}

#endif
