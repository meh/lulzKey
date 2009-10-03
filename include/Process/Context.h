/**
 * @file Process/Context.h
 *
 * @brief Process Context header.
 */

#ifdef _LKEY_SCHEDULER_PROCESS_

class Context
{
  public:
    struct Flags {
        unsigned carry                   : 1;
        unsigned __1                     : 1;
        unsigned parity                  : 1;
        unsigned __2                     : 1;
        unsigned adjust                  : 1;
        unsigned __3                     : 1;
        unsigned zero                    : 1;
        unsigned sign                    : 1;
        unsigned trap                    : 1;
        unsigned interrupt               : 1;
        unsigned direction               : 1;
        unsigned overflow                : 1;
        unsigned ioPrivilege             : 2;
        unsigned nestedTask              : 1;
        unsigned __4                     : 1;
        unsigned resume                  : 1;
        unsigned virtualMode             : 1;
        unsigned alignmentCheck          : 1;
        unsigned virtualInterruptFlag    : 1;
        unsigned virtualInterruptPending : 1;
        unsigned identification          : 1;
    };

  private:
    Type::u32 _eax;
    Type::u32 _ecx;
    Type::u32 _edx;
    Type::u32 _ebx;

    Type::u32 _esp;
    Type::u32 _ebp;
    Type::u32 _esi;
    Type::u32 _edi;

    Flags     _eflags;
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
        Flags eflags, Type::u32 eip,
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

    Flags eflags (Flags eflags);
    Flags eflags (void);

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
