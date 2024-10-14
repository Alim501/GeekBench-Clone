#include "timer.h"

Timer::Timer() : start(std::chrono::high_resolution_clock::now()) {}

void Timer::reset() {
    start = std::chrono::high_resolution_clock::now();
}

double Timer::elapsed() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::high_resolution_clock::now() - start)
        .count();
}
