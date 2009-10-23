/****************************************************************************
* Copyright (C) 2009 meh. [http://meh.doesntexist.org]                      *
*                                                                           *
* This file is part of lulzKey { life }.                                    *
*                                                                           *
* See COPYING or http://www.gnu.org/licenses/agpl-3.0.txt                   *
****************************************************************************/

#ifdef  _LIFE_PROCESS_H

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
