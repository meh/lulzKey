/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_DEBUG_H
#define _LKEY_DEBUG_H

#include <Boot/Multiboot.h>

namespace Kernel {

namespace Debug {

void dump (Multiboot& boot);

}

}

#endif
