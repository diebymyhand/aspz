#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define DATA "Hello world!!\n"
#define TEMP_FILE "data.tmp"
#define FINAL_FILE "data.txt"

int write_to_file(const char *filename, const char *data, size_t length) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    ssize_t written = write(fd, data, length);
    if (written < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

int main() {
    if (write_to_file(TEMP_FILE, DATA, strlen(DATA) / 2) < 0) {
        return 1;
    }

    printf("Failed after partial write!.\n");

    if (write_to_file(TEMP_FILE, DATA, strlen(DATA)) < 0) {
        return 1;
    }

    if (rename(TEMP_FILE, FINAL_FILE) != 0) {
        perror("rename");
        return 1;
    }

    printf("Data successfully recovered and saved in %s\n", FINAL_FILE);
    return 0;
}
