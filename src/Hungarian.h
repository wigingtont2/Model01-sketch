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

#include <Akela-Core.h>

enum {
  HUNGARIAN_FIRST = Akela::Ranges::AKELA_SAFE_START,
  HUN_AA = HUNGARIAN_FIRST,
  HUN_OA,
  HUN_OU,
  HUN_ODA,
  HUN_EA,
  HUN_UA,
  HUN_UU,
  HUN_UDA,
  HUN_IA,
  HUNGARIAN_LAST = HUN_IA,
};

class Hungarian_ : public KeyboardioPlugin {
 public:
  Hungarian_ (void);

  virtual void begin (void) final;
};

static Hungarian_ Hungarian;
