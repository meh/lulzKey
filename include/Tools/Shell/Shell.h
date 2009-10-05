/**
 * @file Tools/Shell.h
 *
 * @brief Kernel shell header
 */

#ifndef _LKEY_TOOLS_SHELL_H
#define _LKEY_TOOLS_SHELL_H

#include <Type.h>

namespace Kernel {

class Shell
{
  public:
    #include <Tools/Shell/Color.h>
    #include <Tools/Shell/OutputMode.h>

  public:
    static const Type::u16 VGA = 0x3D4;

    static const int Default = -1;

    static const unsigned char lines   = 25;
    static const unsigned char columns = 80;

    static const unsigned char endLine = '\n';

  private:
    unsigned char* _video;
    unsigned char  _y;
    unsigned char  _x;
    Shell::Color   _color;

  public:
    Shell (const void* address = (void*) 0xb8000);

    void clear (void);

    void moveCursor (char x, char y);

    void         color (Shell::Color color);
    void         color (char foreground, char background = Shell::Color::Black);
    Shell::Color color (void);

    unsigned int print (char out);
    unsigned int print (unsigned char out);

    unsigned int print (short out);
    unsigned int print (unsigned short out);

    unsigned int print (int out);
    unsigned int print (unsigned int out);

    unsigned int print (long out);
    unsigned int print (unsigned long out);

    unsigned int print (const void* out);

    unsigned int print (const char* out);

    unsigned int _binary      (unsigned long out);
    unsigned int _octal       (unsigned long out);
    unsigned int _hexadecimal (unsigned long out);

  public:
    Shell& operator << (Shell::Color color);

    Shell& operator << (char out);
    Shell& operator << (unsigned char out);

    Shell& operator << (short out);
    Shell& operator << (unsigned short out);

    Shell& operator << (int out);
    Shell& operator << (unsigned int out);

    Shell& operator << (long out);
    Shell& operator << (unsigned long out);

    Shell& operator << (const void* out);

    friend Shell& operator << (Shell& shell, const char* out);
};

}

#endif
