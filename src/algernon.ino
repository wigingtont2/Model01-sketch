/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016, 2017, 2018  Gergely Nagy
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

#include "00-config.h"

#include <Kaleidoscope.h>

#include "LED-Off.h"
#include <Kaleidoscope-Colormap.h>
#include <Kaleidoscope-CycleTimeReport.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Escape-OneShot.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
#include <Kaleidoscope-LED-ActiveModColor.h>
#include <Kaleidoscope-LED-Stalker.h>
#if WITH_MATRIX_EFFECT
# include <Kaleidoscope-LEDEffect-DigitalRain.h>
#endif
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LangPack-Hungarian.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-MouseKeys.h>
#include <Kaleidoscope-Steno.h>
#include <Kaleidoscope-Syster.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-MagicCombo.h>
#include "MouseWrapper.h"

#include "Layers.h"

#include "Colormap.h"
#include "FocusCycleTime.h"
#include "Leader.h"
#include "MagicCombo.h"
#include "Syster.h"
#include "TapDance.h"

#include "keymap.h"

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  if (macroIndex == F11) {
    if (!keyToggledOff(keyState))
      return MACRO_NONE;
    return MACRO(T(F11));
  }

  if (!keyToggledOn(keyState))
    return MACRO_NONE;

  switch (macroIndex) {
  case APPSEL_MUSIC ... APPSEL_PWMGR:
    Serial.print(F("appsel:"));
    break;
  }

  switch (macroIndex) {
  case APPSEL_MUSIC:
    Serial.println(F("music"));
    break;
  case APPSEL_CHAT:
    Serial.println(F("chat"));
    break;
  case APPSEL_EMACS:
    Serial.println(F("emacs"));
    break;
  case APPSEL_TERM:
    Serial.println(F("term"));
    break;
  case APPSEL_WEB:
    Serial.println(F("web"));
    break;
  case APPSEL_SOC:
    Serial.println(F("social"));
    break;
  case APPSEL_SOC2:
    Serial.println(F("social2"));
    break;
  case APPSEL_PWMGR:
    Serial.println(F("pwmgr"));
    break;
  }
  return MACRO_NONE;
}

KALEIDOSCOPE_INIT_PLUGINS(
  Focus,
  LEDControl,
  LEDOff,
#if WITH_STALKER_EFFECT
  StalkerEffect,
#endif
#if WITH_MATRIX_EFFECT
  LEDDigitalRainEffect,
#endif
  HostOS,
  EEPROMSettings,
  EEPROMKeymap,
  LEDPaletteTheme,
  ColormapEffect,
  Leader,
  Unicode,
  TapDance,
  OneShot,
  Syster,
  MagicCombo,
  EscapeOneShot,
#if WITH_STENO
  GeminiPR,
#endif
  Macros,
  Hungarian,
  MouseKeys,
  ActiveModColorEffect,
#if WITH_LED_FOCUS
  FocusLEDCommand,
#endif
  FocusSettingsCommand,
  FocusEEPROMCommand,
  FocusHostOSCommand
#if WITH_CYCLE_REPORT
  , FocusCycleTime,
  CycleTimeReport
#endif
);

void setup() {
  Kaleidoscope.setup();

#if WITH_STALKER_EFFECT
  StalkerEffect.variant = STALKER(BlazingTrail);
#endif

  algernon::Colormap::configure();
  algernon::Leader::configure();

  MouseWrapper.speedLimit = 64;
  MouseKeys.speed = 15;
  MouseKeys.accelDelay = 35;

#if WITH_PROGMEM_KEYMAP
  EEPROMKeymap.setup(LAYER_MAX - 1);
  layer_count++;
#else
  EEPROMKeymap.max_layers(LAYER_MAX - 1);
  Layer.getKey = EEPROMKeymap.getKey;
  layer_count = LAYER_MAX + 1;
#endif
}

void loop() {
  Kaleidoscope.loop();

  if (algernon::TapDance::cancelOneShot) {
    if (!Layer.isOn(_APPSEL))
      OneShot.cancel();
    algernon::TapDance::cancelOneShot = false;
  }

  if (Layer.isOn(_PLOVER)) {
    LEDControl.set_all_leds_to(CRGB(0x56, 0x80, 0x78));
  }
  if (Layer.isOn(_EMPTY)) {
    LEDControl.set_all_leds_to(CRGB(0x0, 0x0, 0x0));
  }
}
