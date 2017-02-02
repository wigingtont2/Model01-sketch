/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016, 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Leader.h"

#include <Keyboardio-Macros.h>
#include <Keyboardio-LEDControl.h>
#include <Akela-Unicode.h>
#include <Akela-Syster.h>
#include <Akela-LangPack-Hungarian.h>

#include "Macros.h"

using namespace Akela::LangPack;

namespace algernon {
  namespace Leader {

    // Leaders
    enum {
      LEAD_UNICODE_UCIS,

      LEAD_CSILLA,
      LEAD_GERGO,
      LEAD_YAY,
      LEAD_SHRUGGY,

      LEAD_LEDEFFECT,
    };

    static void
    Yay (uint8_t seqIndex) {
      ::Macros.play (MACRO (T(Backslash),
                            T(O),
                            T(Slash),
                            END));
    }

    static void
    Shruggy (uint8_t seqIndex) {
      ::Unicode.type (0xaf);
      ::Macros.play (MACRO (T(Backslash),
                            D(RShift),
                            T(Minus),
                            T(9),
                            U(RShift),
                            END));
      ::Unicode.type (0x30c4);
      ::Macros.play (MACRO (D(RShift),
                            T(0),
                            T(Minus),
                            U(RShift),
                            T(Slash),
                            END));
      ::Unicode.type (0xaf);
    }

    static void
    startUCIS (uint8_t seqIndex) {
      handle_key_event (SYSTER, 255, 255, IS_PRESSED | INJECTED);
    }

    static void
    NextLEDEffect (uint8_t seqIndex) {
      LEDControl.next_mode ();
    }

    static const Akela::Leader::dictionary_t dictionary[] PROGMEM = LEADER_DICT
      (
       [LEAD_UNICODE_UCIS]   = {LEADER_SEQ (LEAD(MAIN), Key_U), startUCIS},

       [LEAD_CSILLA]          = {LEADER_SEQ (LEAD(MAIN), Key_C), (Akela::Leader::action_t)algernon::Macros::Csilla},
       [LEAD_GERGO]           = {LEADER_SEQ (LEAD(MAIN), Key_G), (Akela::Leader::action_t)algernon::Macros::Gergo},
       [LEAD_YAY]             = {LEADER_SEQ (LEAD(MAIN), Key_Y), Yay},
       [LEAD_SHRUGGY]         = {LEADER_SEQ (LEAD(MAIN), Key_S), Shruggy},

       [LEAD_LEDEFFECT]       = {LEADER_SEQ (LEAD(MAIN), LEAD(MAIN)), NextLEDEffect}
      );

    void
    configure (void) {
      Keyboardio.use (&::Leader, &::HostOS, &::Unicode, NULL);

      ::Leader.configure (dictionary);
    }

  }
}
