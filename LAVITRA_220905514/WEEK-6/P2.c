#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to push an item onto the stack
void push(struct Stack *stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to return the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    char c, x;

    for (i = 0, j = -1; infix[i] != '\0'; i++) {
        c = infix[i];

        if (c == ' ')
            continue;
        else if (isalnum(c))
            postfix[++j] = c;
        else if (c == '(')
            push(&stack, c);
        else if (c == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(')
                postfix[++j] = pop(&stack);
            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Invalid expression\n");
                exit(1);
            } else
                pop(&stack);
        } else {
            while (!isEmpty(&stack) && precedence(c) <= precedence(stack.items[stack.top]))
                postfix[++j] = pop(&stack);
            push(&stack, c);
        }
    }

    while (!isEmpty(&stack))
        postfix[++j] = pop(&stack);

    postfix[++j] = '\0';
}

// Function to reverse a string
void reverseString(char str[], char reversed[]) {
    int len = strlen(str);
    int i, j = 0;
    for (i = len - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }
    reversed[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);
    reverseString(postfix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
