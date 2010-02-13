/****************************************************************************
* lulzKey. Let's close those effin Windows so penguins won't enter.         *
*                                                                           *
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* lulzKey is free software: you can redistribute it and/or modify           *
* it under the terms of the GNU Affero General Public License as published  *
* by the Free Software Foundation, either version 3 of the License, or      *
* (at your option) any later version.                                       *
*                                                                           *
* lulzKey is distributed in the hope that it will be useful,                *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with lulzKey.  If not, see <http://www.gnu.org/licenses/>.          *
****************************************************************************/

#include <Interrupt/Interrupt.h>

namespace Kernel {

namespace Processor {

namespace Interrupts {

void init (void);

/**
 * System interrupts, only the god service can call them.
 *
 * 1 - disable paging                   { void (void) }
 * 2 - enable paging                    { void (void) }
 * 3 - set paging directory to the ebx  { void (physycal table address) }
 * 4 - flush TLB                        { void (void) }
 */
void system (Interrupt::Registers& regs);

}

}

}
