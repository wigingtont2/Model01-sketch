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

#include "Focus.h"

#define FOCUS_WITHOUT_DOCS 1

#include <Kaleidoscope-Focus.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>

namespace algernon {
  namespace FocusSetup {
    static bool led (const char *command) {
      enum {
        GET,
        SET,
        SETALL,
        OFF,
        NEXTMODE,
        MODE,
      } subCommand;

      if (strncmp_P (command, PSTR ("led."), 4) != 0)
        return false;
      if (strcmp_P (command + 4, PSTR ("get")) == 0)
        subCommand = GET;
      else if (strcmp_P (command + 4, PSTR ("set")) == 0)
        subCommand = SET;
      else if (strcmp_P (command + 4, PSTR ("setAll")) == 0)
        subCommand = SETALL;
      else if (strcmp_P (command + 4, PSTR ("off")) == 0)
        subCommand = OFF;
      else if (strcmp_P (command + 4, PSTR ("nextMode")) == 0)
        subCommand = NEXTMODE;
      else if (strcmp_P (command + 4, PSTR ("mode")) == 0)
        subCommand = MODE;
      else
        return false;

      switch (subCommand) {
      case GET:
        {
          uint8_t idx = Serial.parseInt ();
          cRGB c = LEDControl.led_get_crgb_at (idx);
          const __FlashStringHelper *spc = F(" ");

          Serial.print (c.r);
          Serial.print (spc);
          Serial.print (c.g);
          Serial.print (spc);
          Serial.println (c.b);
          break;
        }
      case SET:
        {
          uint8_t idx = Serial.parseInt ();
          cRGB c;

          c.r = Serial.parseInt ();
          c.g = Serial.parseInt ();
          c.b = Serial.parseInt ();

          LEDControl.led_set_crgb_at (idx, c);
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
      case OFF:
        LEDControl.set_all_leds_to (0, 0, 0);
        break;
      case NEXTMODE:
        LEDControl.next_mode ();
        break;
      case MODE:
        {
          uint8_t mode = Serial.parseInt ();

          LEDControl.set_mode (mode);
          break;
        }
      }

      Serial.read ();
      return true;
    }

    void configure (void) {
      USE_PLUGINS (&Focus, &EEPROMSettings, &EEPROMKeymap);

      if (EEPROMSettings.isValid ()) {
        EEPROMSettings.version (0);
        EEPROMSettings.update ();
      }

      Focus.addHook (FOCUS_HOOK_HELP);
      Focus.addHook (FOCUS_HOOK_VERSION);
      Focus.addHook (FOCUS_HOOK_KEYMAP);
      Focus.addHook (FOCUS_HOOK (led,
                                 "led.set index r g b\n"
                                 "-------------------\n"
                                 "Set the led at `index` to the color described with `r`, `g`, and `b`.\n\n"
                                 "led.setAll r g b\n"
                                 "----------------\n"
                                 "Set all leds to the color described with `r`, `g`, and `b`.\n\n"
                                 "led.get index\n"
                                 "-------------\n"
                                 "Return the color of the LED at the `index` position, in `r g b` format.\n\n"
                                 "led.nextMode\n"
                                 "------------\n"
                                 "Moves on to the next LED effect mode.\n\n"
                                 "led.mode N\n"
                                 "----------\n"
                                 "Switches to LED effect mode `n`.\n\n"
                                 "led.off\n"
                                 "-------\n"
                                 "Turn all LEDs off."));
      Focus.addHook (FOCUS_HOOK_SETTINGS);
    }
  };
};
