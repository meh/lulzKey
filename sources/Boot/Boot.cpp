#include <Boot/Boot.h>

namespace Kernel {

Boot::Boot (void* information)
{
    _info = (Info*) information;
}

bool
Boot::validMemory (void)
{
    return _checkFlag(_info->flags, 0);
}

bool
Boot::validDevice (void)
{
    return _checkFlag(_info->flags, 1);
}

bool
Boot::validModules (void)
{
    return _checkFlag(_info->flags, 3);
}

bool
Boot::validELF (void)
{
    return _checkFlag(_info->flags, 5);
}

bool
Boot::validMmap (void)
{
    return _checkFlag(_info->flags, 6);
}

bool
Boot::LOLNO (void)
{
    return _checkFlag(_info->flags, 4) && _checkFlag(_info->flags, 5);
}

const char*
Boot::command (void)
{
    if (_checkFlag(_info->flags, 2)) {
        return (const char*) _info->command;
    }
    else {
        return (const char*) NULL;
    }
}

Boot::Device*
Boot::device (void)
{
    return (Boot::Device*) _info->bootDevice;
}

Boot::Memory*
Boot::memory (void)
{
    return (Boot::Memory*) &_info->memLower;
}

Boot::Modules*
Boot::modules (void)
{
    return (Boot::Modules*) &_info->modulesCount;
}

bool
Boot::_checkFlag (Type::u32 flags, char bit)
{
    return (flags) & (1 << (bit));
}

}
