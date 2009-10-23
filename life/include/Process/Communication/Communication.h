/****************************************************************************
* Copyright (C) 2009 meh. [http://meh.doesntexist.org]                      *
*                                                                           *
* This file is part of lulzKey { life }.                                    *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifdef  _LIFE_PROCESS_H
#ifndef _LIFE_PROCESS_COMMUNICATION_H
#define _LIFE_PROCESS_COMMUNICATION_H

class Communication
{
  public:
    #include <Process/Communication/Message.h>
    #include <Process/Communication/Mailbox.h>

  public:
    Communication (Type::u32 pid, Type::u16 port);
    Communication (const char* name, Type::u16 port);

    bool send (void* message, Type::u32 size, bool blocking = false);
    Message* receive (bool blocking = true);

    static bool sendTo (Type::u32 pid, Type::u16 port, void* message, Type::u32 size, bool blocking = false);
    static bool sendTo (const char* name, Type::u16 port, void* message, Type::u32 size, bool blocking = false);
    static bool sendTo (Message* message, bool blocking = false);

    static Message* receiveFrom (Type::u16 port, bool blocking = true);
};

#endif
#endif
