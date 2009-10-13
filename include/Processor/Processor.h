/****************************************************************************
* Copyright (C) 2009  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_PROCESSOR_H
#define _LKEY_PROCESSOR_H

/**
 * A correct ${ARC}/Process.h should have:
 *  struct Registers with all the registers to be saved from the context.
 *  struct InterruptRegisters with all the stuff pushed in by interrupts.
 *  void init (Multiboot& boot) to initialize what's needed with the boot data.
 */

#ifdef _LKEY_X86
#   include <Processor/x86/Processor.h>
#else
#   error "You didn't choose a supported architecture. Faggot."
#endif

#endif
