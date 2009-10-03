/**
 * @file Process/State.h
 *
 * @brief Process State header
 */

#ifdef _LKEY_SCHEDULER_PROCESS_

class State
{
  public:
    static const Type::u8 Initializing;
    static const Type::u8 Ready;
    static const Type::u8 Suspended;
    static const Type::u8 Executing;
    static const Type::u8 Finished;

  private:
    Type::u8 _state;

  public:
    State (Type::u8 state = Initializing);
};

#endif
