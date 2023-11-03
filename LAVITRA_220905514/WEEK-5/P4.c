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

int pop(STACK *ps){
	if (ps->top!=-1)
		return(ps->array[ps->top--]);
	else
		printf("\nUnderflow!\n");
}

void display(STACK *ps){
	if (ps->top!=-1){
		for (int i=(ps->top); i>=0;i--){
			printf("%d ", ps->array[i]);
		}
		printf("\n");
	}
	else
		printf("Underflow!\n");
}


int main(){
	int n,k;
	printf("Enter value of n and k: ");
	scanf("%d %d", &n, &k);
	STACK* og_stack = createStack(n);
	printf("Start entering elements:-");
	int temp;
	for (int i=0; i<n;i++){
		scanf("%d", &temp);
		push(og_stack, temp);
	}
	printf("\n");
	printf("Initial stack: ");
	display(og_stack);
	
	STACK* pop_stack = createStack(n);
	int ele1,ele2;
	while (k>0){
		ele1 = pop(og_stack);
		ele2 = pop(og_stack);
		if (ele1<ele2){
			push(og_stack, ele2);
			k--;
			int temp2;
			while (pop_stack->top!=-1){
				temp2 = pop(pop_stack);
				push(og_stack, temp2);
			}
		}				
		else{
			push(pop_stack, ele1);
			push(og_stack, ele2);
		}
	}

	
	printf("Final stack: ");
	display(og_stack);
	return 0;
}
