#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    double time_taken;

    start = clock();

    for (long i = 0; i < 10000000; i++) {}

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("Час виконання: %.3f мс\n", time_taken);

    return 0;
}
