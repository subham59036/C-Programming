#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;

    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->arr = (int*)malloc(capacity * sizeof(int));

    if (!q->arr) {
        free(q);
        return NULL;
    }
    return q;
}

bool isEmpty(Queue* q) {
    return q->count == 0;
}

bool isFull(Queue* q) {
    return q->count == q->capacity;
}

int size(Queue* q) {
    return q->count;
}

void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", data);
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
    q->count++;
    printf("Enqueued: %d\n", data);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front++;
    q->count--;
    return data;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

void freeQueue(Queue* q) {
    free(q->arr);
    free(q);
}

void main() {
    Queue* q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Front element: %d\n", peek(q));
    printf("Size: %d\n", size(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Size after dequeue: %d\n", size(q));
    printf("Is Empty? %s\n", isEmpty(q) ? "Yes" : "No");
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    freeQueue(q);
}