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

#include "MagicCombo.h"
#include "Layers.h"
#include "Hungarian.h"

#include <Akela-MagicCombo.h>
#include <Keyboardio-Macros.h>

namespace algernon {
  namespace MagicCombo {

    enum {
      ADORE,
      CsillaDvorak,
      CsillaADORE,
    };

    static void
    toggleADORE () {
      if (Layer.isOn (_ADORE)) {
        Layer.defaultLayer (_DVORAK);
      } else {
        Layer.defaultLayer (_ADORE);
      }
    }

    static void
    Csilla () {
      Macros.play (MACRO (Tr(LSHIFT(Key_C)),
                          T(S),
                          T(I),
                          T(L),
                          T(L),
                          Tr((Key){.raw = HUN_AA}),
                          T(M),
                          T(A),
                          T(S),
                          T(S),
                          T(Z),
                          T(O),
                          T(N),
                          T(Y),
                          T(K),
                          Tr((Key){.raw = HUN_AA}),
                          T(M),
                          END));
    }

    static Akela::MagicCombo::dictionary_t dictionary[] = {
      // palm keys + ADORE
      [ADORE] = {R3C6 | R2C1  | R2C2 | R2C3,
                 R3C9 | R2C10 | R2C11},
      // palm keys + CS (Dvorak)
      [CsillaDvorak] = {R3C6,
                        R3C9 | R1C12 | R2C14},
      // palm keys + CS (ADORE)
      [CsillaADORE] = {R3C6 | R1C3,
                       R3C9 | R2C14},
    };

    void
    configure (void) {
      Akela::USE (::MagicCombo);

      ::MagicCombo.configure (dictionary);
    }
  };
};

void magicComboActions (uint8_t comboIndex, uint32_t leftHand, uint32_t rightHand) {
  switch (comboIndex) {
  case algernon::MagicCombo::ADORE:
    algernon::MagicCombo::toggleADORE ();
    break;
  case algernon::MagicCombo::CsillaDvorak:
  case algernon::MagicCombo::CsillaADORE:
    algernon::MagicCombo::Csilla ();
    break;
  }
}
