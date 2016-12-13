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

#include <Akela-Colormap.h>
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

    void
    configure (void) {
      Akela::USE (ColormapEffect);

      ColormapEffect.configure (colors, colorMap);
      ColormapEffect.activate ();
    }
  };
};
