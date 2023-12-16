#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    char array[MAX_SIZE][MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}


void push(struct Stack *stack, char *s)
{
    strcpy(stack->array[++stack->top], s) ;
}

char* pop(struct Stack *stack)
{
    return stack->array[stack->top--];
}


int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


//function to Convert prefix to Postfix
void convert(char *exp)
{
    struct Stack stack;
    initialize(&stack);
    int i,l;
    char op1[50],op2[50];

    l = strlen(exp);

    //scanning from right to left
    for(i = l - 1; i >= 0; i--)
    {
        //checking if the symbol is an operator
        if (is_operator(exp[i]))
        {
            //popping two operands from stack
            strcpy(op1, pop(&stack)) ;
            strcpy(op2, pop(&stack)) ;;
            //concating the operands and operator
            strcat(op1 , strcat(op2 , (char[2]) {(char)exp[i], '\0'})) ;
            //Pushing the temporary string to stack
            push(&stack, op1);
        }
        //if it is an operand
        else
        {
            //push the operand to the stack
            push(&stack,(char[2]){(char)exp[i], '\0'});
        }
    }
    //printf("The postfix expression is: %s",stack[top].c_str());
    printf("%s\n",stack.array[stack.top]);
}

//main function
int main()
{
    

    convert("/+65*56");
    return 0;
}