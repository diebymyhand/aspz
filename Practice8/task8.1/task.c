#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    int flags = fcntl(pipefd[1], F_GETFL, 0);
    fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK);

    const size_t bufsize = 100000;
    char *buffer = malloc(bufsize);
    memset(buffer, 'A', bufsize);

    ssize_t count = write(pipefd[1], buffer, bufsize);
    if (count == -1) {
        perror("write");
    } else {
        printf("Спроба записати %zu байт. Насправді записано: %zd байт\n", bufsize, count);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    free(buffer);

    return 0;
}
