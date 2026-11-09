#include "Stopwatch.h"

TimeCounter::Milliseconds Stopwatch::getTime() const {
    return elapsedTime();
}
