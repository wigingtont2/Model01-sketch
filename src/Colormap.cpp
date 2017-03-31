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

#include "00-config.h"

#if WITH_PROGMEM_COLORMAP
#  include <Kaleidoscope-Colormap.h>
#else
#  include <Kaleidoscope-EEPROM-Colormap.h>
#  include <Kaleidoscope-Focus.h>
#endif

#include "Layers.h"

namespace algernon {
  namespace Colormap {

#if WITH_PROGMEM_COLORMAP
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
      GREEN,
      PINK,
      MGNT,

      TRNS = KaleidoscopePlugins::ColormapEffect::Transparent,
    };

    static const cRGB colors[] PROGMEM = {
      [OFF]         = {0x00, 0x00, 0x00},
      [FAINT_RED]   = {0x00, 0x00, 0x40},
      [FAINT_GREEN] = {0x00, 0x40, 0x00},
      [FAINT_BLUE]  = {0x40, 0x00, 0x00},
      [CYAN]        = {0xff, 0x88, 0x00},
      [RED]         = {0x00, 0x00, 0xff},
      [BLUE]        = {0xff, 0x00, 0x00},
      [NAVY]        = {0x80, 0x00, 0x00},
      [YELLOW]      = {0x00, 0xff, 0xff},
      [GREEN]       = {0x00, 0xff, 0x00},
      [PINK]        = {0x80, 0x80, 0xff},
      [MGNT]        = {0xcc, 0x33, 0xff},
    };

    static const uint8_t colorMap[LAYER_MAX][ROWS][COLS] PROGMEM = {
      [_DVORAK] = KEYMAP_STACKED
      (
        OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,FAINT_BLUE

       ,OFF ,OFF ,FAINT_RED ,OFF
       ,CYAN

       ,OFF         ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF         ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
                    ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,FAINT_GREEN ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF

       ,OFF ,OFF ,OFF ,OFF
       ,RED
       ),

      [_ADORE] = KEYMAP_STACKED
      (
        OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,FAINT_BLUE

       ,OFF ,OFF ,FAINT_RED ,OFF
       ,CYAN

       ,OFF         ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF         ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
                    ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,FAINT_GREEN ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF

       ,OFF ,OFF ,OFF ,OFF
       ,RED
       ),

      [_NAV] = KEYMAP_STACKED
      (
        CYAN ,CYAN   ,CYAN  ,CYAN   ,CYAN ,CYAN ,TRNS
       ,TRNS ,YELLOW ,GREEN ,YELLOW ,PINK ,PINK ,PINK
       ,TRNS ,GREEN  ,GREEN ,GREEN  ,PINK ,PINK
       ,TRNS ,TRNS   ,TRNS  ,TRNS   ,TRNS ,TRNS ,TRNS

       ,GREEN ,GREEN ,TRNS ,TRNS
       ,TRNS

       ,PINK ,CYAN   ,CYAN ,CYAN ,CYAN ,CYAN ,TRNS
       ,TRNS ,YELLOW ,MGNT ,BLUE ,MGNT ,TRNS ,TRNS
             ,YELLOW ,BLUE ,BLUE ,BLUE ,TRNS ,TRNS
       ,TRNS ,TRNS   ,MGNT ,TRNS ,MGNT ,TRNS ,TRNS

       ,MGNT ,TRNS ,TRNS ,MGNT
       ,TRNS
       ),

      [_AUX] = KEYMAP_STACKED
      (
        TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS ,TRNS ,RED  ,TRNS ,RED  ,TRNS ,TRNS
       ,TRNS ,RED  ,RED  ,RED  ,RED  ,RED
       ,TRNS ,TRNS ,RED  ,TRNS ,RED  ,TRNS ,TRNS

       ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS

       ,TRNS ,TRNS  ,TRNS  ,TRNS  ,TRNS  ,TRNS ,TRNS
       ,TRNS ,TRNS  ,GREEN ,GREEN ,GREEN ,TRNS ,TRNS
             ,GREEN ,GREEN ,GREEN ,GREEN ,TRNS ,TRNS
       ,TRNS ,TRNS  ,GREEN ,GREEN ,GREEN ,TRNS ,TRNS

       ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS
       ),

      [_APPSEL] = KEYMAP_STACKED
      (
        TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS

       ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS

       ,TRNS ,TRNS ,TRNS   ,TRNS   ,TRNS   ,TRNS ,TRNS
       ,TRNS ,TRNS ,TRNS   ,TRNS   ,TRNS   ,TRNS ,TRNS
             ,TRNS ,YELLOW ,YELLOW ,YELLOW ,TRNS ,TRNS
       ,TRNS ,TRNS ,YELLOW ,TRNS   ,YELLOW ,TRNS ,TRNS

       ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS
       ),

      [_EMPTY] = KEYMAP_STACKED
      (
        OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF

       ,OFF ,OFF ,OFF ,OFF
       ,OFF

       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
            ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF
       ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF ,OFF

       ,OFF ,OFF ,OFF ,OFF
       ,OFF
      ),

    };
#endif

    void
    configure (void) {

#if WITH_PROGMEM_COLORMAP
      Kaleidoscope.use (&ColormapEffect, NULL);

      ColormapEffect.configure (colors, colorMap);
      ColormapEffect.activate ();
#else
      Kaleidoscope.use (&EEPROMColormapEffect, NULL);
      EEPROMColormapEffect.configure (LAYER_MAX);
      EEPROMColormapEffect.activate ();

# if WITH_COLORMAP_FOCUS
      Focus.addHook (FOCUS_HOOK_COLORMAP);
# endif
#endif
    }
  };
};
