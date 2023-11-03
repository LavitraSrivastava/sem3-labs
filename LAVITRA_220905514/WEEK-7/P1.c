#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

struct CircularQueue {
    char* items[MAX_SIZE];
    int front, rear;
};

struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

void insertcq(struct CircularQueue* queue, const char* item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->items[queue->rear] = (char*)malloc((strlen(item) + 1) * sizeof(char));
    strcpy(queue->items[queue->rear], item);
}

void deletecq(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    free(queue->items[queue->front]);

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

void displaycq(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    do {
        printf("%s ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct CircularQueue* queue = createQueue();

    insertcq(queue, "Hello");
    insertcq(queue, "World");
    insertcq(queue, "Circular");
    insertcq(queue, "Queue");
    insertcq(queue, "Example");

    displaycq(queue);

    deletecq(queue);

    displaycq(queue);

    return 0;
}
