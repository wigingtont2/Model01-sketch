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
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-LED-AlphaSquare.h>

namespace algernon {
namespace SymUnI {

void input(const char *symbol) {
  uint32_t code = 0;
  bool lambda = false;

  if (strcmp_P(symbol, PSTR("coffee")) == 0) {
    code = 0x2615;
  } else if (strcmp_P(symbol, PSTR("lambda")) == 0) {
    lambda = true;
    code = 0x03bb;
  } else if (strcmp_P(symbol, PSTR("poop")) == 0) {
    code = 0x1f4a9;
  } else if (strcmp_P(symbol, PSTR("rofl")) == 0) {
    code = 0x1f923;
  } else if (strcmp_P(symbol, PSTR("kiss")) == 0) {
    code = 0x1f619;
  } else if (strcmp_P(symbol, PSTR("snowman")) == 0) {
    code = 0x2603;
  } else if (strcmp_P(symbol, PSTR("heart")) == 0) {
    code = 0x2764;
  } else if (strcmp_P(symbol, PSTR("bolt")) == 0) {
    code = 0x26a1;
  } else if (strcmp_P(symbol, PSTR("pi")) == 0) {
    code = 0x03c0;
  } else if (strcmp_P(symbol, PSTR("mouse")) == 0) {
    code = 0x1f401;
  } else if (strcmp_P(symbol, PSTR("micro")) == 0) {
    code = 0x00b5;
  } else if (strcmp_P(symbol, PSTR("tm")) == 0) {
    code = 0x2122;
  }

  if (code)
    Unicode.type(code);
  else
    typeString(symbol);

  if (lambda) {
    AlphaSquare.display(kaleidoscope::alpha_square::symbols::Lambda);
    delay(500);
    AlphaSquare.clear(kaleidoscope::alpha_square::symbols::Lambda);
  }
}

void typeString(const char *str) {
  Unicode.start();

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

    Unicode.input();
    handle_keyswitch_event(key, 255, 255, IS_PRESSED | INJECTED);
    Keyboard.sendReport();
    Unicode.input();
    handle_keyswitch_event(key, 255, 255, WAS_PRESSED | INJECTED);
    Keyboard.sendReport();
  }
  Unicode.end();
}

}
}
