#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int is_executable(const struct stat *st) {
    return S_ISREG(st->st_mode) && (st->st_mode & S_IXUSR);
}

int main() {
    DIR *dir = opendir(".");
    if (!dir) return 1;

    struct dirent *entry;
    struct stat st;
    char answer[10];

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &st) == -1) continue;
        if (!is_executable(&st)) continue;

        printf("File: %s\n", entry->d_name);
        printf("Give permission permission? (y/n): ");
        if (!fgets(answer, sizeof(answer), stdin)) break;
        if (answer[0] == 'y' || answer[0] == 'Y') {
            chmod(entry->d_name, st.st_mode | S_IROTH);
            printf("Read permission granted.\n");
        }
    }

    closedir(dir);
    return 0;
}