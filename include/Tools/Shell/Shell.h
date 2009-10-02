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

  public:
    static const Type::uchar  lines   = 25;
    static const Type::uchar  columns = 80;

    static const Type::uchar  endLine = '\n';

  private:
    Type::uchar* _video;
    Type::uchar  _line;
    Type::uchar  _position;
    Shell::Color _color;

  public:
    Shell (const void* address = (void*) 0xb8000);

    void clear (void);

    void         color (Shell::Color color);
    Shell::Color color (void);

    Type::uint print (char out);
    Type::uint print (const char* out);

  public:
    Shell& operator << (Shell::Color color);

    Shell& operator << (char out);
#if 0
    Shell& operator << (unsigned char out);

    Shell& operator << (short out);
    Shell& operator << (unsigned short out);

    Shell& operator << (int out);
    Shell& operator << (unsigned int out);

    Shell& operator << (long out);
    Shell& operator << (unsigned long out);

    Shell& operator << (float out);
    Shell& operator << (double out);

    Shell& operator << (const void* out);
#endif

    friend Shell& operator << (Shell& shell, const char* out);
};

}

#endif
