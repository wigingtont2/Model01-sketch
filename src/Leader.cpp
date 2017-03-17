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

#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-Syster.h>
#include <Kaleidoscope-LangPack-Hungarian.h>
#include <Kaleidoscope-OneShot.h>

#include "Macros.h"

using namespace KaleidoscopePlugins::LangPack;

namespace algernon {
  namespace Leader {

    // Leaders
    enum {
      LEAD_UNICODE_UCIS,

      LEAD_CSILLA,
      LEAD_KIDS,
      LEAD_GERGO,
      LEAD_YAY,
      LEAD_SHRUGGY,

      LEAD_LEDEFFECT,

      LEAD_BUTTERFLY,
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
    Kids (uint8_t seqIndex) {
      ::Macros.play (MACRO (T(Space), D(RShift), T(7), U(RShift), T(Space), END));
      ::Unicode.type (0x1f476);
      ::Unicode.type (0x1f476);
    }

    static void
    NextLEDEffect (uint8_t seqIndex) {
      LEDControl.next_mode ();
    }

    static void
    Butterfly (uint8_t seqIndex) {
      ::Macros.play (MACRO (I(10),
                            D(LAlt), W(100), T(X), W(100), U(LAlt),
                            W(100), W(100),
                            T(B), T(U), T(T), T(T), T(E), T(R), T(F), T(L), T(Y),
                            W(100), W(100),
                            T(Enter), W(100),
                            T(Y), END));
    }

    static const KaleidoscopePlugins::Leader::dictionary_t dictionary[] PROGMEM = LEADER_DICT
      (
       [LEAD_UNICODE_UCIS]   = {LEADER_SEQ (LEAD(MAIN), Key_U), startUCIS},

       [LEAD_CSILLA]          = {LEADER_SEQ (LEAD(MAIN), Key_C), (KaleidoscopePlugins::Leader::action_t)algernon::Macros::Csilla},
       [LEAD_KIDS]            = {LEADER_SEQ (LEAD(MAIN), Key_K), Kids},
       [LEAD_GERGO]           = {LEADER_SEQ (LEAD(MAIN), Key_G), (KaleidoscopePlugins::Leader::action_t)algernon::Macros::Gergo},
       [LEAD_YAY]             = {LEADER_SEQ (LEAD(MAIN), Key_Y), Yay},
       [LEAD_SHRUGGY]         = {LEADER_SEQ (LEAD(MAIN), Key_S), Shruggy},

       [LEAD_LEDEFFECT]       = {LEADER_SEQ (LEAD(MAIN), LEAD(MAIN)), NextLEDEffect},

       [LEAD_BUTTERFLY]       = {LEADER_SEQ (LEAD(MAIN), OSM(LAlt)), Butterfly}
      );

    void
    configure (void) {
      Kaleidoscope.use (&::Leader, &::HostOS, &::Unicode, NULL);

      ::Leader.configure (dictionary);
    }

  }
}
