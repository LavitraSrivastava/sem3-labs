

#include<stdio.h>
#include<stdlib.h>


typedef struct NODE{
	int data;
	struct NODE* lchild;
	struct NODE* rchild;
}NODE;

NODE* stk[20];
int top=-1;

void push(NODE* n){
	stk[++top]=n;
}

NODE* pop(){
	return stk[top--];
}

NODE* createBinaryTree(){
	//creating root node
	NODE* root = (NODE*)malloc(sizeof(NODE));
	root->lchild=root->rchild=NULL;
	printf("Enter data for root: ");
	int num;
	scanf("%d", &num);
	root->data=num;
	push(root);
	while(top!=-1){
		NODE* parent=pop();

		printf("Enter -999 for NULL\n");
		//getting lchild
		printf("Enter lchild of %d: ", parent->data);
		scanf("%d", &num);
		if (num!=-999){
			NODE* newNode = (NODE*)malloc(sizeof(NODE));
			newNode->data=num;
			newNode->lchild=newNode->rchild=NULL;
			parent->lchild=newNode;
			push(newNode);
		}

		printf("Enter rchild of %d: ", parent->data);
		scanf("%d", &num);
		if (num!=-999){
			NODE* newNode = (NODE*)malloc(sizeof(NODE));
			newNode->data=num;
			newNode->lchild=newNode->rchild=NULL;
			parent->rchild=newNode;
			push(newNode);
		}
	}
	return root;
}

void inorder_stack(NODE* root){
	push(root);
	while(top!=-1){
		NODE* temp = pop();	
		temp=temp->rchild;
		while(temp->lchild!=NULL){
			temp=temp->lchild;
			push(temp);
		}
		printf("%d ",temp->data);
		if(temp->rchild){
			temp=temp->rchild;
			while(temp->lchild!=NULL){
				temp=temp->lchild;
				push(temp);
			}
		}
	}
}






void inorder(NODE* ptr){
	if(ptr!=NULL){
		inorder(ptr->lchild);
		printf("%d ", ptr->data);
		inorder(ptr->rchild);
	}
}

void postorder(NODE* ptr){
	if(ptr!=NULL){
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d ", ptr->data);
	}
}

void preorder(NODE* ptr){
	if(ptr!=NULL){
		printf("%d ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

int main(){
	printf("Creating Binary Tree\n");
	NODE* root;
	root=createBinaryTree();
	printf("\nInorder traversal\n");
	inorder_stack(root);
	//printf("\nPreorder traversal\n");
	//preorder(root);
	//printf("\nPostorder traversal\n");
	//postorder(root);
	return 0;
}