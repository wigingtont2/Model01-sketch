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

#include <Akela-OneShot.h>
#include <Akela-Colormap.h>
#include <Akela-KeyLogger.h>
#include <Akela-Heatmap.h>
#include <Akela-Unicode.h>
#include <Akela-MagicCombo.h>
#include <Akela-ShapeShifter.h>

#include <LED-Off.h>

#define Dr(k) MACRO_ACTION_STEP_KEYDOWN, k >> 8, (k << 8) >> 8
#define Ur(k) MACRO_ACTION_STEP_KEYUP, k >> 8, (k << 8) >> 8
#define Tr(k) Dr(k), Ur(k)

#include "Hungarian.h"

// LAYERS

enum {
  _DVORAK,
  _ADORE,
  _NAV,
  _HUN,
  _EMPTY
};

// MACROS
enum {
  M_LOCK,
};

#define MO(layer) (Key){ KEY_FLAGS | SYNTHETIC | SWITCH_TO_KEYMAP, MOMENTARY_OFFSET + layer }
#define R(n) (Key){.raw = n}
#define MW(d) Key_mouseWarp ## d

#define NIY Key_NoKey

const Key keymaps[][ROWS][COLS] PROGMEM = {
  [_DVORAK] = KEYMAP_STACKED
  (
    Key_F11       ,Key_9     ,Key_7     ,Key_5      ,Key_3 ,Key_1 ,NIY
   ,Key_Backtick  ,Key_Quote ,Key_Comma ,Key_Period ,Key_P ,Key_Y ,NIY
   ,Key_Tab       ,Key_A     ,Key_O     ,Key_E      ,Key_U ,Key_I
   ,Key_playPause ,Key_Slash ,Key_Q     ,Key_J      ,Key_K ,Key_X ,Key_LAlt

   ,NIY ,Key_Backspace ,Key_LShift ,Key_Esc
   ,MO(_NAV)

   ,NIY       ,Key_0 ,Key_2 ,Key_4 ,Key_6 ,Key_8 ,NIY
   ,NIY       ,Key_F ,Key_G ,Key_C ,Key_R ,Key_L ,Key_Backslash
              ,Key_D ,Key_H ,Key_T ,Key_N ,Key_S ,Key_Equals
   ,Key_LCtrl ,Key_B ,Key_M ,Key_W ,Key_V ,Key_Z ,Key_stop

   ,Key_LGUI ,Key_Enter ,Key_Space ,Key_Minus
   ,MO(_HUN)
  ),

  [_ADORE] = KEYMAP_STACKED
  (
    Key_F11       ,Key_9 ,Key_7 ,Key_5      ,Key_3     ,Key_1       ,NIY
   ,Key_Backslash ,Key_X ,Key_W ,Key_C      ,Key_H     ,Key_F       ,NIY
   ,Key_Tab       ,Key_A ,Key_O ,Key_E      ,Key_I     ,Key_U
   ,Key_playPause ,Key_Z ,Key_Q ,Key_Quote  ,Key_Comma ,Key_Period  ,Key_LAlt

   ,NIY ,Key_Backspace ,Key_LShift ,Key_Esc
   ,MO(_NAV)

   ,NIY       ,Key_0 ,Key_2 ,Key_4 ,Key_6 ,Key_8     ,NIY
   ,NIY       ,Key_M ,Key_G ,Key_L ,Key_P ,Key_Slash ,Key_Backslash
              ,Key_D ,Key_R ,Key_T ,Key_N ,Key_S     ,Key_Equals
   ,Key_LCtrl ,Key_B ,Key_K ,Key_V ,Key_Y ,Key_J     ,Key_stop

   ,Key_LGUI ,Key_Enter ,Key_Space ,Key_Minus
   ,MO(_HUN)
  ),

  [_NAV] = KEYMAP_STACKED
  (
    ___ ,Key_F9 ,Key_F7 ,Key_F5 ,Key_F3 ,Key_F1 ,XXX
   ,XXX ,XXX    ,XXX    ,XXX    ,MW(NW) ,MW(NE) ,XXX
   ,XXX ,XXX    ,XXX    ,XXX    ,MW(SW) ,MW(SE)
   ,XXX ,XXX    ,XXX    ,XXX    ,XXX    ,XXX    ,___

   ,Key_volumeDown ,Key_volumeUp ,___ ,Key_volumeMute
   ,___

   ,M(M_LOCK) ,Key_F10 ,Key_F2     ,Key_F4      ,Key_F6     ,Key_F8 ,XXX
   ,XXX       ,XXX     ,Key_Home   ,Key_UpArrow ,Key_End    ,XXX  ,XXX
              ,XXX     ,Key_LArrow ,Key_DnArrow ,Key_RArrow ,XXX  ,XXX
   ,___       ,XXX     ,XXX        ,XXX         ,XXX        ,XXX  ,XXX

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

static LEDOff                ledOffEffect;
static Akela::ColormapEffect colorMapEffect(colors, colorMap);
static Akela::Heatmap        heatMapEffect;

static Akela::OneShotMods    oneShotMods;
static Akela::OneShotLayers  oneShotLayers;
static Akela::Unicode        unicode;

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

static Akela::ShapeShifter shapeShifter (shapeShifterDictionary);

void magicToggleADORE (uint32_t leftHand, uint32_t rightHand) {
  if (Layer.isOn (_ADORE)) {
    Layer.defaultLayer (_DVORAK);
  } else {
    Layer.defaultLayer (_ADORE);
  }
}

void magicCsilla (uint32_t leftHand, uint32_t rightHand) {
  Macros.play (MACRO (D(LShift), T(C), U(LShift),
                      T(S),
                      T(I),
                      T(L),
                      T(L),
                      Tr(HUN_AA),
                      T(M),
                      T(A),
                      T(S),
                      T(S),
                      T(Z),
                      T(O),
                      T(N),
                      T(Y),
                      T(K),
                      Tr(HUN_AA),
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

Akela::MagicCombo magicCombos (dictionary);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case M_LOCK:
    return MACRO (D(LGUI), T(L), U(LGUI), END);
  }

  return MACRO_NONE;
}

static bool handleEsc (Key mappedKey, byte row, byte col, uint8_t keyState) {
  if (mappedKey.raw != Key_Esc.raw ||
      (keyState & INJECTED) ||
      !key_toggled_on (keyState))
    return false;

  if (!oneShotMods.isActive () &&
      !oneShotLayers.isActive ())
    return false;

  oneShotMods.cancel ();
  oneShotLayers.cancel ();

  return true;
}

void
setup () {
  oneShotMods.enableAuto();
  oneShotLayers.enableAuto();
  event_handler_hook_add (handleEsc);

  Keyboardio.setup(KEYMAP_SIZE);
  colorMapEffect.activate ();
}

void
loop () {
  Keyboardio.loop();
}
