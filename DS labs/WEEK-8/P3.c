#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct{
    char items[MAX_SIZE];
    int front;
    int rear;
}DQ;

int isFull(DQ* dq) {
    return (dq->rear == MAX_SIZE - 1);
}

int isEmpty(DQ* dq) {
    return (dq->front == -1);
}

void enqueueRear(DQ* dq, char item) {
    if (isFull(dq)) {
        printf("Deque is full. Enqueue operation failed.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->items[dq->rear] = item;
}

char dqueFront(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Dequeue operation failed.\n");
        return '\0';
    }

    char item = dq->items[dq->front];

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front++;
    }

    return item;
}

int isPalindrome(char* str) {
    int len = strlen(str);
    DQ dq;
    dq.front = -1;
    dq.rear = -1;

    // Enqueue characters from the string to the dq
    for (int i = 0; i < len; i++) {
        enqueueRear(&dq, str[i]);
    }

    // Compare characters from both ends of the dq
    int r = dq.rear;
    while (!isEmpty(&dq)) {
        char frontChar = dqueFront(&dq);
        char rearChar = dq.items[r];

        if (frontChar != rearChar) {
            return 0; // Not a palindrome
        }
        r--;
    }

    return 1; // It's a palindrome
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}
