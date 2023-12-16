#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int MAX;
	int* array;
	int top;
}STACK;

STACK* createStack(int MAX){
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->MAX = MAX;
	stack->top = -1;
	stack->array = (int*)malloc(MAX*sizeof(int));
	return (stack);
}


void push(STACK* ps, int x){
	if (ps->top!=(ps->MAX)-1){
		ps->top++;
		ps->array[ps->top]=x;
	}
	else
		printf("\nOverflow!\n");
}

void display(STACK *ps){
	if (ps->top!=-1){
		for (int i=(ps->top); i>=0;i--){
			printf("%d", ps->array[i]);
		}
		printf("\n");
	}
	else
		printf("Underflow!\n");
}

int main(){
	printf("Enter decimal number to be converted to binary: ");
	int dec;
	scanf("%d", &dec);
	int rem;
	STACK* binary = createStack(10);
	while (dec>0){
		rem = dec%2;
		dec = dec/2;
		push (binary,rem);
	}
	printf("Binary: ");
	display(binary);
	return 0;
}