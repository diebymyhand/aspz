#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Running command as root...\n");

    int result = system("sudo cat /etc/shadow");

    if (result == -1) {
        perror("Error executing command");
        return 1;
    }

    return 0;
}
