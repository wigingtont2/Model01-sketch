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

#include "00-config.h"

#include "Focus.h"

#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope-Focus.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>

namespace algernon {
  namespace FocusSetup {
    static bool led (const char *command) {
      enum {
        SETALL,
        MODE,
        AT
      } subCommand;

      if (strncmp_P (command, PSTR ("led."), 4) != 0)
        return false;
      if (strcmp_P (command + 4, PSTR ("at")) == 0)
        subCommand = AT;
      else if (strcmp_P (command + 4, PSTR ("setAll")) == 0)
        subCommand = SETALL;
      else if (strcmp_P (command + 4, PSTR ("mode")) == 0)
        subCommand = MODE;
      else
        return false;

      switch (subCommand) {
      case AT:
        {
          uint8_t idx = Serial.parseInt ();

          if (Serial.peek () == '\n') {
            cRGB c = LEDControl.led_get_crgb_at (idx);

            Focus.printColor (c);
            Serial.println ();
          } else {
            cRGB c;

            c.r = Serial.parseInt ();
            c.g = Serial.parseInt ();
            c.b = Serial.parseInt ();

            LEDControl.led_set_crgb_at (idx, c);
          }
          break;
        }
      case SETALL:
        {
          cRGB c;

          c.r = Serial.parseInt ();
          c.g = Serial.parseInt ();
          c.b = Serial.parseInt ();

          LEDControl.set_all_leds_to (c);

          break;
        }
      case MODE:
        {
          char peek = Serial.peek ();
          if (peek == '\n') {
            Serial.println (LEDControl.get_mode ());
          } else if (peek == 'n') {
            LEDControl.next_mode ();
            Serial.read ();
          } else if (peek == 'p') {
            // TODO
            Serial.read ();
          } else {
            uint8_t mode = Serial.parseInt ();

            LEDControl.set_mode (mode);
          }
          break;
        }
      }

      Serial.read ();
      return true;
    }

    void configure (void) {
      USE_PLUGINS (&Focus, &EEPROMSettings, &EEPROMKeymap);

      Focus.addHook (FOCUS_HOOK_HELP);
      Focus.addHook (FOCUS_HOOK_VERSION);
      Focus.addHook (FOCUS_HOOK_HOSTOS);
      Focus.addHook (FOCUS_HOOK_KEYMAP);
      Focus.addHook (FOCUS_HOOK_EEPROM);
      Focus.addHook (FOCUS_HOOK (led,
                                 "led.at POS [r g b]\n"
                                 "------------------\n"
                                 "Either display, or set the color of the LED at `POS`, depending on whether the `r`, `g`, and `b` color values are specified.\n\n"
                                 "led.setAll r g b\n"
                                 "----------------\n"
                                 "Set all leds to the color described with `r`, `g`, and `b`.\n\n"
                                 "led.mode [n|p|MODE]\n"
                                 "----------\n"
                                 "Switches to LED effect mode to either the next (if `n` is the argument), the previous (`p`), or to `MODE` if a number is given. Displays the current mode index without arguments."));
      Focus.addHook (FOCUS_HOOK_SETTINGS);
    }
  };
};
