#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int items[MAX_SIZE];
    int front;
    int rear;
}Q;

Q* createQueue() {
    Q* q = (Q*)malloc(sizeof(Q));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Q* q) {
    return (q->front == -1);
}

int isFull(Q* q) {
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(Q* q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }

    q->items[q->rear] = item;
}

int dequeue(Q* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1; // Return a sentinel value for empty q
    }

    int item = q->items[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return item;
}

void reverseQueue(Q* q) {
    if (isEmpty(q)) {
        return; // Nothing to reverse in an empty q
    }

    int frontItem = dequeue(q);

    reverseQueue(q);

    enqueue(q, frontItem);
}

void display(Q* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Q* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Original Queue: ");
    display(q);

    reverseQueue(q);

    printf("Reversed Queue: ");
    display(q);

    free(q);
    return 0;
}
