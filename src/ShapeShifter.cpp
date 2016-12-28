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

#include "ShapeShifter.h"

namespace algernon {
  namespace ShapeShifter {
    static const Akela::ShapeShifter::dictionary_t dictionary[] = {
      {Key_9, Key_NoKey},
      {Key_7, Key_2},
      {Key_5, Key_8},
      {Key_3, Key_6},
      {Key_1, Key_4},

      {Key_0, Key_5},
      {Key_2, Key_1},
      {Key_4, Key_3},
      {Key_6, Key_7},
      {Key_8, Key_NoKey},

      {Key_NoKey, Key_NoKey},
    };

    void
    configure (void) {
      ::ShapeShifter.configure (dictionary);

      Keyboardio.use (&::ShapeShifter, NULL);
    }
  };
};
