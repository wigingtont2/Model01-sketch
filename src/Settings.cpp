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

#include "Layers.h"
#include "Settings.h"
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>

namespace algernon {

kaleidoscope::EventHandlerResult Settings::onSetup() {
  EEPROMKeymap.max_layers(LAYER_MAX - 1);
  base_ = EEPROMSettings.requestSlice(sizeof(settings));
  EEPROM.get(base_, settings);

  return kaleidoscope::EventHandlerResult::OK;
}

kaleidoscope::EventHandlerResult Settings::onFocusEvent(const char *command) {
#if WITH_CYCLE_REPORT
  if (strcmp_P(command, PSTR("help")) == 0) {
    Serial.println(F("settings.cycleTimer"));
    return kaleidoscope::EventHandlerResult::OK;
  }
  if (strcmp_P(command, PSTR("settings.cycleTimer")) != 0)
    return kaleidoscope::EventHandlerResult::OK;

  if (Serial.peek() != '\n') {
    uint8_t state = Serial.parseInt();
    settings.cycleTimer = !!state;

    EEPROM.put(base_, settings);
  }

  Focus.printBool(settings.cycleTimer);
  Serial.println();

  return kaleidoscope::EventHandlerResult::EVENT_CONSUMED;
#else
  return kaleidoscope::EventHandlerResult::OK;
#endif
}
}

algernon::Settings Settings;
