/****************************************************************************
* Copyright (C) 2009 meh. [http://meh.doesntexist.org]                      *
*                                                                           *
* This file is part of lulzKey { life }.                                    *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifdef  _LIFE_PROCESS_H
#ifdef  _LIFE_PROCESS_THREAD_H
#ifndef _LIFE_PROCESS_THREAD_CONTEXT_H
#define _LIFE_PROCESS_THREAD_CONTEXT_H

class Context
{
  private:
    Type::u32 _eax;
    Type::u32 _ecx;
    Type::u32 _edx;
    Type::u32 _ebx;

    Type::u32 _esp;
    Type::u32 _ebp;
    Type::u32 _esi;
    Type::u32 _edi;

    Type::u32 _eflags;
    Type::u32 _eip;

    Type::u16 _cs;
    Type::u16 _ds;
    Type::u16 _ss;
    Type::u16 _es;
    Type::u16 _fs;
    Type::u16 _gs;

  public:
    Context (void);

    Context (
        Type::u32 eax, Type::u32 ecx, Type::u32 edx, Type::u32 ebx,
        Type::u32 esp, Type::u32 ebp, Type::u32 esi, Type::u32 edi,
        Type::u32 eflags, Type::u32 eip,
        Type::u16 cs, Type::u16 ds, Type::u16 ss, Type::u16 es, Type::u16 fs, Type::u16 gs
    );

    void      eax (Type::u32 eax);
    Type::u32 eax (void);

    void      ecx (Type::u32 ecx);
    Type::u32 ecx (void);

    void      edx (Type::u32 edx);
    Type::u32 edx (void);

    void      ebx (Type::u32 ebx);
    Type::u32 ebx (void);

    void      esp (Type::u32 esp);
    Type::u32 esp (void);

    void      ebp (Type::u32 ebp);
    Type::u32 ebp (void);

    void      esi (Type::u32 esi);
    Type::u32 esi (void);

    void      edi (Type::u32 edi);
    Type::u32 edi (void);

    void      eflags (Type::u32 eflags);
    Type::u32 eflags (void);

    void      eip (Type::u32 eip);
    Type::u32 eip (void);

    void      cs (Type::u16 cs);
    Type::u16 cs (void);

    void      ds (Type::u16 ds);
    Type::u16 ds (void);

    void      ss (Type::u16 ss);
    Type::u16 ss (void);

    void      es (Type::u16 es);
    Type::u16 es (void);

    void      fs (Type::u16 fs);
    Type::u16 fs (void);

    void      gs (Type::u16 gs);
    Type::u16 gs (void);
};

#endif
#endif
#endif
