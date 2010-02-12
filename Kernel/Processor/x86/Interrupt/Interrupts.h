/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
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
