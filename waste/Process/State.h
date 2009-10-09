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
