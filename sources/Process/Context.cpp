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

    _eflags = (Process::Context::Flags) 0;
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
    Process::Context::Flags eflags, Type::u32 eip,
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
eflags (Process::Context::Flags eflags)
{
    _eflags = eflags;
}

Process::Context::Flags
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

