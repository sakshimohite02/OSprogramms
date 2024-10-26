#include <stdio.h>
#include <time.h>

int main() {
    // Get the clock ticks before execution
    clock_t start_time = clock();

    // Instructions to be measured
    long sum = 0;
    for (long i = 0; i < 100000000; i++) {
        sum += i;  // Simple computation
    }

    // Get the clock ticks after execution
    clock_t end_time = clock();

    // Calculate the time taken in seconds
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sum: %ld\n", sum);
    printf("Time taken for execution: %f seconds\n", time_taken);

    return 0;
}
