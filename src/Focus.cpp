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

#include "Focus.h"

#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope-Focus.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LED-Palette-Theme.h>
#include <Kaleidoscope-Colormap.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>

namespace algernon {
namespace FocusSetup {

void configure(void) {
  Focus.addHook(FOCUS_HOOK_HELP);
  Focus.addHook(FOCUS_HOOK_VERSION);
  Focus.addHook(FOCUS_HOOK_HOSTOS);
  Focus.addHook(FOCUS_HOOK_KEYMAP);
#if WITH_PROGMEM_KEYMAP
  Focus.addHook(FOCUS_HOOK_KEYMAP_TRANSFER);
#endif
  Focus.addHook(FOCUS_HOOK_EEPROM);
  Focus.addHook(FOCUS_HOOK_KALEIDOSCOPE);
  Focus.addHook(FOCUS_HOOK_LEDPALETTETHEME);
  Focus.addHook(FOCUS_HOOK_COLORMAP);
#if WITH_LED_FOCUS
  Focus.addHook(FOCUS_HOOK_LEDCONTROL);
#endif
  Focus.addHook(FOCUS_HOOK_SETTINGS);
}

}
}
