#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    size_t pagesize = sysconf(_SC_PAGESIZE);
    void *ptr = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    ((char *)ptr)[0] = 'A';

    mprotect(ptr, pagesize, PROT_READ);

    ((char *)ptr)[0] = 'B';

    return 0;
}
