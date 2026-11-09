#pragma once

#include <chrono>

class TimeCounter {
public:
    using Milliseconds = std::chrono::milliseconds;

    virtual ~TimeCounter() = default;

    virtual void start();
    void stop();
    void reset();

    virtual bool isRunning() const;
    virtual Milliseconds getTime() const = 0;

protected:
    Milliseconds elapsedTime() const;

private:
    using Clock = std::chrono::steady_clock;

    Clock::time_point startedAt_{};
    Clock::duration elapsed_{};
    bool running_ = false;
};
