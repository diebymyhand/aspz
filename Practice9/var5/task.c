#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FILE_PATH "write_only.txt"

int main() {
    int fd = open(FILE_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0200); // тільки запис
    if (fd < 0) {
        perror("Не вдалося створити файл");
        return 1;
    }

    const char *msg = "Це можна записати, але не прочитати\n";
    if (write(fd, msg, strlen(msg)) < 0) {
        perror("Помилка запису");
        close(fd);
        return 1;
    }

    close(fd);
    printf("Файл '%s' створено з правами тільки на запис (0200).\n", FILE_PATH);

    fd = open(FILE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Спроба прочитати файл — доступ заборонено");
    } else {
        char buf[100];
        int n = read(fd, buf, sizeof(buf)-1);
        if (n > 0) {
            buf[n] = '\0';
            printf("Вміст файлу: %s\n", buf);
        }
        close(fd);
    }

    return 0;
}
