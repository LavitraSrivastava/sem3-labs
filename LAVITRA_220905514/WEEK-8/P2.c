#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct{
    char* items[MAX_SIZE];
    int front;
    int rear;
    int size;
}DQ;

DQ* createDQ() {
    DQ* dq = (DQ*)malloc(sizeof(DQ));
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

int isFull(DQ* dq) {
    return (dq->size == MAX_SIZE);
}

int isEmpty(DQ* dq) {
    return (dq->size == 0);
}

void enqueueLeft(DQ* dq, char* item) {
    if (isFull(dq)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    dq->items[dq->front] = strdup(item);
    dq->size++;
}

void enqueueRight(DQ* dq, char* item) {
    if (isFull(dq)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }

    dq->items[dq->rear] = strdup(item);
    dq->size++;
}

char* dqueLeft(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty. DQue operation failed.\n");
        return NULL;
    }

    char* item = dq->items[dq->front];
    dq->front = (dq->front + 1) % MAX_SIZE;
    dq->size--;

    return item;
}

void display(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%s, ", dq->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%s\n", dq->items[i]);
}

int main() {
    DQ* dq = createDQ();

    enqueueRight(dq, "A");
    enqueueRight(dq, "B");
    enqueueLeft(dq, "C");
    enqueueLeft(dq, "D");

    display(dq);
    // Output: Queue: D, C, A, B

    char* item = dqueLeft(dq);
    printf("DQued item: %s\n", item);
    // Output: DQued item: D

    display(dq);
    // Output: Queue: C, A, B

    free(dq);
    return 0;
}
