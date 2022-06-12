/**
 * @file Blinker.hpp
 * @author Esteban Duran (@astroesteban)
 * @brief Implements the capability to blink the Tiva's onboard LED
 * @version 0.1
 * @date 2022-04-17
 *
 */

#ifndef Blinker_HPP
#define Blinker_HPP

#include "App/Blinker/BlinkerComponentAc.hpp"

/**
 * @brief The App namespace contains all of the App app's
 * related components, ports, types and unit tests.
 */
namespace App {
/**
 * @brief The Blinker class is a passive component that is used to blink an
 * LED.
 */
class Blinker final : public BlinkerComponentBase {
 public:
  /**
   * @brief Construct the Blinker object
   *
   * @param compName The component name
   */
  Blinker(const char *const compName);

  /**
   * @brief Initialize the Blinker object
   *
   * @param instance The instance number [default 0]
   */
  void init(const NATIVE_INT_TYPE instance = 0);

  /**
   * @brief Destroy the Blinker object
   */
  ~Blinker() = default;

 private:
  /**
   * @brief Blink the LED
   */
  void blinkLED();

  /**
   * @brief Handler implementation for schedIn
   *
   * @param portNum The port number
   * @param context The call order
   */
  void schedIn_handler(const NATIVE_INT_TYPE portNum,
                       NATIVE_UINT_TYPE context) override;

  // the LED pin to blink
  U32 m_pin;

  // The state of the LED (on or off)
  bool m_state;
};  // end class Blinker

}  // end namespace App

#endif
