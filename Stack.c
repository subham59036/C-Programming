#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    if (!stack->arr) {
        free(stack);
        return NULL;
    }
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int size(Stack* stack) {
    return stack->top + 1;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("Pushed: %d\n", data);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

void main() {
    Stack* s = createStack(5);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("Top element: %d\n", peek(s));
    printf("Size: %d\n", size(s));
    printf("Popped: %d\n", pop(s));
    printf("Size after pop: %d\n", size(s));
    printf("Is Empty? %s\n", isEmpty(s) ? "Yes" : "No");
    freeStack(s);
}