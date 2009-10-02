#include <Tools/Shell.h>

namespace Kernel {

Shell::Shell (const void* address)
{
    _video    = (Type::uchar*) address;
    _line     = 0;
    _position = 0;
    _color    = FGBlack;
}

void
Shell::clear (void)
{
    for (Type::uchar i = 0; i < Shell::lines; i++) {
        for (Type::uchar h = 0; h < Shell::columns; h++) {
            _video[(i * Shell::columns) + (h * 2)]     = ' ';
            _video[(i * Shell::columns) + (h * 2) + 1] = 0x00;
        }
    }

    _line     = 0;
    _position = 0;
}

void
Shell::color (Shell::Color color)
{
    _color = color;
}

Shell::Color
Shell::color (void)
{
    return _color;
}

Type::uint
Shell::print (char out)
{
    Type::uint printed = 0;

    switch (out) {
        case '\t':
        printed = this->print("    ");
        break;

        case '\r':
        _position = 0;
        printed   = 1;
        break;

        case '\n':
        _position = 0;

        if (_line < Shell::lines-1) {
            _line++;
        }
        else {
            for (Type::uchar i = 1; i < Shell::lines; i++) {
                for (Type::uchar h = 0; h < Shell::columns; h++) {
                    _video[((i-1) * Shell::columns) + (h * 2)]     = _video[(i * Shell::columns) + h];
                    _video[((i-1) * Shell::columns) + (h * 2) + 1] = _video[(i * Shell::columns) + h + 1];
                }
            }

            for (Type::uchar i = 0; i < Shell::columns; i += 2) {
                _video[((Shell::lines-1) * Shell::columns) + i]     = ' ';
                _video[((Shell::lines-1) * Shell::columns) + i + 1] = 0x00;
            }
        }

        printed = 1;
        break;

        case '\b':
        if (_position > 0) {
            _video[(_line * Shell::columns) + (_position * 2)]     = ' ';
            _video[(_line * Shell::columns) + (_position * 2) + 1] = 0x00;

            _position--;
        }

        printed = 1;
        break;

        default:
        _video[(_line * Shell::columns) + (_position * 2)]     = out;
        _video[(_line * Shell::columns) + (_position * 2) + 1] = _color;

        _position++;
        printed = 1;
        break;
    }

    return printed;
}

Type::uint
Shell::print (const char* out)
{
    Type::uint printed = 0;

    for (Type::uint i = 0; out[i] != '\0'; i++) {
        printed += this->print(out[i]);
    }

    return printed;
}

Shell&
Shell::operator << (char out)
{
    this->print(out);
    return *this;
}

Shell& operator << (Shell& shell, const char* string)
{
    shell.print(string);
    return shell;
}

}

