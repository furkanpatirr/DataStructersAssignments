#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//  This program creates a queue consisting of 100 random numbers, prints the data in the queue to the screen, 
// then transfers this data to a stack and prints the data in the stack to the screen.

#define MAX_QUEUE 100
#define STACK_SIZE 100

struct Queue {
    int items[MAX_QUEUE];
    int front, rear;
};

_Bool isEmptyQueue(struct Queue *queue) {
    if (queue->front == queue->rear)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *queue, int x) {
    if (queue->rear == MAX_QUEUE - 1)
        queue->rear = 0;
    else
        (queue->rear)++;

    if (isEmptyQueue(queue)) {
        printf("Queue is full.");
        exit(1);
    }

    queue->items[queue->rear] = x;
}

int dequeue(struct Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty.");
        exit(1);
    }

    if (queue->front == MAX_QUEUE - 1)
        queue->front = 0;
    else
        (queue->front)++;

    return (queue->items[queue->front]);
}

void printQueue(struct Queue *queue) {
    for (int i = 95; i > 0; i--)
        printf("-%d--", queue->items[i]);
}

void setRandom_100Num_Queue(struct Queue *queue) {
    srand(time(NULL));
    int number;

    for (int i = 0; i <= 98; i++) {
        enqueue(queue, rand() % 1000);
    }
}

void scanQueue(struct Queue *queue, int searchElement) {
    int rearNew = queue->rear;

    for (int i = 0; i <= rearNew; i++) {
        if (searchElement == queue->items[i]) {
            printf("The searched element is at position %d in the queue.\n", 1 + i);
        }
    }
}

struct Stack {
    int top;
    int items[STACK_SIZE];
};

int isEmptyStack(struct Stack *stack) {
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *stack, int x) {
    if (stack->top == STACK_SIZE - 1) {
        printf("%s", "Stack overflow");
        exit(1);
    } else {
        stack->items[++(stack->top)] = x;
    }
}

int pop(struct Stack *stack) {
    if (isEmptyStack(stack)) {
        printf("%s", "Stack underflow");
        exit(1);
    }
    return (stack->items[stack->top--]);
}

void printStack(struct Stack *stack) {
    int topNew = (stack->top) - 2;

    for (int i = 0; i <= topNew; i++) {
        printf("-%d--", pop(stack));
    }
    printf("\n");
}

void transfer(struct Queue *queue, struct Stack *stack) {
    if (stack->top == STACK_SIZE - 1) {
        printf("%s", "Stack overflow");
        exit(1);
    }

    if (queue->front == queue->rear) {
        printf("Queue is empty.");
        exit(1);
    } else {
        for (int i = 0; i <= 95; i++) {
            push(stack, dequeue(queue));
        }
    }
}

int main() {
    int searchElement;

    struct Queue myQueue;
    myQueue.front = myQueue.rear = MAX_QUEUE - 1;
    struct Stack myStack;

    setRandom_100Num_Queue(&myQueue);
    printf("\nData in the queue:");
    printf("\n--------------------------------------------------------\n");

    printQueue(&myQueue);

    transfer(&myQueue, &myStack);

    printf("\nData in the stack:");
    printf("\n--------------------------------------------------------\n");

    printStack(&myStack);

    return 0;
}
