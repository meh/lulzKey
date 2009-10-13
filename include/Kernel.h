/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_KERNEL_H
#define _LKEY_KERNEL_H

#include <Tools/Shell/Shell.h>

namespace Kernel {

extern Shell shell;

void panic (const char* message);

}

#endif
