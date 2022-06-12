// ======================================================================
// \title  BlinkerTiva.cpp
// \author @astroesteban
// \brief  Tiva-specific implementation of Blinker
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <App/Blinker/Blinker.hpp>

#include "Fw/Types/BasicTypes.hpp"

namespace App {
void Blinker::init(const NATIVE_INT_TYPE instance) {
  BlinkerComponentBase::init(instance);

  // todo: initialize the Tiva's onboard LED
}

void Blinker::blinkLED() {
  // todo: Blink the LED
}
}  // end namespace App