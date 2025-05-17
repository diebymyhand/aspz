#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MY_UID 1000

int is_normal_user(int uid) {
    return uid >= 1000;
}

int main() {
    FILE *fp;
    char line[1024];
    char username[100];
    int uid;
    
    fp = popen("getent passwd", "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%99[^:]:x:%d", username, &uid) == 2) {
            if (uid != MY_UID && is_normal_user(uid)) {
                printf("Normal user: %s, UID: %d\n", username, uid);
            }
        }
    }

    fclose(fp);
    return 0;
}
