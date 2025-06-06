#include <stdio.h>
#include <time.h>
#include <unistd.h>

void print_time(clockid_t clock_id, const char *label) {
    struct timespec ts;
    clock_gettime(clock_id, &ts);
    printf("%s: %ld.%09ld\n", label, ts.tv_sec, ts.tv_nsec);
}

int main() {
    printf("До sleep:\n");
    print_time(CLOCK_REALTIME, "CLOCK_REALTIME");
    print_time(CLOCK_MONOTONIC, "CLOCK_MONOTONIC");

    printf("Сон 5 секунд...\n");
    sleep(5);

    printf("Після sleep:\n");
    print_time(CLOCK_REALTIME, "CLOCK_REALTIME");
    print_time(CLOCK_MONOTONIC, "CLOCK_MONOTONIC");

    return 0;
}
