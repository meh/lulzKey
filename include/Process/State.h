/**
 * @file Process/State.h
 *
 * @brief Process State header
 */

#ifdef _LKEY_SCHEDULER_PROCESS_

class State
{
  public:
    static const Type::u8 Initializing = 0x01;
    static const Type::u8 Ready        = 0x02;
    static const Type::u8 Suspended    = 0x04;
    static const Type::u8 Executing    = 0x08;
    static const Type::u8 Finished     = 0x10;

  private:
    Type::u8 _state;

  public:
    State (Type::u8 state = State::Initializing);
};

#endif
