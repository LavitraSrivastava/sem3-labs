#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void push(STACK* ps, char x){
	if (ps->top!=(ps->MAX)-1){
		ps->top++;
		ps->chars[ps->top]=x;
	}
	else
		printf("\nOverflow!\n");
}

char pop(STACK *ps){
	if (ps->top!=-1)
		return(ps->chars[ps->top--]);
	else
		printf("\nUnderflow!\n");
}

int main(){
	char string[20];
	printf("Enter string to check for palindrome: ");
	scanf("%s", string);
	int len = strlen(string);
	STACK* stack = createStack(len);
	for (int i=0; i<len;i++)
		push(stack, string[i]);
	char* string2 = (char*)malloc(len*sizeof(char));
	for (int i=0; i<len;i++)
		string2[i]=pop(stack);
	if (strcmp(string,string2)==0)
		printf("It is a palindrome\n");
	else
		printf("Not a palindrome\n");
	return 0;
}