#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100

typedef struct {
	int top;
	int array[MAX_SIZE];
}stack;

void initialize(stack *s){
	s->top = -1;
}

void push(stack *s, int x){
	s->array[++s->top] = x;
}

int pop(stack *s){
	return (s->array[s->top--]);
}

int eval(char* expression){
	stack opstack;
	initialize(&opstack);
	int len = strlen(expression);
	for (int i=len-1; i>=0; i--){
		if(isdigit(expression[i]))
			push(&opstack,expression[i]-'0');
		else{
			int op1 = pop(&opstack);
			int op2 = pop(&opstack);
			switch(expression[i]){
			case '+' : push(&opstack, op1+op2); break;
			case '-' : push(&opstack, op1-op2); break;
			case '*' : push(&opstack, op1*op2); break;
			case '/' : push(&opstack, op1/op2); break;
			default : printf("Invalid expression\n"); exit(1);
			}
		}
	}
	return pop(&opstack);
}
int main(){
	char expression[MAX_SIZE];
	printf("Enter prefix expression: ");
	scanf("%s", expression);
	printf("Result: %d\n", eval(expression));
	return 0;
}