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

#define FOCUS_WITHOUT_DOCS 1

#include "Layers.h"
#include "Settings.h"
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-Focus.h>

namespace algernon {
  namespace Settings {
    static uint16_t base;

    static bool
    focusSettings (const char *command) {
      enum {
        CYCLETIMER_GET,
        CYCLETIMER_SET,
      } subCommand;

      if (strncmp_P (command, PSTR ("settings."), 9) != 0)
        return false;

      if (strncmp_P (command + 9, PSTR ("cycleTimer."), 11) == 0) {
        if (strcmp_P (command + 9 + 11, PSTR ("get")) == 0)
          subCommand = CYCLETIMER_GET;
        else if (strcmp_P (command + 9 + 11, PSTR ("set")) == 0)
          subCommand = CYCLETIMER_SET;
        else
          return false;
      } else
        return false;

      switch (subCommand) {
      case CYCLETIMER_GET:
        Serial.println ((settings.cycleTimer) ? F("on") : F("off"));
        break;

      case CYCLETIMER_SET:
        {
          uint8_t state = Serial.parseInt ();
          settings.cycleTimer = !!state;

          EEPROM.put (base, settings);
          break;
        }
      }

      Serial.read ();
      return true;
    }

    void
    configure (void) {
      USE_PLUGINS (&EEPROMSettings,
                   &EEPROMKeymap);

      EEPROMKeymap.reserveSpace (LAYER_MAX);
      base = EEPROMSettings.requestSlice (sizeof (settings));
      EEPROMSettings.seal ();

      if (!EEPROMSettings.isValid ()) {
        EEPROMSettings.version (0);
        EEPROMSettings.update ();
      }

      EEPROM.get (base, settings);

      Focus.addHook (FOCUS_HOOK (focusSettings,
                                 "settings.cycleTimer.get\n"
                                 "-----------------------\n"
                                 "Display the state of the cycle timer feature.\n\n"
                                 "settings.cycleTimer.set STATE\n"
                                 "-----------------------------\n"
                                 "Enable or disable the cycle timer."));
    }

    settings_ settings;
  }
}
