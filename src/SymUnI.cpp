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

#include "SymUnI.h"
#include <Akela-Unicode.h>

namespace algernon {
  namespace SymUnI {
    void
    input (const char *symbol) {
      uint32_t code = 0;

      if (strcmp (symbol, "coffee") == 0) {
        code = 0x2615;
      } else if (strcmp (symbol, "lambda") == 0) {
        code = 0x03bb;
      } else if (strcmp (symbol, "poop") == 0) {
        code = 0x1f4a9;
      } else if (strcmp (symbol, "rofl") == 0) {
        code = 0x1f923;
      } else if (strcmp (symbol, "kiss") == 0) {
        code = 0x1f619;
      } else if (strcmp (symbol, "snowman") == 0) {
        code = 0x2603;
      } else if (strcmp (symbol, "heart") == 0) {
        code = 0x2764;
      } else if (strcmp (symbol, "bolt") == 0) {
        code = 0x26a1;
      } else if (strcmp (symbol, "pi") == 0) {
        code = 0x03c0;
      } else if (strcmp (symbol, "mouse") == 0) {
        code = 0x1f401;
      } else if (strcmp (symbol, "micro") == 0) {
        code = 0x00b5;
      }

      if (code)
        Unicode.type (code);
      else
        typeString (symbol);
    }

    void
    typeString (const char *str) {
      Unicode.start ();

      for (uint8_t i = 0; str[i]; i++) {
        const char c = str[i];
        Key key = Key_NoKey;

        switch (c) {
        case 'a' ... 'z':
          key.keyCode = Key_A.keyCode + (c - 'a');
          break;
        case 'A' ... 'Z':
          key.keyCode = Key_A.keyCode + (c - 'A');
          break;
        case '1' ... '9':
          key.keyCode = Key_1.keyCode + (c - '1');
          break;
        case '0':
          key.keyCode = Key_0.keyCode;
          break;
        }

        Unicode.input ();
        handle_key_event (key, 255, 255, IS_PRESSED | INJECTED);
        Keyboard.sendReport ();
        Unicode.input ();
        handle_key_event (key, 255, 255, WAS_PRESSED | INJECTED);
        Keyboard.sendReport ();
      }
      Unicode.end ();
    }

  }
}
