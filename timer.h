#ifndef TIMER_H
#define TIMER_H

#include <chrono>

// Timer class declaration
class Timer {
public:
    Timer();
    void reset();
    double elapsed() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

#endif
