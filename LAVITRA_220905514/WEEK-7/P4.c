#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int max_size;
	int* arr;
	int top;
}Stack;

Stack* createStack(int max){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top=-1;
	s->max_size = max;
	s->arr = (int*)malloc(max*sizeof(int));
	return s;
}

int isEmpty(Stack* s){
	return (s->top==-1);
}

int isFull(Stack* s){
	return(s->top==s->max_size-1);
}

void push(Stack* s, int x){
	if(isFull(s))
		printf("Stack full\n");
	else
		s->arr[++s->top]=x;
}

int pop(Stack* s){
	if (isEmpty(s))
		printf("Underflow\n");
	else
		return (s->arr[s->top--]);
}


int delq(Stack* sin, Stack* sout){
	if(isEmpty(sout)){
		while(!isEmpty(sin))
			push(sout,pop(sin));
		return(pop(sout));
	}
	else{
		return(pop(sout));
	}
}

void displayq(Stack* sin, Stack* sout){
	for (int i=sin->top;i>=0;i--){
		printf("%d\t", sin->arr[i]);
	}
	for (int i=0;i<=sout->top;i++){
		printf("%d\t", sout->arr[i]);
	}
}

int main(){
	int n;
	printf("Enter max size of queue: ");
	scanf("%d", &n);
	Stack* sin = createStack(n);
	Stack* sout = createStack(n);

	int choice,x;
	printf("\nEnter 1 to insert, 2 to delete, 3 to display, 0 to exit\n");
	do{
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			if((sin->top+sout->top)!=n-2){
				printf("Enter value to insert to queue: ");
				scanf("%d", &x);
				push(sin,x);
			}
			else{
				printf("Queue full\n");
			}
			break;
		case 2:
			if((sin->top+sout->top)>=-1){
				x = delq(sin,sout);
				printf("Deleted value: %d\n", x);
			}
			else{
				printf("Queue empty\n");
			}
			break;
		case 3:
			displayq(sin,sout);
			printf("\n");
			break;
		default:
			break;
		}
	}while(choice!=0);
	return 0;
}

