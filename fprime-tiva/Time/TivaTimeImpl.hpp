/**
 * @file TivaTimeImpl.hpp
 * @author Esteban Duran (@astroesteban)
 * @brief The time component implementation for Texas Instruments MCU's
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TIVA_TIME_IMPL_HPP
#define TIVA_TIME_IMPL_HPP

#include "Svc/Time/TimeComponentAc.hpp"

namespace Svc {
    class TivaTimeImpl final : public TimeComponentBase {
        public:
            TivaTimeImpl(const char* compName);

            virtual ~TivaTimeImpl();

            void init(NATIVE_INT_TYPE instance);

        protected:
            void timeGetPort_handler(NATIVE_INT_TYPE portNum, Fw::Time &time);
    };
}

#endif