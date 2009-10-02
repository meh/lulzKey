#include <Tools/Shell/Shell.h>

namespace Kernel {

Shell::Color::Color (char foreground, char background)
{
    _foreground = foreground;
    _background = background;
}

char
Shell::Color::foreground (void)
{
    return _foreground;
}

void
Shell::Color::foreground (char color)
{
    _foreground = color;
}

char
Shell::Color::background (void)
{
    return _background;
}

void
Shell::Color::background (char color)
{
    _background = color;
}

unsigned char
Shell::Color::value (void)
{
    return (this->background() * 16) + this->foreground();
}

}
