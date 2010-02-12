/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LKEY_INTERRUPT_REQUEST_H
#define _LKEY_INTERRUPT_REQUEST_H

#define IRQ(n) __irq## n
#define DEFINE_IRQ(n) extern "C" void __irq##n ()

DEFINE_IRQ(0);
DEFINE_IRQ(1);
DEFINE_IRQ(2);
DEFINE_IRQ(3);
DEFINE_IRQ(4);
DEFINE_IRQ(5);
DEFINE_IRQ(6);
DEFINE_IRQ(7);
DEFINE_IRQ(8);
DEFINE_IRQ(9);
DEFINE_IRQ(10);
DEFINE_IRQ(11);
DEFINE_IRQ(12);
DEFINE_IRQ(13);
DEFINE_IRQ(14);
DEFINE_IRQ(15);

#endif
