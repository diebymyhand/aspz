#include <stdio.h>
#include <time.h>
#include <limits.h>  

int main() {

    time_t time64 = LLONG_MAX;
    time_t time32 = INT_MAX;

    printf("For 64-bit time_t (LLONG_MAX): %s\n", ctime(&time64));
    printf("For 32-bit time_t (INT_MAX): %s", ctime(&time32));

    return 0;
}