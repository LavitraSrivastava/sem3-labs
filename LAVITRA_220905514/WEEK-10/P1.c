#include<stdio.h>
#include<stdlib.h>

//menu driven program to implement doubly linked list without header node to insert into and delete from both the sides


typedef struct node{
	int data;
	struct node* prev;
	struct node* next;
}node;

node* insertFront(node* start, int num){
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data=num;
	new_node->prev=NULL;
	new_node->next=NULL;
	if (start==NULL)
		start=new_node;
	else{
		new_node->next=start;
		start->prev=new_node;
		start=new_node;
	}
	return start;
}

node* insertRear(node* start, int num){
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data=num;
	new_node->next=NULL;
	new_node->next=NULL;
	if(start==NULL)
		start=new_node;
	else{
		node* ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=new_node;
		new_node->prev=ptr;
	}
	return start;
}

node* delFront(node* start){
	if (start==NULL || start->next==NULL){
		start=NULL;
		return start;
	}
	node* temp=start;
	start=start->next;
	start->prev=NULL;
	free(temp);
	return start;
}

node* delRear(node* start){
	if (start==NULL || start->next==NULL){
		start=NULL;
		return start;
	}
	node* ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->prev->next=NULL;
	free(ptr);
	return start;
}

node* display(node* start){
	printf("List:\tNULL->");
	node* ptr=start;
	while(ptr!=NULL){
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
	return start;
}

int main(){
	node* start=NULL;
	int choice,num;
	printf("Choices:-\n");
	printf("1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n0.Exit");
	do{
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			printf("Enter value to insert at front: ");
			scanf("%d", &num);
			start=insertFront(start,num);
			start=display(start);
			break;
		case 2:
			printf("Enter value to insert at rear: ");
			scanf("%d", &num);
			start=insertRear(start,num);
			start=display(start);
			break;
		case 3:
			printf("Deleting at front\n");
			start=delFront(start);
			start=display(start);
			break;
		case 4:
			printf("Deleting at rear\n");
			start=delRear(start);
			start=display(start);
			break;
		case 0:
			printf("Exiting\n");
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	}while(choice!=0);
	return 0;
}