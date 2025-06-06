#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define CHECKPOINT_FILE "checkpoint.txt"

long long current_number = 0;
long long factorial_result = 1;

void save_checkpoint() {
    FILE *fp = fopen(CHECKPOINT_FILE, "w");
    if (fp) {
        fprintf(fp, "%lld %lld", current_number, factorial_result);
        fclose(fp);
    }
}

void load_checkpoint() {
    FILE *fp = fopen(CHECKPOINT_FILE, "r");
    if (fp) {
        fscanf(fp, "%lld %lld", &current_number, &factorial_result);
        fclose(fp);
    }
}

void sigsegv_handler(int signum) {
    printf("SIGSEGV. Відновлення...\n");
    load_checkpoint();
    printf("Відновлено: current_number = %lld, factorial_result = %lld\n", current_number, factorial_result);
    exit(EXIT_FAILURE);
}

void *compute_factorial(void *arg) {
    long long n = (long long)arg;
    for (long long i = current_number + 1; i <= n; i++) {
        factorial_result *= i;
        current_number = i;
        if (i % 1000 == 0) save_checkpoint();
        if (i == 5000) raise(SIGSEGV);
    }
    return NULL;
}

int main() {
    signal(SIGSEGV, sigsegv_handler);
    load_checkpoint();

    pthread_t thread;
    pthread_create(&thread, NULL, compute_factorial, (void *)10000LL);
    pthread_join(thread, NULL);

    save_checkpoint();
    printf("Готово: %lld! = %lld\n", current_number, factorial_result);
    return 0;
}
