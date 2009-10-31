/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_KERNEL_H
#define _LKEY_KERNEL_H

#define KERNEL_LEVEL  0
#define SERVICE_LEVEL 1
#define USER_LEVEL    3

#include <Tools/Shell/Shell.h>

namespace Kernel {

extern Shell shell;

void panic (const char* message, ...);

}

#endif
