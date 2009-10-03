/**
 * @file Process/State.cpp
 *
 * @brief Process State implementation
 */

#include <Process/Process.h>

namespace Kernel {

Process::State::State (Type::u8 state)
{
    _state = state;
}

}
