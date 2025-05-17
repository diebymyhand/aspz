#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PATH "/tmp/test_access_file.txt"

int main() {
    int fd = open(FILE_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Не вдалося створити файл");
        return 1;
    }

    write(fd, "Це тестовий файл\n", 18);
    close(fd);
    printf("Файл створено: %s\n", FILE_PATH);

    int chown_status = system("sudo chown root:root /tmp/test_access_file.txt");
    int chmod_status = system("sudo chmod 600 /tmp/test_access_file.txt");

    if (chown_status != 0 || chmod_status != 0) {
        fprintf(stderr, "ПОМИЛКА: Не вдалося змінити власника або права доступу.\n");
    } else {
        printf("Власник змінений на root:root, права змінено на 600.\n");
    }

    fd = open(FILE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Читання заборонено");
    } else {
        printf("Читання дозволено.\n");
        close(fd);
    }

    fd = open(FILE_PATH, O_WRONLY);
    if (fd < 0) {
        perror("Запис заборонено");
    } else {
        printf("Запис дозволено.\n");
        close(fd);
    }

    return 0;
}
