/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _SERVICES_LIB_SERVICE_H
#define _SERVICES_LIB_SERVICE_H

#include <Type.h>

namespace Service {

struct Info {
    const char* name;
    Type::u8    priority;
};

}

#endif
