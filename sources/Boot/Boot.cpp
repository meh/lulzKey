#include <Boot/Boot.h>

namespace Kernel {

Boot::Boot (void* information)
{
    _info = (Info*) information;
}

const char*
Boot::command (void)
{
    return (const char*) _info->command;
}

}
