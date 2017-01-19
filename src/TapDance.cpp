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

#include "TapDance.h"
#include "Leader.h"
#include "OneShot.h"

namespace algernon {
  namespace TapDance {
    static void TMUX (uint8_t tapCount, Akela::TapDance::ActionType tapDanceAction) {
      if (tapDanceAction != Akela::TapDance::Release)
        return;

      Key key;

      if (tapCount == 1) {
        key.flags = KEY_FLAGS | LALT_HELD;
        key.keyCode = Key_Space.keyCode;
      } else {
        key.flags = KEY_FLAGS | CTRL_HELD;
        key.keyCode = Key_A.keyCode;
      }

      press_key (key);
      Keyboard.sendReport ();
      release_key (key);
      Keyboard.sendReport ();
    }

    static void TMUXPane (uint8_t tapCount, Akela::TapDance::ActionType tapDanceAction) {
      if (tapDanceAction != Akela::TapDance::Release)
        return;

      Key key;

      // Alt + Space
      key.flags = KEY_FLAGS | LALT_HELD;
      key.raw = Key_Space.keyCode;
      press_key (key);
      Keyboard.sendReport ();
      press_key (key);
      Keyboard.sendReport ();


      // P, or Z

      key.raw = Key_P.raw;
      if (tapCount == 2)
        key.raw = Key_Z.raw;

      press_key (key);
      Keyboard.sendReport ();
      release_key (key);
      Keyboard.sendReport ();
    }
  }
}

void
tapDanceAction (uint8_t tapDanceIndex, uint8_t tapCount, Akela::TapDance::ActionType tapDanceAction) {
  switch (tapDanceIndex) {
  case TMUX:
    return algernon::TapDance::TMUX (tapCount, tapDanceAction);
  case TMUXP:
    return algernon::TapDance::TMUXPane (tapCount, tapDanceAction);

  case LPB:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_LBracket,
                               (Key){ KEY_FLAGS | SHIFT_HELD, HID_KEYBOARD_9_AND_LEFT_PAREN });
  case RPB:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_RBracket,
                               (Key){ KEY_FLAGS | SHIFT_HELD, HID_KEYBOARD_0_AND_RIGHT_PAREN });


  case COLON:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               (Key){ KEY_FLAGS | SHIFT_HELD, HID_KEYBOARD_SEMICOLON_AND_COLON },
                               Key_Semicolon);

  case MNP:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_nextTrack,
                               Key_prevTrack);
  }
}

namespace algernon {
  namespace TapDance {
    void
    configure (void) {
      Keyboardio.use (&::TapDance, NULL);
    }
  };
};
