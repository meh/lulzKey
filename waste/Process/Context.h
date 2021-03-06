/****************************************************************************
 * lulzKey. Let's close those effin Windows so penguins won't enter.        *
 *                                                                          *
 * Copyright (C) 2009  meh. [http://meh.doesntexist.org]                    *
 *                                                                          *
 * This program is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 ****************************************************************************/

/**
 * @file Process/Context.h
 *
 * @brief Process Context header.
 */

#ifdef _LKEY_SCHEDULER_PROCESS_

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
