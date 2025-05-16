#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <signal.h>
#include <unistd.h>

#define CPU_TIME_LIMIT 1

void handle_sigxcpu(int sig) {
    printf("\nЛіміт часу ЦП вичерпано. Програма завершується.\n");
    exit(1);
}

void generate_numbers(int *array, int n, int max) {
    int count = 0;
    while (count < n) {
        int num = rand() % max + 1;
        int unique = 1;
        for (int i = 0; i < count; i++) {
            if (array[i] == num) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            array[count++] = num;
        }
    }
}

int main() {
    struct rlimit limit = {1, 2};
    setrlimit(RLIMIT_CPU, &limit);

    signal(SIGXCPU, handle_sigxcpu);

    srand(time(NULL));

    int numbers49[7];
    int numbers36[6];

    generate_numbers(numbers49, 7, 49);
    generate_numbers(numbers36, 6, 36);

    printf("Лотерея 7 з 49: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", numbers49[i]);
    }

    printf("\nЛотерея 6 з 36: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numbers36[i]);
    }

    printf("\n");

    while(1) {}

    return 0;
}
