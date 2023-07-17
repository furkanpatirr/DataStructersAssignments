#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


// This program creates a queue with 100 random elements, prints the queue, and checks if a user-input element is present in the queue.

#define MAXQUEUE 100

// Memory model

struct Queue {
    int items[MAXQUEUE];
    int front, rear;
};

// Check if the queue is empty
_Bool isEmpty(struct Queue *queue) {
    if (queue->front == queue->rear)
        return 1;
    else
        return 0;
}

// Insert an element into the queue
void insert(struct Queue *queue, int x) {
    // Create space for the new element
    if (queue->rear == MAXQUEUE - 1)
        queue->rear = 0;
    else
        (queue->rear)++;

    // Check for queue overflow
    if (isEmpty(queue)) {
        printf("Queue is full.");
        exit(1);
    }

    queue->items[queue->rear] = x;

    return;
}

// Remove an element from the queue
int removeElement(struct Queue *queue) {
    // Check for empty queue
    if (queue->front == queue->rear) {
        printf("Queue is empty.");
        exit(1);
    }

    if (queue->front == MAXQUEUE - 1)
        queue->front = 0;
    else
        (queue->front)++;

    return (queue->items[queue->front]);
}

// Print the queue
void printQueue(struct Queue *queue) {
    for (int i = 0; i < 98; i++)
        printf("-%d--", removeElement(queue));
}

// Populate the queue with random elements
void populate(struct Queue *queue) {
    srand(time(NULL));
    int number;

    for (int i = 0; i <= 98; i++) {
        insert(queue, rand() % 1000);
    }
}

// Search for the selected element in the queue
void search(struct Queue *queue, int searchElement) {
    int rearNew = queue->rear;

    for (int i = 0; i <= rearNew; i++) {
        if (searchElement == queue->items[i]) {
            printf("The searched element is at position %d in the queue.\n", 1 + i);
        }
    }
}

int main() {
    int searchedElement;

    setlocale(LC_ALL, "English");

    struct Queue myQueue;
    myQueue.front = myQueue.rear = MAXQUEUE - 1;

    populate(&myQueue);
    printQueue(&myQueue);

    printf("\nPlease enter the element you are searching for: ");
    scanf("\n%d", &searchedElement);

    search(&myQueue, searchedElement);
    return 0;
}
