#include <stdio.h>
#include <stdlib.h>  

int global_var = 0;

void increase_stack() {
    int array[1000];

    printf("The stack top after increasing is near: %p\n", (void*)&array);
}

void check_heap(){
    int *heap = (int *)malloc(sizeof(int));

    printf("Heap variable is located at address: %p\n", (void*)heap);
    free(heap);
}

int main() {
    int i;

    printf("The initial stack top is near: %p\n", (void*)&i);
    printf("Global variable address (data segment): %p\n", (void*)&global_var);
    printf("Function address (text segment): %p\n", (void*)increase_stack);

    check_heap();
    increase_stack();

    return 0;
}
