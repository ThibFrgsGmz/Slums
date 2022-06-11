/**
 * @file IntervalTimer.cpp
 * @author Esteban Duran (@astroesteban)
 * @brief The pico implementation of the interval timer shares the same raw
 * setup as otehr x86 implementations. That is: the lower U32 of the Raw TIme
 * is nanoseconds while the upper U32 of the RawTime object is seconds.
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Os/IntervalTimer.hpp"
#include "Fw/Types/Assert.hpp"
#include <ctime>
#include <cerrno>
#include <cstring>

namespace Os {
    void IntervalTime::getRawTime(RawTime& time) {

    }

    // Adapted from: http://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html
    // should be t1In - t2In
    U32 IntervalTimer::getDiffUsec(const RawTime& t1In, const RawTime& t2In) {

        RawTime result = {t1In.upper - t2In.upper,0};

        if (t1In.lower < t2In.lower) {
            result.upper -= 1; // subtract nsec carry to seconds
            result.lower = t1In.lower + (1000000000 - t2In.lower);
        } else {
            result.lower = t1In.lower - t2In.lower;
        }

        return result.upper*1000000 + result.lower / 1000;
    }
}