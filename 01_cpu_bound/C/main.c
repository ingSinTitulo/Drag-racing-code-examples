#include <stdio.h>
#include <time.h>

long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    clock_t start, end;
    start = clock();

    long result = fibonacci(40);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("Fibonacci(40) = %ld\n", result);
    printf("Execution time: %.2f ms\n", time_taken);

    return 0;
}
