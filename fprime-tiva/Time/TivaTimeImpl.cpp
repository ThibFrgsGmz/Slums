/**
 * @file TivaTimeImpl.cpp
 * @author Esteban Duran (@astroesteban)
 * @brief The Time Component implementation for the Texas Instruments MCU's
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fprime-tiva/Time/TivaTimeImpl.hpp"
#include "Fw/Time/Time.hpp"


namespace Svc {
    TivaTimeImpl::TivaTimeImpl(const char* name) : TimeComponentBase(name) {} 

    TivaTimeImpl::~TivaTimeImpl() {}

    void TivaTimeImpl::timeGetPort_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Time &time /*!< The time to set */
    ) {
        const auto absoluteTime = get_absolute_time();

        U32 msec = to_ms_since_boot(absoluteTime);
        U32 usec = to_us_since_boot(absoluteTime);
        time.set(msec/1000, usec);
    }

    void TivaTimeImpl::init(NATIVE_INT_TYPE instance) {
        TimeComponentBase::init(instance);
    }
}