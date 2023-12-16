#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *next;
}NODE;



void enqueue(NODE* start, int num){
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	if (new_node==NULL){
		printf("Memory unavailable!\n");
		return;
	}
	new_node->data = num;
	new_node->next = NULL;
	if (start==NULL)
		start = new_node;
	else
		start->next=new_node;
	printf("Enqueued %d\n", num);
}

int dequeue(NODE* start){
	if (start==NULL){
		printf("Queue empty");
		return -1;
	}
	int num = start->data;
	NODE* temp=start;
	start = start->next;
	free(temp);
	return num;
}

void display(NODE* start){
	NODE* ptr;
	ptr = start;
	printf("Queue: ");
	while(ptr->next!=NULL){
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
}

int main(){
	NODE* start=NULL;
	int choice;
	printf("Enter 1 to enqueue, 2 to dequeue, 3 to display, 0 to exit\n");
	do{
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		int num;
		switch(choice){
		case 1: 
			printf("Enter value to enqueue: ");
			scanf("%d", &num);
			enqueue(start,num);
			break;
		case 2:
			num = dequeue(start);
			printf("Value dequeued: %d\n", num);
			break;
		case 3:
			display(start);
			break;
		case 0:
			printf("Exiting\n");
			break;
		default:	
			printf("Invalid choice\n");
		}
	}while(choice!=0);
	return 0;
}