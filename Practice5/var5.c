#include <stdio.h>
#include <stdlib.h>

int main() {

    char *x = (char*) malloc(10);
    char *y = (char*) malloc(10);

    free(x);
    free(y);

    x = (char*) malloc(10);
    free(y);

    printf("Hello world\n");
    
    return 0;
}
