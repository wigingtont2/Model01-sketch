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

#pragma once

enum {
  DVORAK,
  ADORE,
  NAV,
  HUN
};

static const uint16_t keymap[][64] PROGMEM = {
  [DVORAK] = KEYMAP (
   // left hand

   KC_F11     ,AM_9       ,AM_7       ,AM_5       ,AM_3       ,AM_1       ,TD(TC_TMX)
  ,KC_GRV     ,KC_QUOT    ,KC_COMM    ,KC_DOT     ,KC_P       ,KC_Y
  ,KC_TAB     ,KC_A       ,KC_O       ,KC_E       ,KC_U       ,KC_I       ,TD(TC_LPB)
  ,CC_PLPS    ,KC_SLSH    ,KC_Q       ,KC_J       ,KC_K       ,KC_X       ,OSM(LALT)

                   ,TD(TC_CLN) ,KC_BSPC    ,OSM(LSFT)  ,KC_ESC
                               ,OSL(NAV)

    // right hand

   ,TD(TC_TMXP),AM_0       ,AM_2       ,AM_4       ,AM_6       ,AM_8       ,AM_MNP
               ,KC_F       ,KC_G       ,KC_C       ,KC_R       ,KC_L       ,KC_BSLS
   ,TD(TC_RPB) ,KC_D       ,KC_H       ,KC_T       ,KC_N       ,KC_S       ,KC_EQL
   ,OSM(LCTL)  ,KC_B       ,KC_M       ,KC_W       ,KC_V       ,KC_Z       ,CC_STOP

                   ,TD(TC_GUI) ,KC_ENT     ,KC_SPC     ,KC_MINS
                               ,OSL(HUN)
  ),
  [ADORE] = KEYMAP (
   // left hand

   KC_F11     ,AM_9       ,AM_7       ,AM_5       ,AM_3       ,AM_1       ,TD(TC_TMX)
  ,KC_BSLS    ,KC_X       ,KC_W       ,KC_C       ,KC_H       ,KC_F
  ,KC_TAB     ,KC_A       ,KC_O       ,KC_E       ,KC_I       ,KC_U       ,TD(TC_LPB)
  ,CC_PLPS    ,KC_Z       ,KC_Q       ,KC_QUOT    ,KC_COMM    ,KC_DOT     ,OSM(LALT)

                   ,TD(TC_CLN) ,KC_BSPC    ,OSM(LSFT)  ,KC_ESC
                               ,OSL(NAV)

    // right hand

   ,TD(TC_TMXP),AM_0       ,AM_2       ,AM_4       ,AM_6       ,AM_8       ,AM_MNP
               ,KC_M       ,KC_G       ,KC_L       ,KC_P       ,KC_SLSH    ,KC_GRV
   ,TD(TC_RPB) ,KC_D       ,KC_R       ,KC_T       ,KC_N       ,KC_S       ,KC_EQL
   ,OSM(LCTL)  ,KC_B       ,KC_K       ,KC_V       ,KC_Y       ,KC_J       ,CC_STOP

                   ,TD(TC_GUI) ,KC_ENT     ,KC_SPC     ,KC_MINS
                               ,OSL(HUN)
  ),
  [NAV] = KEYMAP (
   // left hand

   KC_NO      ,KC_F9      ,KC_F7      ,KC_F5      ,KC_F3      ,KC_F1      ,KC_NO
  ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO
  ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO
  ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,OSM(LALT)

                   ,CC_VDN     ,CC_VUP     ,OSM(LSFT)  ,CC_MUTE
                               ,KC_NO

    // right hand

   ,LGUI(KC_L) ,KC_F10     ,KC_F2      ,KC_F4      ,KC_F6      ,KC_F8      ,KC_NO
               ,KC_NO      ,KC_HOME    ,KC_UP      ,KC_END     ,KC_NO      ,KC_NO
   ,KC_NO      ,KC_NO      ,KC_LEFT    ,KC_DOWN    ,KC_RGHT    ,KC_NO      ,KC_NO
   ,OSM(LCTL)  ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO

                   ,KC_NO      ,KC_PGDN    ,KC_PGUP    ,KC_NO
                               ,KC_NO
  ),
  [HUN] = KEYMAP (
   // left hand

   KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO
  ,KC_NO      ,KC_NO      ,HU_OEE     ,KC_NO      ,HU_UEE     ,KC_NO
  ,KC_NO      ,HU_AA      ,HU_OO      ,HU_EE      ,HU_UU      ,HU_II      ,KC_NO
  ,KC_NO      ,KC_NO      ,HU_OE      ,KC_NO      ,HU_UE      ,KC_NO      ,KC_NO

                   ,KC_NO      ,KC_NO      ,OSM(LSFT)  ,KC_ESC
                               ,KC_NO

    // right hand

   ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO
               ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO
   ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO
   ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO

                   ,KC_NO      ,OSM(LSFT)  ,KC_NO      ,KC_NO
                               ,KC_NO
  ),

};
