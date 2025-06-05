#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Завершуємо дочірній процес з кодом 7\n");
        exit(7);
    } else if (pid > 0) {
        int status;
        wait(&status);
        int exit_code = WEXITSTATUS(status);
        printf("Код завершення дочірнього процесу: %d\n", exit_code);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}