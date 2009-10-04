#include <Tools/Shell/Shell.h>

namespace Kernel {

Shell::Shell (const void* address)
{
    _video    = (unsigned char*) address;
    _line     = 0;
    _position = 0;
}

void
Shell::clear (void)
{
    for (unsigned char i = 0; i < Shell::lines; i++) {
        for (unsigned char h = 0; h < Shell::columns; h++) {
            _video[(i * 2 * Shell::columns) + (h * 2)]     = ' ';
            _video[(i * 2 * Shell::columns) + (h * 2) + 1] = 0x00;
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

void
Shell::color (char foreground, char background)
{
    _color = Color(foreground, background);
}

Shell::Color
Shell::color (void)
{
    return _color;
}

unsigned int
Shell::print (char out)
{
    return this->print((unsigned char) out);
}

unsigned int
Shell::print (unsigned char out)
{
    unsigned int printed = 0;

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
            for (unsigned char i = 1; i < Shell::lines; i++) {
                for (unsigned char h = 0; h < Shell::columns; h++) {
                    _video[((i-1) * 2 * Shell::columns) + (h * 2)]     = _video[(i * Shell::columns) + (h * 2)];
                    _video[((i-1) * 2 * Shell::columns) + (h * 2) + 1] = _video[(i * Shell::columns) + (h * 2) + 1];
                }
            }

            for (unsigned char i = 0; i < Shell::columns; i += 2) {
                _video[((Shell::lines-1) * 2 * Shell::columns) + (i * 2)]     = ' ';
                _video[((Shell::lines-1) * 2 * Shell::columns) + (i * 2) + 1] = 0x00;
            }
        }

        printed = 1;
        break;

        case '\b':
        if (_position > 0) {
            _video[(_line * 2 * Shell::columns) + (_position * 2)]     = ' ';
            _video[(_line * 2 * Shell::columns) + (_position * 2) + 1] = 0x00;

            _position--;
        }

        printed = 1;
        break;

        default:
        if (_position == Shell::columns) {
            this->print('\n');
        }

        _video[(_line * 2 * Shell::columns) + (_position * 2)]     = out;
        _video[(_line * 2 * Shell::columns) + (_position * 2) + 1] = _color.value();

        _position++;
        printed = 1;
        break;
    }

    return printed;
}

unsigned int
Shell::print (short out)
{
    unsigned int printed;

    if (out < 0) {
        printed = this->print('-') + this->print((unsigned long) -out);
    }
    else {
        printed = this->print((unsigned long) -out);
    }

    return printed;
}

unsigned int
Shell::print (unsigned short out)
{
    return this->print((unsigned long) out);
}

unsigned int
Shell::print (int out)
{
    unsigned int printed;

    if (out < 0) {
        printed = this->print('-') + this->print((unsigned long) -out);
    }
    else {
        printed = this->print((unsigned long) -out);
    }

    return printed;
}

unsigned int
Shell::print (unsigned int out)
{
    return this->print((unsigned long) out);
}

unsigned int
Shell::print (long out)
{
    unsigned int printed;

    if (out < 0) {
        printed = this->print('-') + this->print((unsigned long) -out);
    }
    else {
        printed = this->print((unsigned long) -out);
    }

    return printed;
}

unsigned int
Shell::print (unsigned long out)
{
    char output[21] = {0};
    int  count      = 0;

    do {
        output[count] = out % 10;
        out           = out / 10;
        count++;
    } while (out > 0);

    for (int i = count-1; i >= 0; i--) {
        this->print((char) (output[i] + 0x30));
    }

    return count;
}

unsigned int
Shell::print (const void* out)
{
    return _hexadecimal((unsigned long) out);
}


unsigned int
Shell::print (const char* out)
{
    unsigned int printed = 0;

    for (unsigned int i = 0; out[i] != '\0'; i++) {
        printed += this->print(out[i]);
    }

    return printed;
}

Shell&
Shell::operator << (Shell::Color color)
{
    this->color(color);
    return *this;
}

Shell&
Shell::operator << (char out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (unsigned char out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (short out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (unsigned short out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (int out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (unsigned int out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (long out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (unsigned long out)
{
    this->print(out);
    return *this;
}

Shell&
Shell::operator << (const void* out)
{
    this->print(out);
    return *this;
}

Shell& operator << (Shell& shell, const char* string)
{
    shell.print(string);
    return shell;
}

unsigned int
Shell::_binary (unsigned long out)
{
    unsigned long filter = 0x80000000;

    for (int i = 0; i < 32; i++) {
        if (filter & out) {
            this->print('1');
        }
        else {
            this->print('0');
        }
        filter >>= 1;
    }

    return 32;
}

unsigned int
Shell::_octal (unsigned long out)
{
    int           shift    = 30;
    unsigned int  returned = 0;
    unsigned long filter   = 0xC0000000;
    char          cipher;

    returned += this->print('0');
    cipher    = ((filter & out) >> shift);

    if (cipher != 0) {
        returned += this->print((char) (cipher + '0'));
    }

    filter = 0x38000000;
    shift -= 3;
    cipher = ((filter & out) >> shift);

    while (cipher == 0 && shift > 0) {
        filter >>= 3;
        shift   -= 3;
        cipher   = ((filter & out) >> shift);
    }

    while (shift > 0) {
        returned += this->print((char) (cipher + '0'));
        filter >>= 3;
        shift   -= 3;
        cipher   = ((filter & out) >> shift);
    }

    returned += this->print((char) (cipher + '0'));

    return returned;
}

unsigned int
Shell::_hexadecimal (unsigned long out)
{
    int           shift    = 28;
    unsigned int  returned = 0;
    unsigned long filter   = 0xf0000000;
    char          cipher;

    returned += this->print('0');
    returned += this->print('x');

    cipher = ((filter & out) >> shift);

    while (cipher == 0 && shift > 0) {
        filter >>= 4;
        shift   -= 4;
        cipher   = ((filter & out) >> shift);
    }

    while (shift > 0) {
        if (cipher < 10) {
            returned += this->print((char) (cipher + '0'));
        }
        else {
            returned += this->print((char) (cipher - 10 + 'a'));
        }
        shift   -= 4;
        filter >>= 4;
        cipher   = ((filter & out) >> shift);
    }

    if (cipher < 10) {
        returned += this->print((char) (cipher + '0'));
    }
    else {
        returned += this->print((char) (cipher - 10 + 'a'));
    }

    return returned;
}

}
