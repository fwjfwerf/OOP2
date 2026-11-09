#include "Stopwatch.h"
#include "Timer.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void printTime(const char* label, const TimeCounter& counter) {
    std::cout << label << counter.getTime().count() << " ms" << std::endl;
}

int main() {
    Timer timer(1000ms);
    printTime("Timer before start: ", timer);

    timer.start();
    while (timer.isRunning()) {
        std::this_thread::sleep_for(10ms);
    }
    printTime("Timer remaining: ", timer);
    std::cout << std::boolalpha
              << "Timer finished: " << timer.isFinished() << std::endl;

    timer.reset();
    printTime("Timer after reset: ", timer);

    Stopwatch stopwatch;
    stopwatch.start();
    std::this_thread::sleep_for(250ms);
    stopwatch.stop();
    printTime("Stopwatch after stop: ", stopwatch);

    stopwatch.start();
    std::this_thread::sleep_for(250ms);
    stopwatch.stop();
    printTime("Stopwatch after resuming: ", stopwatch);

    stopwatch.reset();
    printTime("Stopwatch after reset: ", stopwatch);

    return 0;
}
