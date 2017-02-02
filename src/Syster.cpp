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

#include <Akela-Unicode.h>

void systerAction (Akela::Syster::action_t action, const char *symbol) {
  switch (action) {
  case Akela::Syster::StartAction:
    Unicode.type (0x2328);
    break;
  case Akela::Syster::EndAction:
    handle_key_event (Key_Backspace, 255, 255, IS_PRESSED | INJECTED);
    Keyboard.sendReport ();
    handle_key_event (Key_Backspace, 255, 255, WAS_PRESSED | INJECTED);
    Keyboard.sendReport ();
    break;
  case Akela::Syster::SymbolAction:
    if (strcmp (symbol, "coffee") == 0) {
      Unicode.type (0x2615);
    } else if (strcmp (symbol, "lambda") == 0) {
      Unicode.type (0x03bb);
    } else if (strcmp (symbol, "poop") == 0) {
      Unicode.type (0x1f4a9);
    } else if (strcmp (symbol, "rofl") == 0) {
      Unicode.type (0x1f923);
    } else if (strcmp (symbol, "kiss") == 0) {
      Unicode.type (0x1f619);
    } else if (strcmp (symbol, "snowman") == 0) {
      Unicode.type (0x2603);
    } else if (strcmp (symbol, "heart") == 0) {
      Unicode.type (0x2764);
    } else if (strcmp (symbol, "bolt") == 0) {
      Unicode.type (0x26a1);
    } else if (strcmp (symbol, "pi") == 0) {
      Unicode.type (0x03c0);
    } else if (strcmp (symbol, "mouse") == 0) {
      Unicode.type (0x1f401);
    } else if (strcmp (symbol, "micro") == 0) {
      Unicode.type (0x00b5);
    }
    break;
  }
}

namespace algernon {
  namespace Syster {
    void
    configure (void) {
      Keyboardio.use (&::Syster, NULL);
    }

  }
}
