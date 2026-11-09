#pragma once

#include "TimeCounter.h"

class Stopwatch : public TimeCounter {
public:
    Milliseconds getTime() const override;
};
