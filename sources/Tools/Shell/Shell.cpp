/****************************************************************************
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#include <string.h>

#include <Tools/Shell/Shell.h>
#include <Misc/IO.h>

namespace Kernel {

Shell* Shell::_object = NULL;

Shell::Shell (const void* address)
{
    if (!Shell::_object) {
        _video = (Type::u8*) address;
        _y     = 0;
        _x     = 0;

        Shell::_object = this;
        this->clear();
    }
}

void
Shell::clear (void)
{
    Color tmp = _color;
    _color    = Color();

    for (Type::u8 y = 0; y < Shell::lines; y++) {
        for (Type::u8 x = 0; x < Shell::columns; x++) {
            Shell::_object->_video[(x + y * Shell::columns) * 2]     = ' ';
            Shell::_object->_video[(x + y * Shell::columns) * 2 + 1] = 0x00;
        }
    }

    Shell::_object->_y = 0;
    Shell::_object->_x = 0;

    this->moveCursor(Shell::_object->_x, Shell::_object->_y);

    _color = tmp;
}

void
Shell::scroll (Type::u32 lines)
{
    for (Type::u8 y = lines; y < Shell::lines; y++) {
        for (Type::u8 x = 0; x < Shell::columns; x++) {
            Shell::_object->_video[(x + (y - 1) * Shell::columns) * 2]     = Shell::_object->_video[(x + y * Shell::columns) * 2];
            Shell::_object->_video[(x + (y - 1) * Shell::columns) * 2 + 1] = Shell::_object->_video[(x + y * Shell::columns) * 2 + 1];
        }
    }

    for (Type::u8 y = Shell::lines; y > Shell::lines - lines; y--) {
        for (Type::u8 x = 0; x < Shell::columns; x++) {
            Shell::_object->_video[(x + (y-1) * Shell::columns) * 2]     = ' ';
            Shell::_object->_video[(x + (y-1) * Shell::columns) * 2 + 1] = 0x00;
        }
    }
}

void
Shell::moveCursor (char x, char y)
{
    Shell::_object->_video[(x + y * Shell::columns) * 2 + 1] = _color.value();

    Misc::out(Shell::VGA,   (Type::u8) 14);
    Misc::out(Shell::VGA+1, (Type::u8) ((x + y * Shell::columns) >> 8));
    Misc::out(Shell::VGA,   (Type::u8) 15);
    Misc::out(Shell::VGA+1, (Type::u8) (x + y * Shell::columns));
}

void
Shell::color (Shell::Color& color)
{
    _color = color;
}

void
Shell::color (char foreground, char background, bool blinking)
{
    _color = Color(foreground, background, blinking);
}

Shell::Color&
Shell::color (void)
{
    return _color;
}

Type::u32
Shell::printf (const char* message, ...)
{
    va_list   args;
    Type::u32 printed;

    va_start(args, message);

    printed = this->printf(message, args);

    va_end(args);

    return printed;
}

Type::u32
Shell::printf (const char* message, va_list args)
{
    Type::u32 printed = 0;
    size_t    length  = strlen(message);

    for (size_t i = 0; i < length; i++) {
        if (message[i] == '%') {
            i++;

            if (message[i] == 'd') {
                this->print(va_arg(args, int));
            }
            else if (message[i] == 's') {
                this->print(va_arg(args, const char*));
            }
            else if (message[i] == 'x') {
                this->_hexadecimal(va_arg(args, unsigned long));
            }
            else if (message[i] == 'b') {
                this->_binary(va_arg(args, unsigned long));
            }
        }
        else {
            this->print(message[i]);
        }
    }

    return printed;
}

Type::u32
Shell::print (char out)
{
    return this->print((Type::u8) out);
}

Type::u32
Shell::print (unsigned char out)
{
    Type::u32 printed = 0;

    switch (out) {
        case '\t':
        printed = this->print("    ");
        break;

        case '\r':
        Shell::_object->_x = 0;
        printed   = 1;
        break;

        case '\n':
        Shell::_object->_x = 0;

        if (Shell::_object->_y < Shell::lines-1) {
            Shell::_object->_y++;
        }
        else {
            this->scroll();
        }

        printed = 1;
        break;

        case '\b':
        if (Shell::_object->_x > 0) {
            Shell::_object->_video[(Shell::_object->_x + Shell::_object->_y * Shell::columns) * 2]     = ' ';
            Shell::_object->_video[(Shell::_object->_x + Shell::_object->_y * Shell::columns) * 2 + 1] = 0x00;

            Shell::_object->_x--;
        }

        printed = 1;
        break;

        default:
        if (Shell::_object->_x == Shell::columns) {
            this->print('\n');
        }

        Shell::_object->_video[(Shell::_object->_x + Shell::_object->_y * Shell::columns) * 2]     = out;
        Shell::_object->_video[(Shell::_object->_x + Shell::_object->_y * Shell::columns) * 2 + 1] = _color.value();

        Shell::_object->_x++;
        printed = 1;
        break;
    }

    this->moveCursor(Shell::_object->_x, Shell::_object->_y);

    return printed;
}

Type::u32
Shell::print (short out)
{
    Type::u32 printed;

    if (out < 0) {
        printed = this->print('-') + this->print((unsigned long) -out);
    }
    else {
        printed = this->print((unsigned long) out);
    }

    return printed;
}

Type::u32
Shell::print (unsigned short out)
{
    return this->print((unsigned long) out);
}

Type::u32
Shell::print (int out)
{
    Type::u32 printed;

    if (out < 0) {
        printed = this->print('-') + this->print((unsigned long) -out);
    }
    else {
        printed = this->print((unsigned long) out);
    }

    return printed;
}

Type::u32
Shell::print (unsigned int out)
{
    return this->print((unsigned long) out);
}

Type::u32
Shell::print (long out)
{
    Type::u32 printed;

    if (out < 0) {
        printed = this->print('-') + this->print((unsigned long) -out);
    }
    else {
        printed = this->print((unsigned long) out);
    }

    return printed;
}

Type::u32
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

Type::u32
Shell::print (const void* out)
{
    Type::u32 tmp = this->print("0x");

    return tmp + _hexadecimal((unsigned long) out);
}


Type::u32
Shell::print (const char* out)
{
    Type::u32 printed = 0;

    for (Type::u32 i = 0; out[i] != '\0'; i++) {
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

Type::u32
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

Type::u32
Shell::_octal (unsigned long out)
{
    int           shift    = 30;
    Type::u32  returned = 0;
    unsigned long filter   = 0xC0000000;
    char          cipher;

    cipher = ((filter & out) >> shift);

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

Type::u32
Shell::_hexadecimal (unsigned long out)
{
    int           shift    = 28;
    Type::u32     returned = 0;
    unsigned long filter   = 0xf0000000;
    char          cipher;

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
