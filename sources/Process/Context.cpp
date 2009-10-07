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

#include <Process/Process.h>

namespace Kernel {

Process::Context::Context (void)
{
    _eax = 0;
    _ecx = 0;
    _edx = 0;
    _ebx = 0;

    _esp = 0;
    _ebp = 0;
    _esi = 0;
    _edi = 0;

    _eflags = 0;
    _eip    = 0;

    _cs = 0;
    _ds = 0;
    _ss = 0;
    _es = 0;
    _fs = 0;
    _gs = 0;
}

Process::Context::Context(
    Type::u32 eax, Type::u32 ecx, Type::u32 edx, Type::u32 ebx,
    Type::u32 esp, Type::u32 ebp, Type::u32 esi, Type::u32 edi,
    Type::u32 eflags, Type::u32 eip,
    Type::u16 cs, Type::u16 ds, Type::u16 ss, Type::u16 es, Type::u16 fs, Type::u16 gs)
{
    _eax = eax;
    _ecx = ecx;
    _edx = edx;
    _ebx = ebx;

    _esp = esp;
    _ebp = ebp;
    _esi = esi;
    _edi = edi;

    _eflags = eflags;
    _eip    = eip;

    _cs = cs;
    _ds = ds;
    _ss = ss;
    _es = es;
    _fs = fs;
    _gs = gs;
}

void
Process::Context::eax (Type::u32 eax)
{
    _eax = eax;
}

Type::u32
Process::Context::eax (void)
{
    return _eax;
}

void
Process::Context::ecx (Type::u32 ecx)
{
    _ecx = ecx;
}

Type::u32
Process::Context::ecx (void)
{
    return _ecx;
}

void
Process::Context::edx (Type::u32 edx)
{
    _edx = edx;
}

Type::u32
Process::Context::edx (void)
{
    return _edx;
}

void
Process::Context::ebx (Type::u32 ebx)
{
    _ebx = ebx;
}

Type::u32
Process::Context::ebx (void)
{
    return _ebx;
}

void
Process::Context::esp (Type::u32 esp)
{
    _esp = esp;
}

Type::u32
Process::Context::esp (void)
{
    return _esp;
}

void
Process::Context::ebp (Type::u32 ebp)
{
    _ebp = ebp;
}

Type::u32
Process::Context::ebp (void)
{
    return _ebp;
}

void
Process::Context::esi (Type::u32 esi)
{
    _esi = esi;
}

Type::u32
Process::Context::esi (void)
{
    return _esi;
}

void
Process::Context::edi (Type::u32 edi)
{
    _edi = edi;
}

Type::u32
Process::Context::edi (void)
{
    return _edi;
}

void
Process::Context::eflags (Type::u32 eflags)
{
    _eflags = eflags;
}

Type::u32
Process::Context::eflags (void)
{
    return _eflags;
}

void
Process::Context::eip (Type::u32 eip)
{
    _eip = eip;
}

Type::u32
Process::Context::eip (void)
{
    return _eip;
}

void
Process::Context::cs (Type::u16 cs)
{
    _cs = cs;
}

Type::u16
Process::Context::cs (void)
{
    return _cs;
}

void
Process::Context::ds (Type::u16 ds)
{
    _ds = ds;
}

Type::u16
Process::Context::ds (void)
{
    return _ds;
}

void
Process::Context::ss (Type::u16 ss)
{
    _ss = ss;
}

Type::u16
Process::Context::ss (void)
{
    return _ss;
}

void
Process::Context::es (Type::u16 es)
{
    _es = es;
}

Type::u16
Process::Context::es (void)
{
    return _es;
}

void
Process::Context::fs (Type::u16 fs)
{
    _fs = fs;
}

Type::u16
Process::Context::fs (void)
{
    return _fs;
}

void
Process::Context::gs (Type::u16 gs)
{
    _gs = gs;
}

Type::u16
Process::Context::gs (void)
{
    return _gs;
}

}

