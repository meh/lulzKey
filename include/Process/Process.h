/**
 * @file Process/Process.h
 *
 * @brief Process header
 */

#ifndef _LKEY_SCHEDULER_PROCESS_
#define _LKEY_SCHEDULER_PROCESS_

#include <Type.h>

namespace Kernel {

class Process
{
  public:
    #include <Process/State.h>
    #include <Process/Context.h>

  private:
    Type::u32        _pid;
    Process::State   _state;
    Process::Context _context;

  public:
    Process (void);
};

}

#endif
