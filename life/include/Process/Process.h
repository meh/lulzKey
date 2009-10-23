/****************************************************************************
* Copyright (C) 2009 meh. [http://meh.doesntexist.org]                      *
*                                                                           *
* This file is part of lulzKey { life }.                                    *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifndef _LIFE_PROCESS_H
#define _LIFE_PROCESS_H

#include <Type.h>
#include <List.h>

class Process
{
  public:
    #include <Process/Communication/Communication.h>
    #include <Process/Context.h>
    #include <Process/Thread/Thread.h>

  private:
    Type::u32 _pid;
    Type::u32 _pid2;
    
    char* _name;

    Context _context;

    List<Thread> _threads;

  public:
    Process (const char* name);

    void      pid (Type::u32 pid);
    Type::u32 pid (void);

    void             context (Process::Context context);
    Process::Context context (void);

    Type::u32 hash (const char* string);
};

#endif
