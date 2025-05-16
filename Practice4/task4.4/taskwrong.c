#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = NULL;
    int i = 0;

    while (i < 3) {
        if (!ptr)
            ptr = malloc(16);

        printf("Ітерація %d: ptr = %p\n", i + 1, ptr);

        if (ptr) {
            ((char *)ptr)[0] = 'A';
            printf("ptr[0] = %c\n", ((char *)ptr)[0]);
        }

        free(ptr);
        
        i++;
    }

    return 0;
}
