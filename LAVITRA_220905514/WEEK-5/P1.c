#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int MAX;
	char* chars;
	int top;
}STACK;

STACK* createStack(int MAX){
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->MAX = MAX;
	stack->top = -1;
	stack->chars = (char*)malloc(MAX*sizeof(char));
	return (stack);
}

int isFull(STACK* ps){
	if (ps->top==(ps->MAX)-1)
		return 1;
	return 0; 
}

int isEmpty(STACK* ps){
	if (ps->top==-1)
		return 1;
	return 0;
}


void push(STACK* ps, char x){
	if (isFull(ps)==0){
		ps->top++;
		ps->chars[ps->top]=x;
		printf("Pushed %c successfully\n", x);
	}
	else
		printf("\nOverflow!\n");
}

char pop(STACK *ps){
	if (isEmpty(ps)==0)
		printf("Popped character: %c\n", ps->chars[ps->top--]);
	else
		printf("\nUnderflow!\n");
}

void display(STACK *ps){
	if (isEmpty(ps)==0){
		for (int i=(ps->top); i>=0;i--){
			printf("%c ", ps->chars[i]);
		}
		printf("\n");
	}
	else
		printf("Underflow!\n");
}

int menu(){
	int choice;
	printf("Enter 1 to push, 2 to pop, 3 to display, 0 to exit: ");
	scanf("%d", &choice);
	return choice;
}

int main(){
	STACK* stack = createStack(5);
	printf("Max stack length = 5\n");
	int choice=1;
	while (choice>0){
		choice = menu();
		switch(choice)
		{
		case 1: printf("Enter character to push: ");
				char c1;
				scanf(" %c", &c1);
				push(stack,c1);
				break;
		case 2: printf("Popping character...");
				char c2;
				c2 = pop(stack);
				break;
		case 3: printf("Displaying the stack: \n");
				display(stack);
				break;
		default: printf("Exiting...");
				break;
		}
	}
	return 0;

}