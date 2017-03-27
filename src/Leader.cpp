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
#include <Kaleidoscope-EEPROM-Keymap-Programmer.h>

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
      LEAD_SHRUGGY,

      LEAD_LEDEFFECT,

      LEAD_BUTTERFLY,

      LEAD_REPROGRAM,
    };

    static void
    Shruggy (uint8_t seqIndex) {
      ::Unicode.type (0xaf);
      ::Macros.play (MACRO (Tc(Backslash),
                            D(RShift),
                            Tc(Minus),
                            Tc(9),
                            U(RShift),
                            END));
      ::Unicode.type (0x30c4);
      ::Macros.play (MACRO (D(RShift),
                            Tc(0),
                            Tc(Minus),
                            U(RShift),
                            Tc(Slash),
                            END));
      ::Unicode.type (0xaf);
    }

    static void
    startUCIS (uint8_t seqIndex) {
      handle_key_event (SYSTER, 255, 255, IS_PRESSED | INJECTED);
    }

    static void
    Kids (uint8_t seqIndex) {
      ::Macros.play (MACRO (Tc(Space), Tr(LSHIFT(Key_7)), Tc(Space), END));
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
                            D(LAlt), W(100), Tc(X), W(100), U(LAlt),
                            W(100), W(100),
                            Tc(B), Tc(U), Tc(T), Tc(T), Tc(E), Tc(R), Tc(F), Tc(L), Tc(Y),
                            W(100), W(100),
                            Tc(Enter), W(100),
                            Tc(Y), END));
    }

    static void
    ReProgram (uint8_t seqIndex) {
      ::EEPROMKeymapProgrammer.nextState ();
    }

    static const KaleidoscopePlugins::Leader::dictionary_t dictionary[] PROGMEM = LEADER_DICT
      (
       [LEAD_UNICODE_UCIS]   = {LEADER_SEQ (LEAD(MAIN), Key_U), startUCIS},

       [LEAD_CSILLA]          = {LEADER_SEQ (LEAD(MAIN), Key_C), (KaleidoscopePlugins::Leader::action_t)algernon::Macros::Csilla},
       [LEAD_KIDS]            = {LEADER_SEQ (LEAD(MAIN), Key_K), Kids},
       [LEAD_GERGO]           = {LEADER_SEQ (LEAD(MAIN), Key_G), (KaleidoscopePlugins::Leader::action_t)algernon::Macros::Gergo},
       [LEAD_SHRUGGY]         = {LEADER_SEQ (LEAD(MAIN), Key_S), Shruggy},

       [LEAD_LEDEFFECT]       = {LEADER_SEQ (LEAD(MAIN), LEAD(MAIN)), NextLEDEffect},

       [LEAD_BUTTERFLY]       = {LEADER_SEQ (LEAD(MAIN), OSM(LAlt)), Butterfly},

       [LEAD_REPROGRAM]       = {LEADER_SEQ (LEAD(MAIN), Key_R), ReProgram}
      );

    void
    configure (void) {
      Kaleidoscope.use (&::Leader, &::Unicode, NULL);

      ::Leader.configure (dictionary);
    }

  }
}
