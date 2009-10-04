/**
 * @file Process/Process.h
 *
 * @brief Process header
 *
 * @see Kernel::Process::Context
 * @see Kernel::Process::State
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

    void      pid (Type::u32 pid);
    Type::u32 pid (void);

    void           state (Process::State state);
    Process::State state (void);

    void             context (Process::Context context);
    Process::Context context (void);
};

}

#endif
