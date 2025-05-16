#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT 256

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

void interpret(Stack *s, const char *op) {
    int a, b;
    if (strcmp(op, "+") == 0) {
        b = pop(s);
        a = pop(s);
        push(s, a + b);
    } else if (strcmp(op, "-") == 0) {
        b = pop(s);
        a = pop(s);
        push(s, a - b);
    } else if (strcmp(op, "*") == 0) {
        b = pop(s);
        a = pop(s);
        push(s, a * b);
    } else if (strcmp(op, "/") == 0) {
        b = pop(s);
        a = pop(s);
        if (b == 0) {
            printf("Division by zero!\n");
            exit(EXIT_FAILURE);
        }
        push(s, a / b);
    } else {
        // вважаємо, що це число
        push(s, atoi(op));
    }
}

int main() {
    Stack s;
    init(&s);

    char input[MAX_INPUT];
    printf("Enter an RPN expression (e.g. 3 4 + 2 *), or 'exit' to quit:\n");

    while (1) {
        printf("> ");
        if (!fgets(input, sizeof(input), stdin)) break;

        if (strncmp(input, "exit", 4) == 0)
            break;

        char *token = strtok(input, " \n");
        while (token != NULL) {
            interpret(&s, token);
            token = strtok(NULL, " \n");
        }

        if (!is_empty(&s)) {
            printf("Stack top (result): %d\n", s.data[s.top]);
        }
    }

    return 0;
}
