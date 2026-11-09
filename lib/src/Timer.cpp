#include "Timer.h"

#include <algorithm>

Timer::Timer(Milliseconds duration)
    : duration_(std::max(duration, Milliseconds::zero())) {
}

void Timer::start() {
    if (!isFinished()) {
        TimeCounter::start();
    }
}

bool Timer::isRunning() const {
    return TimeCounter::isRunning() && !isFinished();
}

TimeCounter::Milliseconds Timer::getTime() const {
    return std::max(duration_ - elapsedTime(), Milliseconds::zero());
}

bool Timer::isFinished() const {
    return getTime() == Milliseconds::zero();
}
