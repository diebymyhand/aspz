#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILENAME "example.txt"
#define COPY_FILENAME "example_copy.txt"
#define USER_HOME "/home/ddovdan/"

int create_file_as_normal_user() {
    int fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Не вдалося створити файл");
        return -1;
    }
    char *data = "This is a test file created by a normal user.\n";
    write(fd, data, strlen(data));
    close(fd);
    return 0;
}

int copy_file_as_root() {
    if (system("sudo cp example.txt /root/example_copy.txt") != 0) {
        perror("Не вдалося скопіювати файл");
        return -1;
    }
    return 0;
}

int move_file_to_user_home() {
    char command[256];
    snprintf(command, sizeof(command), "sudo mv /root/example_copy.txt %s", USER_HOME);
    if (system(command) != 0) {
        perror("Не вдалося перемістити файл в домашній каталог");
        return -1;
    }
    return 0;
}

int modify_file_as_normal_user() {
    int fd = open(USER_HOME FILENAME, O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Не вдалося відкрити файл для запису");
        return -1;
    }
    char *data = "Additional data added by a normal user.\n";
    write(fd, data, strlen(data));
    close(fd);
    return 0;
}

int remove_file() {
    char command[256];
    snprintf(command, sizeof(command), "rm %s%s", USER_HOME, FILENAME);
    if (system(command) != 0) {
        perror("Не вдалося видалити файл");
        return -1;
    }
    return 0;
}

int main() {
    if (create_file_as_normal_user() != 0) {
        return 1;
    }

    if (copy_file_as_root() != 0) {
        return 1;
    }

    if (move_file_to_user_home() != 0) {
        return 1;
    }

    if (modify_file_as_normal_user() != 0) {
        return 1;
    }

    if (remove_file() != 0) {
        return 1;
    }

    return 0;
}
