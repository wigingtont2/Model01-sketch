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

#define AKELA_HOSTOS_GUESSER 1

#include <Keyboardio-MouseKeys.h>
#include <KeyboardioFirmware.h>

#include <Akela-KeyLogger.h>
#include <Akela-IgnoranceIsBliss.h>

#include "LED-Off.h"
#include "LED-ChaseEffect.h"
#include "LED-RainbowEffect.h"

#include <Akela-LangPack-Hungarian.h>

#include "Layers.h"

#include "Colormap.h"
#include "Leader.h"
#include "OneShot.h"
#include "TapDance.h"
#include "ShapeShifter.h"
#include "MagicCombo.h"

using namespace Akela::LangPack;

#define R(n) (Key){.raw = n}
#define MW(d) Key_mouseWarp ## d

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
   ,Key_LCtrl ,Key_B ,Key_M ,Key_W ,Key_V ,Key_Z ,LEAD(MAIN)

   ,Key_LGUI ,Key_Enter ,Key_Space ,Key_Minus
   ,MO(_HUN)
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
   ,Key_LCtrl ,Key_B ,Key_K ,Key_V ,Key_Y ,Key_J     ,LEAD(MAIN)

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

static Key handleEsc (Key mappedKey, byte row, byte col, uint8_t keyState) {
  if (mappedKey.raw != Key_Esc.raw ||
      (keyState & INJECTED) ||
      !key_toggled_on (keyState))
    return mappedKey;

  if (!algernon::OneShot::isActive ())
    return mappedKey;

  algernon::OneShot::cancel ();

  return Key_NoKey;
}

static void activeModColorHook (bool postClear) {
  if (postClear)
    return;

  for (byte r = 0; r < ROWS; r++) {
    for (byte c = 0; c < COLS; c++) {
      Key k = Layer.lookup (r, c);

      if (k.raw >= Akela::Ranges::OSM_FIRST && k.raw <= Akela::Ranges::OSM_LAST) {
        uint8_t idx = k.raw - Akela::Ranges::OSM_FIRST;
        k.flags = 0;
        k.keyCode = Key_LCtrl.keyCode + idx;
      }

      if (k.raw < Key_LCtrl.raw || k.raw > Key_RGUI.raw)
        continue;

      if (Keyboard.isModifierActive (k.keyCode))
        led_set_crgb_at (r, c, (cRGB) {0xff, 0xff, 0xff});
    }
  }
}

void setup () {
  Serial.begin(9600);

  IgnoranceIsBliss.configure (R2C6 | R0C6, 0);
  Keyboardio.use (&IgnoranceIsBliss, NULL);

  //Keyboardio.use (&KeyLogger, NULL);

  algernon::TapDance::configure ();
  algernon::Leader::configure ();
  algernon::OneShot::configure ();
  algernon::ShapeShifter::configure ();
  algernon::MagicCombo::configure ();

  Keyboardio.use (&Hungarian, NULL);

  event_handler_hook_add (handleEsc);

  Keyboardio.setup (KEYMAP_SIZE);

  Keyboardio.use (&LEDOff, &LEDRainbowWaveEffect, &LEDChaseEffect,
                  //&HeatmapEffect,

                  NULL);

  algernon::Colormap::configure ();

  loop_hook_add (activeModColorHook);
}

void loop () {
  Keyboardio.loop();
}
