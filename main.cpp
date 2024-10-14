#include <iostream>
#include "arithmetic_tests.h"
#include "timer.h"
#include <bits/std_thread.h>

int main() {
    const int iterations = 100000000;
    Timer timer;
    // Integer arithmetic test
    timer.reset();
    integerArithmeticTest(iterations);
    double intTestTime = timer.elapsed();
    std::cout << "Integer arithmetic test took " << intTestTime << " ms.\n";

    // Calculate throughput for integer arithmetic
    double intOpsPerSec = iterations / (intTestTime / 1000);  // ops/sec
    std::cout << "Integer arithmetic throughput: " << intOpsPerSec << " ops/sec.\n";

    // Floating-point arithmetic test
    timer.reset();
    floatingPointArithmeticTest(iterations);
    double floatTestTime = timer.elapsed();
    std::cout << "Floating-point arithmetic test took " << floatTestTime << " ms.\n";

    // Calculate throughput for floating-point arithmetic
    double floatOpsPerSec = iterations / (floatTestTime / 1000);  // ops/sec
    std::cout << "Floating-point arithmetic throughput: " << floatOpsPerSec << " ops/sec.\n";

    // Multi-threaded test
    int numThreads = std::thread::hardware_concurrency();
    timer.reset();
    multiThreadedTest(numThreads, iterations / numThreads);
    double multiThreadTestTime = timer.elapsed();
    std::cout << "Multi-threaded test took " << multiThreadTestTime << " ms.\n";

    // Calculate throughput for multi-threaded test
    double multiThreadOpsPerSec = iterations / (multiThreadTestTime / 1000);  // ops/sec
    std::cout << "Multi-threaded throughput: " << multiThreadOpsPerSec << " ops/sec.\n";

    // Calculate scalability
    double scalabilityFactor = intTestTime / multiThreadTestTime;
    std::cout << "Scalability factor: " << scalabilityFactor << "\n";

    return 0;
}
