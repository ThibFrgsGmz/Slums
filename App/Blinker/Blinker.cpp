// ======================================================================
// \title  Blinker.cpp
// \author @astroesteban
// \brief  cpp file for Blinker component implementation class
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
// ----------------------------------------------------------------------
// Construction, initialization, and destruction
// ----------------------------------------------------------------------

Blinker::Blinker(const char *const compName)
    : BlinkerComponentBase(compName), m_pin(0), m_state(false) {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void Blinker::schedIn_handler(const NATIVE_INT_TYPE portNum,
                              NATIVE_UINT_TYPE context) {
  blinkLED();
  m_state = !m_state;
}
}  // end namespace App
