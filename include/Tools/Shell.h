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
    typedef enum Color {
        FGBlack  = 0x0,
        FGYellow = 0xE,
        FGPink   = 0xD,
        FGWhite  = 0xF,

        BGBlack  = 0x00
    } Color;

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
    Shell& operator << (char out);
#if 0
    inline Shell& operator << (unsigned char out);

    inline Shell& operator << (short out);
    inline Shell& operator << (unsigned short out);

    inline Shell& operator << (int out);
    inline Shell& operator << (unsigned int out);

    inline Shell& operator << (long out);
    inline Shell& operator << (unsigned long out);

    inline Shell& operator << (float out);
    inline Shell& operator << (double out);

    inline Shell& operator << (const void* out);
#endif

    friend Shell& operator << (Shell& shell, const char* out);
};

}

#endif
