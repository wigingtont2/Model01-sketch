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

#include "Syster.h"
#include "SymUnI.h"

#include <Kaleidoscope-Unicode.h>

void systerAction(kaleidoscope::Syster::action_t action, const char *symbol) {
  switch (action) {
  case kaleidoscope::Syster::StartAction:
    Unicode.type(0x2328);
    break;
  case kaleidoscope::Syster::EndAction:
    handle_keyswitch_event(Key_Backspace, 255, 255, IS_PRESSED | INJECTED);
    Keyboard.sendReport();
    handle_keyswitch_event(Key_Backspace, 255, 255, WAS_PRESSED | INJECTED);
    Keyboard.sendReport();
    break;
  case kaleidoscope::Syster::SymbolAction:
    algernon::SymUnI::input(symbol);
    break;
  }
}

namespace algernon {
namespace Syster {

void configure(void) {
  Kaleidoscope.use(&::Syster);
}

}
}
