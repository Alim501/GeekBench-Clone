#include "arithmetic_tests.h"
#include <thread>
#include <vector>

void integerArithmeticTest(int iterations)
{
    volatile int x = 0;
    for (int i = 0; i < iterations; ++i)
    {
        x += i * 3 - i / 2 + i % 7;
    }
}

void floatingPointArithmeticTest(int iterations)
{
    volatile double x = 0.0;
    for (int i = 0; i < iterations; ++i)
    {
        x += i * 0.5 - i / 3.0 + i * 1.234;
    }
}

void multiThreadedTest(int numThreads, int iterationsPerThread)
{
    auto worker = [](int iterations)
    {
        volatile int x = 0;
        for (int i = 0; i < iterations; ++i)
        {
            x += i * 3 - i / 2 + i % 7;
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(worker, iterationsPerThread);
    }

    for (auto &t : threads)
    {
        t.join();
    }
}
