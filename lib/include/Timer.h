#pragma once

#include "TimeCounter.h"

class Timer : public TimeCounter {
public:
    Timer(Milliseconds duration);

    void start() override;
    bool isRunning() const override;
    Milliseconds getTime() const override;
    bool isFinished() const;

private:
    Milliseconds duration_;
};
