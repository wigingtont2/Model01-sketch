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

#include <Keyboardio-MouseKeys.h>
#include <Keyboardio-Macros.h>
#include <KeyboardioFirmware.h>

#include <Akela-Leader.h>
#include <Akela-OneShot.h>
#include <Akela-Colormap.h>
#include <Akela-KeyLogger.h>
#include <Akela-Heatmap.h>
#include <Akela-Unicode.h>
#include <Akela-MagicCombo.h>
#include <Akela-ShapeShifter.h>
#include <Akela-TapDance.h>

#include <LED-Off.h>

#include "Hungarian.h"

// LAYERS

enum {
  _DVORAK,
  _ADORE,
  _NAV,
  _HUN,
  _EMPTY
};

// Tap-dance
enum {
  TMUX,
  TMUXP,
  LPB,
  RPB,
  COLON,
  MNP,

  HLEAD,
};

#define MO(layer) (Key){ KEY_FLAGS | SYNTHETIC | SWITCH_TO_KEYMAP, MOMENTARY_OFFSET + layer }
#define R(n) (Key){.raw = n}
#define MW(d) Key_mouseWarp ## d

#define NIY Key_NoKey

const Key keymaps[][ROWS][COLS] PROGMEM = {
  [_DVORAK] = KEYMAP_STACKED
  (
    Key_F11       ,Key_9     ,Key_7     ,Key_5      ,Key_3 ,Key_1 ,TD(TMUX)
   ,Key_Backtick  ,Key_Quote ,Key_Comma ,Key_Period ,Key_P ,Key_Y ,TD(LPB)
   ,Key_Tab       ,Key_A     ,Key_O     ,Key_E      ,Key_U ,Key_I
   ,Key_playPause ,Key_Slash ,Key_Q     ,Key_J      ,Key_K ,Key_X ,Key_LAlt

   ,TD(COLON) ,Key_Backspace ,Key_LShift ,Key_Esc
   ,MO(_NAV)

   ,TD(TMUXP) ,Key_0 ,Key_2 ,Key_4 ,Key_6 ,Key_8 ,TD(MNP)
   ,TD(RPB)   ,Key_F ,Key_G ,Key_C ,Key_R ,Key_L ,Key_Backslash
              ,Key_D ,Key_H ,Key_T ,Key_N ,Key_S ,Key_Equals
   ,Key_LCtrl ,Key_B ,Key_M ,Key_W ,Key_V ,Key_Z ,Key_stop

   ,Key_LGUI ,Key_Enter ,Key_Space ,Key_Minus
   ,TD(HLEAD)
  ),

  [_ADORE] = KEYMAP_STACKED
  (
    Key_F11       ,Key_9 ,Key_7 ,Key_5      ,Key_3     ,Key_1       ,TD(TMUX)
   ,Key_Backslash ,Key_X ,Key_W ,Key_C      ,Key_H     ,Key_F       ,TD(LPB)
   ,Key_Tab       ,Key_A ,Key_O ,Key_E      ,Key_I     ,Key_U
   ,Key_playPause ,Key_Z ,Key_Q ,Key_Quote  ,Key_Comma ,Key_Period  ,Key_LAlt

   ,TD(COLON) ,Key_Backspace ,Key_LShift ,Key_Esc
   ,MO(_NAV)

   ,TD(TMUXP) ,Key_0 ,Key_2 ,Key_4 ,Key_6 ,Key_8     ,TD(MNP)
   ,TD(RPB)   ,Key_M ,Key_G ,Key_L ,Key_P ,Key_Slash ,Key_Backslash
              ,Key_D ,Key_R ,Key_T ,Key_N ,Key_S     ,Key_Equals
   ,Key_LCtrl ,Key_B ,Key_K ,Key_V ,Key_Y ,Key_J     ,Key_stop

   ,Key_LGUI ,Key_Enter ,Key_Space ,Key_Minus
   ,TD(HLEAD)
  ),

  [_NAV] = KEYMAP_STACKED
  (
    ___ ,Key_F9 ,Key_F7 ,Key_F5 ,Key_F3 ,Key_F1 ,XXX
   ,XXX ,XXX    ,XXX    ,XXX    ,MW(NW) ,MW(NE) ,XXX
   ,XXX ,XXX    ,XXX    ,XXX    ,MW(SW) ,MW(SE)
   ,XXX ,XXX    ,XXX    ,XXX    ,XXX    ,XXX    ,___

   ,Key_volumeDown ,Key_volumeUp ,___ ,Key_volumeMute
   ,___

   ,LGUI(Key_L) ,Key_F10 ,Key_F2     ,Key_F4      ,Key_F6     ,Key_F8 ,XXX
   ,XXX         ,XXX     ,Key_Home   ,Key_UpArrow ,Key_End    ,XXX  ,XXX
                ,XXX     ,Key_LArrow ,Key_DnArrow ,Key_RArrow ,XXX  ,XXX
   ,___         ,XXX     ,XXX        ,XXX         ,XXX        ,XXX  ,XXX

   ,___ ,Key_PageDn ,Key_PageUp ,XXX
   ,MO(_EMPTY)
  ),

  [_HUN] = KEYMAP_STACKED
  (
    XXX ,XXX       ,XXX        ,XXX       ,XXX        ,XXX       ,XXX
   ,XXX ,XXX       ,R(HUN_ODA) ,XXX       ,R(HUN_UDA) ,XXX       ,XXX
   ,XXX ,R(HUN_AA) ,R(HUN_OA)  ,R(HUN_EA) ,R(HUN_UA)  ,R(HUN_IA)
   ,XXX ,XXX       ,R(HUN_OU)  ,XXX       ,R(HUN_UU)  ,XXX       ,XXX

   ,XXX ,___ ,___ ,___
   ,MO(_EMPTY)

   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
        ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX

   ,XXX ,XXX ,XXX ,XXX
   ,___
  ),

  [_EMPTY] = KEYMAP_STACKED
  (
    XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX
   ,___

   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
        ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX

   ,XXX ,XXX ,XXX ,XXX
   ,___
   ),
};

// Colors
enum {
  OFF,
  FAINT_RED,
  FAINT_GREEN,
  FAINT_BLUE,
  CYAN,
  RED,
  BLUE,
  NAVY,
  YELLOW,

  TRNS = Akela::ColormapEffect::Transparent,
};

const cRGB colors[] PROGMEM = {
  [OFF]         = {0x00, 0x00, 0x00},
  [FAINT_RED]   = {0x40, 0x00, 0x00},
  [FAINT_GREEN] = {0x00, 0x40, 0x00},
  [FAINT_BLUE]  = {0x00, 0x00, 0x40},
  [CYAN]        = {0x00, 0x88, 0xff},
  [RED]         = {0xff, 0x00, 0x00},
  [BLUE]        = {0x00, 0x00, 0xff},
  [NAVY]        = {0x00, 0x00, 0x80},
  [YELLOW]      = {0xff, 0xff, 0x00},
};

static const uint8_t colorMap[KEYMAP_SIZE][ROWS][COLS] PROGMEM = {
  [_DVORAK] = KEYMAP_STACKED
  (
    OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,FAINT_GREEN

   ,OFF ,OFF ,FAINT_RED ,OFF
   ,CYAN

   ,OFF        ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF        ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
               ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,FAINT_BLUE ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF

   ,OFF ,OFF ,OFF ,OFF
   ,RED
  ),

  [_ADORE] = KEYMAP_STACKED
  (
    OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,FAINT_GREEN

   ,OFF ,OFF ,FAINT_RED ,OFF
   ,CYAN

   ,OFF        ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,OFF        ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
               ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
   ,FAINT_BLUE ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF

   ,OFF ,OFF ,OFF ,OFF
   ,RED
  ),

  [_NAV] = KEYMAP_STACKED
  (
    CYAN ,CYAN ,CYAN ,CYAN ,CYAN ,CYAN ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS

   ,YELLOW ,YELLOW ,TRNS ,YELLOW
   ,TRNS

   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,NAVY ,BLUE ,NAVY ,TRNS ,TRNS
         ,TRNS ,BLUE ,BLUE ,BLUE ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS

   ,TRNS ,NAVY ,NAVY ,TRNS
   ,TRNS
  ),

  [_HUN] = KEYMAP_STACKED
  (
    TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,RED  ,TRNS ,RED  ,TRNS ,TRNS
   ,TRNS ,RED  ,RED  ,RED  ,RED  ,RED
   ,TRNS ,TRNS ,RED  ,TRNS ,RED  ,TRNS ,TRNS

   ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS

   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
         ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS

   ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS
  ),

  [_EMPTY] = KEYMAP_STACKED
  (
    TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS

   ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS

   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
         ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS

   ,TRNS ,TRNS ,TRNS ,TRNS
   ,TRNS
  ),
};

static const Akela::ShapeShifter::dictionary_t shapeShifterDictionary[] = {
  {Key_9, Key_NoKey},
  {Key_7, Key_2},
  {Key_5, Key_8},
  {Key_3, Key_6},
  {Key_1, Key_4},

  {Key_0, Key_5},
  {Key_2, Key_1},
  {Key_4, Key_3},
  {Key_6, Key_7},
  {Key_8, Key_NoKey},

  {Key_NoKey, Key_NoKey},
};

void magicToggleADORE (uint32_t leftHand, uint32_t rightHand) {
  if (Layer.isOn (_ADORE)) {
    Layer.defaultLayer (_DVORAK);
  } else {
    Layer.defaultLayer (_ADORE);
  }
}

void magicCsilla (uint32_t leftHand, uint32_t rightHand) {
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

Akela::MagicCombo::dictionary_t dictionary[] = {
  // palm keys + ADORE
  {R3C6 | R2C1  | R2C2 | R2C3, // left hand
   R3C9 | R2C10 | R2C11,       // right hand
   magicToggleADORE            // callback
  },
  // palm keys + CS (Dvorak)
  {R3C6,
   R3C9 | R1C12 | R2C14,
   magicCsilla},
  // palm keys + CS (ADORE)
  {R3C6 | R1C3,
   R3C9 | R2C14,
   magicCsilla},
};

static bool handleEsc (Key mappedKey, byte row, byte col, uint8_t keyState) {
  if (mappedKey.raw != Key_Esc.raw ||
      (keyState & INJECTED) ||
      !key_toggled_on (keyState))
    return false;

  if (!OneShotMods.isActive () &&
      !OneShotLayers.isActive ())
    return false;

  OneShotMods.cancel ();
  OneShotLayers.cancel ();

  return true;
}

static void tapDanceTMUX (uint8_t tapCount, Akela::TapDance::ActionType tapDanceAction) {
  if (tapDanceAction != Akela::TapDance::Release)
    return;

  Key key;

  if (tapCount == 1) {
    key.flags = KEY_FLAGS | LALT_HELD;
    key.rawKey = Key_Space.rawKey;
  } else {
    key.flags = KEY_FLAGS | CTRL_HELD;
    key.rawKey = Key_A.rawKey;
  }

  press_key (key);
  Keyboard.sendReport ();
  release_key (key);
  Keyboard.sendReport ();
}

static void tapDanceTMUXPane (uint8_t tapCount, Akela::TapDance::ActionType tapDanceAction) {
  if (tapDanceAction != Akela::TapDance::Release)
    return;

  Key key;

  // Alt + Space
  key.flags = KEY_FLAGS | LALT_HELD;
  key.raw = Key_Space.rawKey;
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

static void tapDanceHUNLeader (uint8_t tapCount, Akela::TapDance::ActionType tapDanceAction) {
  uint8_t keyState = 0;

  switch (tapDanceAction) {
  case Akela::TapDance::Release:
    keyState = WAS_PRESSED;
    break;
  case Akela::TapDance::Timeout:
  case Akela::TapDance::Interrupt:
    keyState = IS_PRESSED;
    break;
  case Akela::TapDance::Hold:
    keyState = IS_PRESSED | WAS_PRESSED;
    break;
  default:
    break;
  }

  if (keyState == 0)
    return;

  if (tapCount == 1)
    OneShotLayers.inject (OSL (_HUN), keyState);
  else if (tapCount == 2)
    Leader.inject (LEAD (0), keyState);
}

void tapDanceAction (uint8_t tapDanceIndex, uint8_t tapCount, Akela::TapDance::ActionType tapDanceAction) {
  switch (tapDanceIndex) {
  case TMUX:
    return tapDanceTMUX (tapCount, tapDanceAction);
  case TMUXP:
    return tapDanceTMUXPane (tapCount, tapDanceAction);

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

  case HLEAD:
    return tapDanceHUNLeader (tapCount, tapDanceAction);
  }
}

static void leaderGergo (uint8_t seqIndex) {
  Macros.play (MACRO (Tr(LSHIFT(Key_G)),
                      T(E),
                      T(J),
                      T(G),
                      Tr((Key){.raw = HUN_ODA}),
                      Tr((Key){.raw = HUN_ODA}),
                      Tr((Key){.raw = HUN_ODA}),
                      END));
}

static void leaderYay (uint8_t seqIndex) {
  Macros.play (MACRO (T(Backslash),
                      T(O),
                      T(Slash),
                      END));
}

static void leaderShruggy (uint8_t seqIndex) {
  Unicode.type (0xaf);
  Macros.play (MACRO (T(Backslash),
                      D(RShift),
                      T(Minus),
                      T(9),
                      U(RShift),
                      END));
  Unicode.type (0x30c4);
  Macros.play (MACRO (D(RShift),
                      T(0),
                      T(Minus),
                      U(RShift),
                      T(Slash),
                      END));
  Unicode.type (0xaf);
}

// Leaders
enum {
  LEAD_UNICODE_LAMBDA,
  LEAD_UNICODE_POOP,
  LEAD_UNICODE_ROFL,
  LEAD_UNICODE_KISS,
  LEAD_UNICODE_SNOWMAN,
  LEAD_UNICODE_COFFEE,
  LEAD_UNICODE_HEART,
  LEAD_UNICODE_BOLT,
  LEAD_UNICODE_PI,
  LEAD_UNICODE_MOUSE,
  LEAD_UNICODE_MICRO,

  LEAD_UNICODE_START,

  LEAD_CSILLA,
  LEAD_GERGO,
  LEAD_YAY,
  LEAD_SHRUGGY,
};

static const uint32_t unicodeTable[] PROGMEM = {
  [LEAD_UNICODE_LAMBDA]  = 0x03bb,
  [LEAD_UNICODE_POOP]    = 0x1f4a9,
  [LEAD_UNICODE_ROFL]    = 0x1f923,
  [LEAD_UNICODE_KISS]    = 0x1f619,
  [LEAD_UNICODE_SNOWMAN] = 0x2603,
  [LEAD_UNICODE_COFFEE]  = 0x2615,
  [LEAD_UNICODE_HEART]   = 0x2764,
  [LEAD_UNICODE_BOLT]    = 0x26a1,
  [LEAD_UNICODE_PI]      = 0x03c0,
  [LEAD_UNICODE_MOUSE]   = 0x1f401,
  [LEAD_UNICODE_MICRO]   = 0x00b5,
};

static void leaderUnicode (uint8_t seqIndex) {
  if (seqIndex == LEAD_UNICODE_START)
    return Unicode.start ();

  uint32_t code = pgm_read_dword (unicodeTable[seqIndex]);
  Unicode.type_code (code);
  Unicode.end ();

  Leader.reset ();
}

static const Akela::Leader::dictionary_t leaderDictionary[] PROGMEM = LEADER_DICT
  (
   [LEAD_UNICODE_LAMBDA]  = {LEADER_SEQ (LEAD(0), Key_L), leaderUnicode},
   [LEAD_UNICODE_POOP]    = {LEADER_SEQ (LEAD(0), Key_U, Key_P, Key_O, Key_O, Key_P), leaderUnicode},
   [LEAD_UNICODE_ROFL]    = {LEADER_SEQ (LEAD(0), Key_U, Key_R, Key_O, Key_F, Key_L), leaderUnicode},
   [LEAD_UNICODE_KISS]    = {LEADER_SEQ (LEAD(0), Key_U, Key_K, Key_I, Key_S, Key_S), leaderUnicode},
   [LEAD_UNICODE_SNOWMAN] = {LEADER_SEQ (LEAD(0), Key_U, Key_S, Key_N, Key_O, Key_W, Key_M, Key_A, Key_N), leaderUnicode},
   [LEAD_UNICODE_COFFEE]  = {LEADER_SEQ (LEAD(0), Key_U, Key_C, Key_O, Key_F, Key_F, Key_E, Key_E), leaderUnicode},
   [LEAD_UNICODE_HEART]   = {LEADER_SEQ (LEAD(0), Key_U, Key_H, Key_E, Key_A, Key_R, Key_T), leaderUnicode},
   [LEAD_UNICODE_BOLT]    = {LEADER_SEQ (LEAD(0), Key_U, Key_B, Key_O, Key_L, Key_T), leaderUnicode},
   [LEAD_UNICODE_PI]      = {LEADER_SEQ (LEAD(0), Key_U, Key_P, Key_I), leaderUnicode},
   [LEAD_UNICODE_MOUSE]   = {LEADER_SEQ (LEAD(0), Key_U, Key_M, Key_O, Key_U, Key_S, Key_E), leaderUnicode},
   [LEAD_UNICODE_MICRO]   = {LEADER_SEQ (LEAD(0), Key_U, Key_M, Key_I, Key_C, Key_R, Key_O), leaderUnicode},

   [LEAD_UNICODE_START]   = {LEADER_SEQ (LEAD(0), Key_U), leaderUnicode},

   [LEAD_CSILLA]          = {LEADER_SEQ (LEAD(0), Key_C), (Akela::Leader::action_t) magicCsilla},
   [LEAD_GERGO]           = {LEADER_SEQ (LEAD(0), Key_G), leaderGergo},
   [LEAD_YAY]             = {LEADER_SEQ (LEAD(0), Key_Y), leaderYay},
   [LEAD_SHRUGGY]         = {LEADER_SEQ (LEAD(0), Key_S), leaderShruggy}
  );

static LEDOff                ledOffEffect;

void
setup () {
  ColormapEffect.configure (colors, colorMap);
  OneShotMods.enableAuto();
  OneShotLayers.enableAuto();
  Leader.configure (leaderDictionary);
  ShapeShifter.configure (shapeShifterDictionary);
  MagicCombo.configure (dictionary);

  event_handler_hook_add (handleEsc);

  Keyboardio.setup(KEYMAP_SIZE);
  ColormapEffect.activate ();
}

void
loop () {
  Keyboardio.loop();
}
