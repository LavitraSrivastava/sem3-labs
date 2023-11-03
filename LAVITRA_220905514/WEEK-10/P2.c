#include<stdio.h>
#include<stdlib.h>

//Add two long positive integers represented using circular doubly linked list with header node.


typedef struct node{
	int sum;
	int carry;
	struct node* prev;
	struct node* next;
}node;


node* insert(node* head, int s, int c){
	node* new_node=(node*)malloc(sizeof(node));
	new_node->sum=s;
	new_node->carry=c;
	if (head->next==head){
		head->next=new_node;
		new_node->next=head;
		head->prev=new_node;
		new_node->prev=head;
		head->sum++;
	}
	else{
		new_node->next=head->next;
		new_node->prev=head;
		head->next->prev=new_node;
		head->next=new_node;
		head->sum++;
	}
	return head;
}

node* inputInteger(node* head){
	head->carry=0;
	head->sum=0;
	head->prev=head;
	head->next=head;
	printf("Inputting the integer\n");
	long num;
	int rem;
	printf("Enter the integer: ");
	scanf("%ld", &num);
	while(num>0){
		rem=num%10;
		num=num/10;
		head=insert(head,rem, 0);
	}
	return head;
}


node* adding(node* head1, node* head2){
	node *temp1, *temp2;
	temp1=head1->prev;
	temp2=head2->prev;
	node* result = (node*)malloc(sizeof(node));
	result->carry=0;
	result->sum=0;
	result->prev=result;
	result->next=result;
	int c,s;
	while(temp1!=head1 && temp2!=head2){
		s = (temp1->sum + temp2->sum +result->next->carry)%10;
		c = (temp1->sum + temp2->sum +result->next->carry)/10;
		result = insert(result,s,c);
		temp1=temp1->prev;
		temp2=temp2->prev;
	}
	while(temp1!=head1){
		s = (temp1->sum +result->next->carry)%10;
		c = (temp1->sum +result->next->carry)/10;
		result = insert(result,s,c);
		temp1=temp1->prev;
	}
	while(temp2!=head2){
		s = (temp2->sum +result->next->carry)%10;
		c = (temp2->sum +result->next->carry)/10;
		result = insert(result,s,c);
		temp2=temp2->prev;
	}
	if (result->next->carry>0){
		result = insert(result,result->next->carry,0);
	}
	return result;
}

node* displayInt(node* head){
	node *ptr=head->next;
	while(ptr!=head){
		printf("%d", ptr->sum);
		ptr=ptr->next;
	}
	printf("\n");
	return head;
}

int main(){
	node* int1 = (node*)malloc(sizeof(node));
	int1 = inputInteger(int1);
	node* int2 = (node*)malloc(sizeof(node));
	int2 = inputInteger(int2);
	printf("Integer 1: ");
	int1 = displayInt(int1);
	printf("Integer 2: ");
	int2 = displayInt(int2);
	node* result=NULL;
	result = adding(int1,int2);
	printf("Result: ");
	result = displayInt(result);
	return 0;
}