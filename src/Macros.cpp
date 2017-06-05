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
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-LangPack-Hungarian.h>

namespace algernon {
namespace Macros {

namespace LP = kaleidoscope::language;

void Csilla() {
  ::Macros.play(MACRO(Tr(LSHIFT(Key_C)),
                      Tc(S),
                      Tc(I),
                      Tc(L),
                      Tc(L),
                      END));

  handle_keyswitch_event((Key) {
    .raw = LP::HUN_AA
  }, UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED | INJECTED);

  ::Macros.play(MACRO(Tc(M),
                      Tc(A),
                      Tc(S),
                      Tc(S),
                      Tc(Z),
                      Tc(O),
                      Tc(N),
                      Tc(Y),
                      Tc(K),
                      END));

  handle_keyswitch_event((Key) {
    .raw = LP::HUN_AA
  }, UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED | INJECTED);

  ::Macros.play(MACRO(Tc(M),
                      END));
}

void Gergo() {
  ::Macros.play(MACRO(Tr(LSHIFT(Key_G)),
                      Tc(E),
                      Tc(J),
                      Tc(G),
                      END));

  handle_keyswitch_event((Key) {
    .raw = LP::HUN_ODA
  }, UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED | INJECTED);
  Keyboard.sendReport();
  handle_keyswitch_event((Key) {
    .raw = LP::HUN_ODA
  }, UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED | INJECTED);
  Keyboard.sendReport();
  handle_keyswitch_event((Key) {
    .raw = LP::HUN_ODA
  }, UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED | INJECTED);
}

}
}
