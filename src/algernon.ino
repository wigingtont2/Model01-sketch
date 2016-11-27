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

#include <Keyboardio-Macros.h>
#include <KeyboardioFirmware.h>
#include <Akela-OneShot.h>
#include <Akela-Colormap.h>
#include <Akela-KeyLogger.h>
#include <Akela-Heatmap.h>
#include <Akela-Unicode.h>
#include <Akela-MagicCombo.h>

#include <LED-Off.h>

// LAYERS

enum {
  _DVORAK,
  _ADORE,
  _NAV,
  _HUN
};

// MACROS
enum {
  M_1,
  M_2,
  M_3,
  M_4,
  M_5,
  M_6,
  M_7,
  M_8,
  M_9,
  M_0,
};

#define MO(layer) (Key){ KEY_FLAGS | SYNTHETIC | SWITCH_TO_KEYMAP, MOMENTARY_OFFSET + layer }

#define NIY Key_NoKey

const Key keymaps[][ROWS][COLS] PROGMEM = {
  [_DVORAK] = KEYMAP_STACKED
  (
    Key_F11       ,M(M_9)    ,M(M_7)    ,M(M_5)     ,M(M_3) ,M(M_1) ,NIY
   ,Key_Backtick  ,Key_Quote ,Key_Comma ,Key_Period ,Key_P  ,Key_Y  ,NIY
   ,Key_Tab       ,Key_A     ,Key_O     ,Key_E      ,Key_U  ,Key_I
   ,Key_playPause ,Key_Slash ,Key_Q     ,Key_J      ,Key_K  ,Key_X  ,Key_LAlt

   ,NIY ,Key_Backspace ,Key_LShift ,Key_Esc
   ,MO(_NAV)

   ,NIY       ,M(M_0) ,M(M_2) ,M(M_4) ,M(M_6) ,M(M_8) ,NIY
   ,NIY       ,Key_F  ,Key_G  ,Key_C  ,Key_R  ,Key_L  ,Key_Backslash
              ,Key_D  ,Key_H  ,Key_T  ,Key_N  ,Key_S  ,Key_Equals
   ,Key_LCtrl ,Key_B  ,Key_M  ,Key_W  ,Key_V  ,Key_Z  ,Key_stop

   ,Key_LGUI ,Key_Enter ,Key_Space ,Key_Minus
   ,MO(_HUN)
  ),

  [_ADORE] = KEYMAP_STACKED
  (
    Key_F11       ,M(M_9) ,M(M_7) ,M(M_5)     ,M(M_3)    ,M(M_1) ,NIY
   ,Key_Backslash ,Key_X  ,Key_W  ,Key_C      ,Key_H     ,Key_F  ,NIY
   ,Key_Tab       ,Key_A  ,Key_O  ,Key_E      ,Key_I     ,Key_U
   ,Key_playPause ,Key_Z  ,Key_Q  ,Key_Quote  ,Key_Comma ,Key_Period  ,Key_LAlt

   ,NIY ,Key_Backspace ,Key_LShift ,Key_Esc
   ,MO(_NAV)

   ,NIY       ,M(M_0) ,M(M_2) ,M(M_4) ,M(M_6) ,M(M_8)     ,NIY
   ,NIY       ,Key_M  ,Key_G  ,Key_L  ,Key_P  ,Key_Slash ,Key_Backslash
              ,Key_D  ,Key_R  ,Key_T  ,Key_N  ,Key_S     ,Key_Equals
   ,Key_LCtrl ,Key_B  ,Key_K  ,Key_V  ,Key_Y  ,Key_J     ,Key_stop

   ,Key_LGUI ,Key_Enter ,Key_Space ,Key_Minus
   ,MO(_HUN)
  ),

  [_NAV] = KEYMAP_STACKED
  (
    ___ ,Key_F9 ,Key_F7 ,Key_F5 ,Key_F3 ,Key_F1 ,XXX
   ,XXX ,XXX    ,XXX    ,XXX    ,XXX    ,XXX    ,XXX
   ,XXX ,XXX    ,XXX    ,XXX    ,XXX    ,XXX
   ,XXX ,XXX    ,XXX    ,XXX    ,XXX    ,XXX    ,___

   ,Key_volumeDown ,Key_volumeUp ,___ ,Key_volumeMute
   ,___

   ,NIY ,Key_F10 ,Key_F2     ,Key_F4      ,Key_F6     ,Key_F8 ,XXX
   ,XXX ,XXX     ,Key_Home   ,Key_UpArrow ,Key_End    ,XXX  ,XXX
        ,XXX     ,Key_LArrow ,Key_DnArrow ,Key_RArrow ,XXX  ,XXX
   ,___ ,XXX     ,XXX        ,XXX         ,XXX        ,XXX  ,XXX

   ,___ ,Key_PageDn ,Key_PageUp ,XXX
   ,___
  ),

  [_HUN] = KEYMAP_STACKED
  (
    XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,NIY ,XXX ,NIY ,XXX ,XXX
   ,XXX ,NIY ,NIY ,NIY ,NIY ,NIY
   ,XXX ,XXX ,NIY ,XXX ,NIY ,XXX ,XXX

   ,XXX ,___ ,___ ,___
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

const uint8_t colorMap[][ROWS][COLS] PROGMEM = {
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
};

static LEDOff                ledOffEffect;
static Akela::ColormapEffect colorMapEffect(colors, colorMap);
static Akela::Heatmap        heatMapEffect;

static Akela::OneShotMods    oneShotMods;
static Akela::OneShotLayers  oneShotLayers;
static Akela::Unicode        unicode;

static const macro_t *handleNumRow (uint8_t macroIndex, uint8_t keyState) {
  if (key_toggled_off (keyState))
    return MACRO_NONE;

  uint8_t kc = Key_1.rawKey;
  bool shifted = Keyboard.isModifierActive (Key_LShift.rawKey) ||
    Keyboard.isModifierActive (Key_RShift.rawKey);


  if (!shifted) {
    kc += macroIndex;
    return MACRO (MACRO_ACTION_STEP_KEYDOWN, kc, MACRO_ACTION_END);
  }

  switch (macroIndex) {
  case M_9:
  case M_8:
    return MACRO_NONE;
  case M_7:
    kc += 1;
    break;
  case M_5:
    kc += 7;
    break;
  case M_3:
    kc += 5;
    break;
  case M_1:
    kc += 3;
    break;

  case M_0:
    kc += 4;
    break;
  case M_2:
    kc += 0;
    break;
  case M_4:
    kc += 2;
    break;
  case M_6:
    kc += 6;
    break;
  }

  return MACRO (MACRO_ACTION_STEP_KEYDOWN, kc, MACRO_ACTION_END);
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case M_1 ... M_0:
    return handleNumRow (macroIndex, keyState);
  }

  return MACRO_NONE;
}

void
setup () {
  oneShotMods.enableAuto();
  oneShotLayers.enableAuto();

  Keyboardio.setup(KEYMAP_SIZE);
  colorMapEffect.activate ();
}

void
loop () {
  Keyboardio.loop();
}
