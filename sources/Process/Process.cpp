/**
 * @file Process/Process.cpp
 *
 * @brief Process implementation
 */

#include <Process/Process.h>

namespace Kernel {

Process::Process (void)
{

}

void
Process::pid (Type::u32 pid)
{
    _pid = pid;
}

Type::u32
Process::pid (void)
{
    return _pid;
}

void
Process::state (Process::State state)
{
    _state = state;
}

Process::State
Process::state (void)
{
    return _state;
}

void
Process::context (Process::Context context)
{
    _context = context;
}

Process::Context
Process::context (void)
{
    return _context;
}

}

