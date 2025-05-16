#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_negative_malloc() {
    size_t bad_size = (size_t)-1;
    void *ptr = malloc(bad_size);
    if (ptr == NULL) {
        printf("malloc(-1) повертає NULL\n");
    } else {
        printf("malloc(-1) виділив пам'ять\n");
        free(ptr);
    }
}

void test_overflow_malloc() {
    int xa = 1000000;
    int xb = 1000000;
    int num = xa * xb;
    void *ptr = malloc(num);

    if (ptr == NULL) {
        printf("malloc повертає NULL\n");
    } else {
        printf("malloc виділив пам'ять\n");
        free(ptr);
    }
}

int main() {

    test_negative_malloc();
    
    test_overflow_malloc();

    return 0;
}