#include "TimeCounter.h"

void TimeCounter::start() {
    if (!running_) {
        startedAt_ = Clock::now();
        running_ = true;
    }
}

void TimeCounter::stop() {
    if (running_) {
        elapsed_ += Clock::now() - startedAt_;
        running_ = false;
    }
}

void TimeCounter::reset() {
    elapsed_ = Clock::duration::zero();
    running_ = false;
}

bool TimeCounter::isRunning() const {
    return running_;
}

TimeCounter::Milliseconds TimeCounter::elapsedTime() const {
    auto elapsed = elapsed_;

    if (running_) {
        elapsed += Clock::now() - startedAt_;
    }

    return std::chrono::duration_cast<Milliseconds>(elapsed);
}
