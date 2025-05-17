#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void test_access(const char *path) {
    printf("\nФайл: %s\n", path);

    if (access(path, R_OK) == 0) printf(" [✓] Читання дозволено\n");
    else perror(" [X] Читання");

    if (access(path, W_OK) == 0) printf(" [✓] Запис дозволено\n");
    else perror(" [X] Запис");

    if (access(path, X_OK) == 0) {
        printf(" [✓] Виконання дозволено\n");
        printf(" -> Результат виконання:\n");
        char cmd[256]; snprintf(cmd, sizeof(cmd), "%s --version", path);
        system(cmd);
    } else perror(" [X] Виконання");
}

int main() {
    system("ls -l $HOME");
    system("ls -l /usr/bin | head"); 
    system("ls -l /etc | head");

    test_access("/etc/passwd");
    test_access("/usr/bin/ls");

    char tmp[256]; snprintf(tmp, sizeof(tmp), "%s/test.txt", getenv("HOME"));
    int fd = open(tmp, O_CREAT | O_WRONLY, 0644);
    if (fd >= 0) write(fd, "Hi\n", 3), close(fd);
    test_access(tmp);

    return 0;
}