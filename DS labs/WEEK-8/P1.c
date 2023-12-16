#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent the ascending priority queue
typedef struct {
    int arr[MAX_SIZE];
    int size;
} APQ;

// Function to initialize an empty ascending priority queue
void pqinit(APQ* apq) {
    apq->size = 0;
}

// Function to insert an element into the ascending priority queue
void pqinsert(APQ* apq, int x) {
    if (apq->size >= MAX_SIZE) {
        printf("Priority queue is full. Cannot insert.\n");
        return;
    }

    apq->arr[apq->size] = x;
    apq->size++;
}

// Function to remove and return the minimum element from the ascending priority queue
int pqmindelete(APQ* apq) {
    if (apq->size == 0) {
        printf("Priority queue is empty. Cannot delete.\n");
        return -1; // Return a sentinel value indicating an error
    }

    int min_value = apq->arr[0];
    int min_index = 0;

    // Find the index of the minimum element
    for (int i = 1; i < apq->size; i++) {
        if (apq->arr[i] < min_value) {
            min_value = apq->arr[i];
            min_index = i;
        }
    }

    // Remove the minimum element by shifting elements in the array
    for (int i = min_index; i < apq->size - 1; i++) {
        apq->arr[i] = apq->arr[i + 1];
    }

    apq->size--;

    return min_value;
}

int main() {
    APQ apq;
    pqinit(&apq);

    // Insert elements into the ascending priority queue
    pqinsert(&apq, 5);
    pqinsert(&apq, 10);
    pqinsert(&apq, 3);
    pqinsert(&apq, 7);

    // Remove and print the minimum elements from the queue
    while (apq.size > 0) {
        int min_element = pqmindelete(&apq);
        printf("Min Element: %d\n", min_element);
    }

    return 0;
}
