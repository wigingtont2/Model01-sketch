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

#include <Kaleidoscope-Colormap.h>
#include "Layers.h"

namespace algernon {
  namespace Colormap {

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
    };

    static const uint8_t colorMap[LAYER_MAX][ROWS][COLS] PROGMEM = {
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
        CYAN ,CYAN  ,CYAN  ,CYAN  ,CYAN ,CYAN ,TRNS
       ,TRNS ,TRNS  ,GREEN ,TRNS  ,PINK ,PINK ,PINK
       ,TRNS ,GREEN ,GREEN ,GREEN ,PINK ,PINK
       ,TRNS ,TRNS  ,TRNS  ,TRNS  ,TRNS ,TRNS ,TRNS

       ,YELLOW ,YELLOW ,TRNS ,YELLOW
       ,TRNS

       ,RED  ,CYAN ,CYAN ,CYAN ,CYAN ,CYAN ,TRNS
       ,TRNS ,TRNS ,NAVY ,BLUE ,NAVY ,TRNS ,TRNS
             ,TRNS ,BLUE ,BLUE ,BLUE ,TRNS ,TRNS
       ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS

       ,GREEN ,NAVY ,NAVY ,GREEN
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

       ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS ,TRNS
       ,TRNS ,TRNS ,CYAN ,CYAN ,CYAN ,TRNS ,TRNS
             ,TRNS ,CYAN ,CYAN ,CYAN ,CYAN ,TRNS
       ,TRNS ,TRNS ,CYAN ,CYAN ,CYAN ,TRNS ,TRNS

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
      [_APPSEL] = KEYMAP_STACKED
      (
        TRNS ,YELLOW ,YELLOW ,YELLOW ,YELLOW ,YELLOW ,TRNS
       ,TRNS ,TRNS   ,TRNS   ,TRNS   ,TRNS   ,TRNS   ,TRNS
       ,TRNS ,TRNS   ,TRNS   ,TRNS   ,TRNS   ,TRNS
       ,TRNS ,TRNS   ,TRNS   ,TRNS   ,TRNS   ,TRNS   ,TRNS

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

    void
    configure (void) {
      Kaleidoscope.use (&ColormapEffect, NULL);
      ColormapEffect.configure (colors, colorMap);
      ColormapEffect.activate ();
    }
  };
};
