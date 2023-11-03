#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TwoStacks {
    int top1; // Top index of the first stack
    int top2; // Top index of the second stack
    int arr[MAX_SIZE];
};

// Initialize the two stacks
void initialize(struct TwoStacks *stacks) {
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE;
}

// Push an element onto the first stack
void push1(struct TwoStacks *stacks, int item) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->arr[++stacks->top1] = item;
    } else {
        printf("Stack Overflow (Stack 1)\n");
        exit(1);
    }
}

// Push an element onto the second stack
void push2(struct TwoStacks *stacks, int item) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->arr[--stacks->top2] = item;
    } else {
        printf("Stack Overflow (Stack 2)\n");
        exit(1);
    }
}

// Pop an element from the first stack
int pop1(struct TwoStacks *stacks) {
    if (stacks->top1 >= 0) {
        return stacks->arr[stacks->top1--];
    } else {
        printf("Stack Underflow (Stack 1)\n");
        exit(1);
    }
}

// Pop an element from the second stack
int pop2(struct TwoStacks *stacks) {
    if (stacks->top2 < MAX_SIZE) {
        return stacks->arr[stacks->top2++];
    } else {
        printf("Stack Underflow (Stack 2)\n");
        exit(1);
    }
}

int main() {
    struct TwoStacks stacks;
    initialize(&stacks);

    push1(&stacks, 1);
    push1(&stacks, 2);
    push1(&stacks, 3);

    push2(&stacks, 10);
    push2(&stacks, 9);
    push2(&stacks, 8);

    printf("Popped from Stack 1: %d\n", pop1(&stacks)); // Outputs 3
    printf("Popped from Stack 2: %d\n", pop2(&stacks)); // Outputs 8

    return 0;
}
