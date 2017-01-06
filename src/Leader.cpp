/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016  Gergely Nagy
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
#include "Hungarian.h"

#include <Keyboardio-Macros.h>
#include <Akela-Unicode.h>

namespace algernon {
  namespace Leader {

    // Leaders
    enum {
      LEAD_UNICODE_LAMBDA,
      LEAD_UNICODE_POOP,
      LEAD_UNICODE_ROFL,
      LEAD_UNICODE_KISS,
      LEAD_UNICODE_SNOWMAN,
      LEAD_UNICODE_COFFEE,
      LEAD_UNICODE_HEART,
      LEAD_UNICODE_BOLT,
      LEAD_UNICODE_PI,
      LEAD_UNICODE_MOUSE,
      LEAD_UNICODE_MICRO,

      LEAD_UNICODE_START,

      LEAD_CSILLA,
      LEAD_GERGO,
      LEAD_YAY,
      LEAD_SHRUGGY,
    };

    static const uint32_t unicodeTable[] PROGMEM = {
      [LEAD_UNICODE_LAMBDA]  = 0x03bb,
      [LEAD_UNICODE_POOP]    = 0x1f4a9,
      [LEAD_UNICODE_ROFL]    = 0x1f923,
      [LEAD_UNICODE_KISS]    = 0x1f619,
      [LEAD_UNICODE_SNOWMAN] = 0x2603,
      [LEAD_UNICODE_COFFEE]  = 0x2615,
      [LEAD_UNICODE_HEART]   = 0x2764,
      [LEAD_UNICODE_BOLT]    = 0x26a1,
      [LEAD_UNICODE_PI]      = 0x03c0,
      [LEAD_UNICODE_MOUSE]   = 0x1f401,
      [LEAD_UNICODE_MICRO]   = 0x00b5,
    };

    static void
    Csilla (uint8_t seqIndex) {
      Macros.play (MACRO (Tr(LSHIFT(Key_C)),
                          T(S),
                          T(I),
                          T(L),
                          T(L),
                          END));

      handle_key_event ((Key){.raw = HUN_AA}, 255, 255, IS_PRESSED | INJECTED);

      Macros.play (MACRO (T(M),
                          T(A),
                          T(S),
                          T(S),
                          T(Z),
                          T(O),
                          T(N),
                          T(Y),
                          T(K),
                          END));

      handle_key_event ((Key){.raw = HUN_AA}, 255, 255, IS_PRESSED | INJECTED);

      Macros.play (MACRO (T(M),
                          END));
    }

    static void
    Gergo (uint8_t seqIndex) {
      Macros.play (MACRO (Tr(LSHIFT(Key_G)),
                          T(E),
                          T(J),
                          T(G),
                          Tr((Key){.raw = HUN_ODA}),
                          Tr((Key){.raw = HUN_ODA}),
                          Tr((Key){.raw = HUN_ODA}),
                          END));
    }

    static void
    Yay (uint8_t seqIndex) {
      Macros.play (MACRO (T(Backslash),
                          T(O),
                          T(Slash),
                          END));
    }

    static void
    Shruggy (uint8_t seqIndex) {
      ::Unicode.type (0xaf);
      Macros.play (MACRO (T(Backslash),
                          D(RShift),
                          T(Minus),
                          T(9),
                          U(RShift),
                          END));
      ::Unicode.type (0x30c4);
      Macros.play (MACRO (D(RShift),
                          T(0),
                          T(Minus),
                          U(RShift),
                          T(Slash),
                          END));
      ::Unicode.type (0xaf);
    }

    static void
    Unicode (uint8_t seqIndex) {
      if (seqIndex == LEAD_UNICODE_START)
        return ::Unicode.start ();

      uint32_t code = pgm_read_dword (unicodeTable[seqIndex]);
      ::Unicode.typeCode (code);
      ::Unicode.end ();

      ::Leader.reset ();
    }

    static const Akela::Leader::dictionary_t dictionary[] PROGMEM = LEADER_DICT
      (
       [LEAD_UNICODE_LAMBDA]  = {LEADER_SEQ (LEAD(MAIN), Key_L), Unicode},
       [LEAD_UNICODE_POOP]    = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_P, Key_O, Key_O, Key_P), Unicode},
       [LEAD_UNICODE_ROFL]    = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_R, Key_O, Key_F, Key_L), Unicode},
       [LEAD_UNICODE_KISS]    = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_K, Key_I, Key_S, Key_S), Unicode},
       [LEAD_UNICODE_SNOWMAN] = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_S, Key_N, Key_O, Key_W, Key_M, Key_A, Key_N), Unicode},
       [LEAD_UNICODE_COFFEE]  = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_C, Key_O, Key_F, Key_F, Key_E, Key_E), Unicode},
       [LEAD_UNICODE_HEART]   = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_H, Key_E, Key_A, Key_R, Key_T), Unicode},
       [LEAD_UNICODE_BOLT]    = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_B, Key_O, Key_L, Key_T), Unicode},
       [LEAD_UNICODE_PI]      = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_P, Key_I), Unicode},
       [LEAD_UNICODE_MOUSE]   = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_M, Key_O, Key_U, Key_S, Key_E), Unicode},
       [LEAD_UNICODE_MICRO]   = {LEADER_SEQ (LEAD(MAIN), Key_U, Key_M, Key_I, Key_C, Key_R, Key_O), Unicode},

       [LEAD_UNICODE_START]   = {LEADER_SEQ (LEAD(MAIN), Key_U), Unicode},

       [LEAD_CSILLA]          = {LEADER_SEQ (LEAD(MAIN), Key_C), Csilla},
       [LEAD_GERGO]           = {LEADER_SEQ (LEAD(MAIN), Key_G), Gergo},
       [LEAD_YAY]             = {LEADER_SEQ (LEAD(MAIN), Key_Y), Yay},
       [LEAD_SHRUGGY]         = {LEADER_SEQ (LEAD(MAIN), Key_S), Shruggy}
      );

    void
    configure (void) {
      Keyboardio.use (&::Leader, &::Unicode, NULL);

      ::Leader.configure (dictionary);
    }

  }
}
