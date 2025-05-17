#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "data.bin";
    unsigned char data[10] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};

    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open (write)");
        return 1;
    }
    write(fd, data, 10);
    close(fd);

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open (read)");
        return 1;
    }

    lseek(fd, 3, SEEK_SET);

    unsigned char buffer[4];
    ssize_t bytesRead = read(fd, buffer, 4);

    printf("Прочитано %zd байт:\n", bytesRead);
    for (int i = 0; i < bytesRead; ++i) {
        printf("buffer[%d] = %u\n", i, buffer[i]);
    }

    close(fd);
    return 0;
}
