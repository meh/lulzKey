/****************************************************************************
* Copyright (C) 2009 meh. [http://meh.doesntexist.org]                      *
*                                                                           *
* This file is part of lulzKey { life }.                                    *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifdef  _LIFE_PROCESS_H
#ifndef _LIFE_PROCESS_THREAD_H
#define _LIFE_PROCESS_THREAD_H

class Thread
{
  public:
    #include <Process/Thread/State.h>
    #include <Process/Thread/Context.h>

  private:
    Type::u32 _tid;
    Type::u32 _tid2;

    State   _state;
    Context _context;

  public:
    Thread (void);

    void      tid (Type::u32 pid);
    Type::u32 tid (void);

    void           state (State state);
    State state (void);

    void             context (Process::Context context);
    Process::Context context (void);
};

#endif
#endif
