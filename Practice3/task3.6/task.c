#include <stdio.h>

void recursion(int depth) {
    printf("Recursion depth: %d\n", depth);
    recursion(depth + 1); 
}

int main() {
    recursion(1);
    return 0;
}
