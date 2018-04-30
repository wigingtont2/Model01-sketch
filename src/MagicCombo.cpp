/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016, 2017, 2018  Gergely Nagy
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
#include "Macros.h"

#include <Kaleidoscope-MagicCombo.h>
#include <Kaleidoscope-LangPack-Hungarian.h>
#include <Kaleidoscope-Macros.h>

namespace algernon {
namespace MagicCombo {

enum {
  ADORE,
  CsillaDvorak,
  CsillaADORE,
  Steno,
};

static void toggleADORE() {
  if (Layer.isOn(_ADORE)) {
    Layer.defaultLayer(_DVORAK);
  } else {
    Layer.defaultLayer(_ADORE);
  }
}

static void togglePlover() {
  if (Layer.isOn(_PLOVER)) {
    Layer.off(_PLOVER);
  } else {
    Layer.on(_PLOVER);
  }
}

static const kaleidoscope::MagicCombo::combo_t magic_combos[] PROGMEM = {
  // palm keys + ADORE
  [ADORE] = {
    R3C6 | R2C1  | R2C2 | R2C3,
    R3C9 | R2C10 | R2C11
  },
  // palm keys + CS (Dvorak)
  [CsillaDvorak] = {
    R3C6,
    R3C9 | R1C12 | R2C14
  },
  // palm keys + CS (ADORE)
  [CsillaADORE] = {
    R3C6 | R1C3,
    R3C9 | R2C14
  },
  // 3 leftmost thumb keys + palm keys
  [Steno] = {
    R0C7 | R1C7 | R2C7 | R3C6,
    R3C9
  },
};

void configure(void) {
  ::MagicCombo.magic_combos = magic_combos;
}

}
}

void magicComboActions(uint8_t comboIndex, uint32_t leftHand, uint32_t rightHand) {
  switch (comboIndex) {
  case algernon::MagicCombo::ADORE:
    algernon::MagicCombo::toggleADORE();
    break;
  case algernon::MagicCombo::CsillaDvorak:
  case algernon::MagicCombo::CsillaADORE:
    algernon::Macros::Csilla();
    break;
  case algernon::MagicCombo::Steno:
    algernon::MagicCombo::togglePlover();
    break;
  }
}
