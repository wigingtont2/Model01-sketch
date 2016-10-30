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

#include <Akela-Model01.h>
#include <Akela-TapDance.h>

enum {
  AM_1 = FM(0),
  AM_2,
  AM_3,
  AM_4,
  AM_5,
  AM_6,
  AM_7,
  AM_8,
  AM_9,
  AM_0,

  HU_AA,
  HU_OO,
  HU_OE,
  HU_OEE,
  HU_EE,
  HU_UU,
  HU_UE,
  HU_UEE,
  HU_II,

  AM_MNP,
};

enum {
  TC_TMX,
  TC_TMXP,

  TC_LPB,
  TC_RPB,

  TC_CLN,

  TC_GUI,
};

namespace algernon {
  class EventHandler :
    public M01::EventHandler::Full,
    public Akela::TapDance::Component::OneShotMod,
    public Akela::TapDance::Component::OneShotLayer,
    public Akela::TapDance::Component::TapDance {
  public:
    EventHandler (Akela::AbstractHID *hid, Akela::LayeredKeyMap *keymap,
                  M01::Scanner *scanner)
      : M01::EventHandler::Full (hid, keymap, scanner) {};

    using Akela::TapDance::Component::OneShotMod::press;
    using Akela::TapDance::Component::OneShotLayer::press;
    using Akela::TapDance::Component::TapDance::press;
    virtual void press (uint8_t index);

    using Akela::TapDance::Component::OneShotMod::release;
    using Akela::TapDance::Component::OneShotLayer::release;
    using Akela::TapDance::Component::TapDance::release;
    virtual void release (uint8_t index);

    virtual void loop ();

    virtual void macroAction (Akela::AbstractHID *hid,
                              Akela::KeyMap *keymap,
                              uint8_t macroIndex,
                              bool pressed);

    virtual void tapDanceCycle (Akela::AbstractHID *,
                                Akela::KeyMap *,
                                uint8_t,
                                uint8_t) {};
    virtual void tapDanceFinish (Akela::AbstractHID *hid,
                                 Akela::KeyMap *keymap,
                                 uint8_t tapIndex,
                                 uint8_t counter);
    virtual void tapDanceRelease (Akela::AbstractHID *hid,
                                  Akela::KeyMap *keymap,
                                  uint8_t tapIndex,
                                  uint8_t counter);

  private:
    using Akela::TapDance::Component::OneShotMod::loop;
    using Akela::TapDance::Component::TapDance::loop;

    void handleNums (Akela::AbstractHID *hid,
                     uint8_t macroIndex,
                     bool pressed);
    void handleHun (Akela::AbstractHID *hid,
                    uint8_t macroIndex,
                    bool pressed);
    void handleMediaPrevNext (Akela::AbstractHID *hid,
                              bool pressed);
  };
};
