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

#include "Layers.h"
#include "TapDance.h"
#include "Leader.h"
#include "OneShot.h"

namespace algernon {
  namespace TapDance {
    static void tap (Key key, byte row, byte col) {
      handle_keyswitch_event (key, row, col, IS_PRESSED | INJECTED);
      Keyboard.sendReport ();
      handle_keyswitch_event (key, row, col, WAS_PRESSED | INJECTED);
      Keyboard.sendReport ();
    }

    static void GUI (uint8_t tapCount, byte row, byte col, KaleidoscopePlugins::TapDance::ActionType tapDanceAction) {
      switch (tapDanceAction) {
      case KaleidoscopePlugins::TapDance::Tap:
        break;
      case KaleidoscopePlugins::TapDance::Interrupt:
      case KaleidoscopePlugins::TapDance::Hold:
      case KaleidoscopePlugins::TapDance::Timeout:
        handle_keyswitch_event (Key_LeftGui, row, col, IS_PRESSED | INJECTED);
        Keyboard.sendReport ();
        break;
      case KaleidoscopePlugins::TapDance::Release:
        handle_keyswitch_event (Key_LeftGui, row, col, WAS_PRESSED | INJECTED);
        Keyboard.sendReport ();
        break;
      }

      if (tapCount >= 2) {
        if (tapDanceAction == KaleidoscopePlugins::TapDance::Release) {
          ::OneShot.inject (OSL(_APPSEL), WAS_PRESSED);
        } else if (tapDanceAction == KaleidoscopePlugins::TapDance::Timeout) {
          ::OneShot.inject (OSL(_APPSEL), IS_PRESSED);
          Serial.println (F("appsel:start"));
        }
      }
    }

    static void TMUX (uint8_t tapCount, byte row, byte col, KaleidoscopePlugins::TapDance::ActionType tapDanceAction) {
      if (tapDanceAction != KaleidoscopePlugins::TapDance::Release)
        return;

      Key key;

      if (tapCount == 1) {
        key = LALT (Key_Spacebar);
      } else {
        key = LCTRL (Key_A);
      }

      tap (key, row, col);
    }

    static void TMUXPane (uint8_t tapCount, byte row, byte col, KaleidoscopePlugins::TapDance::ActionType tapDanceAction) {
      if (tapDanceAction != KaleidoscopePlugins::TapDance::Release)
        return;

      // Alt + Space
      tap (LALT (Key_Spacebar), row, col);

      // P, or Z
      Key key = Key_P;
      if (tapCount == 2)
        key = Key_Z;

      tap (key, row, col);
    }

    bool cancelOneShot = false;
  }
}

void
tapDanceAction (uint8_t tapDanceIndex, byte row, byte col, uint8_t tapCount, KaleidoscopePlugins::TapDance::ActionType tapDanceAction) {
  if (tapDanceAction == KaleidoscopePlugins::TapDance::Release)
    algernon::TapDance::cancelOneShot = true;

  switch (tapDanceIndex) {
  case TMUX:
    return algernon::TapDance::TMUX (tapCount, row, col, tapDanceAction);
  case TMUXP:
    return algernon::TapDance::TMUXPane (tapCount, row, col, tapDanceAction);

  case LPB:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_LeftBracket,
                               Key_LeftParen);
  case RPB:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_RightBracket,
                               Key_RightParen);

  case COLON:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               LSHIFT (Key_Semicolon),
                               Key_Semicolon);

  case MNP:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_Consumer_ScanNextTrack,
                               Key_Consumer_ScanPreviousTrack);

  case GUI:
    return algernon::TapDance::GUI (tapCount, row, col, tapDanceAction);

  case F11:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_F11,
                               Key_NoKey);

  case VOLD:
    return tapDanceActionKeys (tapCount, tapDanceAction,
                               Key_Consumer_VolumeDecrement,
                               Key_Consumer_Mute);
  }
}

namespace algernon {
  namespace TapDance {
    void
    configure (void) {
      Kaleidoscope.use (&::TapDance, NULL);
    }
  };
};
