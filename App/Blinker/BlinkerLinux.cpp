/**
 * @file BlinkerLinux.cpp
 * @author Esteban Duran (@astroesteban)
 * @brief A Linux-based blinker implementation for off-target testing
 * @version 0.1.0
 * @date 2022-03-02
 *
 */
#include <iostream>

#include "App/Blinker/Blinker.hpp"
#include "Fw/Types/BasicTypes.hpp"

namespace App {
void Blinker::init(const NATIVE_INT_TYPE instance) {
  BlinkerComponentBase::init(instance);
}

void Blinker::blinkLED() {
  static U64 s_counter = 0;

  if ((s_counter % 10) == 0) {
    std::cout << "Setting " << m_pin << " to " << std::boolalpha << m_state
              << "\n";
  }

  ++s_counter;
}
}  // end namespace App