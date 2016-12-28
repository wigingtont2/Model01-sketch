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

#include "Hungarian.h"
#include <KeyboardioFirmware.h>

typedef enum {
  AA,
  OA,
  OU,
  ODA,
  EA,
  UA,
  UU,
  UDA,
  IA,
} HungarianSymbol;

static Key
handleHungarian (Key mappedKey, byte row, byte col, uint8_t keyState) {
  if (mappedKey.raw < HUNGARIAN_FIRST || mappedKey.raw > HUNGARIAN_LAST)
    return mappedKey;

  if (!key_toggled_on (keyState))
    return Key_NoKey;

  bool needShift = Keyboard.isModifierActive (Key_LShift.rawKey);

  Keyboard.press (Key_RAlt.rawKey);
  Keyboard.sendReport ();
  delay (10);
  Keyboard.release (Key_RAlt.rawKey);
  Keyboard.sendReport ();
  delay (10);

  HungarianSymbol symbol = (HungarianSymbol) (mappedKey.raw - HUNGARIAN_FIRST);
  Key accent;
  uint8_t kc = 0;

  accent.flags = KEY_FLAGS;

  switch (symbol) {
  case AA:
    kc = Key_A.rawKey;
    accent.raw = Key_Quote.raw;
    break;
  case OA:
    kc = Key_O.rawKey;
    accent.raw = Key_Quote.raw;
    break;
  case OU:
    kc = Key_O.rawKey;
    accent.raw = Key_Quote.raw;
    accent.flags |= SHIFT_HELD;
    break;
  case ODA:
    kc = Key_O.rawKey;
    accent.raw = Key_Equals.raw;
    break;
  case EA:
    kc = Key_E.rawKey;
    accent.raw = Key_Quote.raw;
    break;
  case UA:
    kc = Key_U.rawKey;
    accent.raw = Key_Quote.raw;
    break;
  case UU:
    kc = Key_U.rawKey;
    accent.raw = Key_Quote.raw;
    accent.flags |= SHIFT_HELD;
    break;
  case UDA:
    kc = Key_U.rawKey;
    accent.raw = Key_Equals.raw;
    break;
  case IA:
    kc = Key_I.rawKey;
    accent.raw = Key_Quote.raw;
    break;
  }

  if (accent.flags & SHIFT_HELD)
    Keyboard.press (Key_LShift.rawKey);
  else
    Keyboard.release (Key_LShift.rawKey);
  Keyboard.sendReport ();
  delay(10);

  Keyboard.press (accent.rawKey);
  Keyboard.sendReport ();
  Keyboard.release (accent.rawKey);
  Keyboard.sendReport ();

  if (needShift)
    Keyboard.press (Key_LShift.rawKey);
  else
    Keyboard.release (Key_LShift.rawKey);

  delay (10);
  Keyboard.press (kc);
  Keyboard.sendReport ();
  delay(10);
  Keyboard.release (kc);
  Keyboard.sendReport ();
  delay (10);

  return Key_NoKey;
}

Hungarian_::Hungarian_ (void) {
}

void
Hungarian_::begin (void) {
  event_handler_hook_add (handleHungarian);
}
