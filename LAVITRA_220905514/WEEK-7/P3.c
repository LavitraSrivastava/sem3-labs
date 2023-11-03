#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int max_size;
	char* arr;
	int front;
	int rear;
}Q;

Q* createQ(int max){
	Q* q = (Q*)malloc(sizeof(Q));
	q->max_size=max;
	q->front=-1;
	q->rear=-1;
	q->arr = (char*)malloc(max*sizeof(char));
	return q;
}

int isEmpty(Q* q){
	return(q->rear==-1);
}

int isFull(Q* q){
	return(q->rear==q->max_size-1);
}

void insertQ(Q* q, char ch){
	if(isFull(q))
		printf("Queue full\n");
	else{
		if(isEmpty(q)){
			q->front=0;
			q->rear=0;
			q->arr[q->rear]=ch;
		}
		else
			q->arr[++q->rear]=ch;
	}
}

char delQ(Q* q){
	if (isEmpty(q))
		printf("Queue empty\n");
	else{
		char ch = q->arr[q->front++];
		if(q->front==q->rear+1){
			q->front=-1;
			q->rear=-1;
		}
		return ch;
	}
		
}

void displayQ(Q* q){
	if (isEmpty(q))
		printf("Queue empty\n");
	else{
		for (int i=q->front;i<=q->rear;i++)
			printf("%c\t", q->arr[i]);
	}
}

int main(){
	int T;
	printf("Enter no of test cases: ");
	scanf("%d", &T);
	int N,K;
	for (int i=1;i<=T;i++){
		printf("Test case %d\n",i);
		printf("Enter value of N and K: ");
		scanf("%d %d", &N,&K);
		Q* q = createQ(N);
		for (int l=0;l<N;l++){
			if(l+1==K){
				insertQ(q,'V');
				insertQ(q,'L');
				l++;
			}
			else{
				insertQ(q,'S');
			}
		}
		int flag=0;
		char ch;
		//popping 3 at a time
		for(int j=0;j<N/3;j++){
			flag=0;
			for (int k=0;k<3;k++){
				ch = delQ(q);
				if(ch=='V')
					flag=1;
			}
			//printf("Flag = %d", flag);
			if (flag==1){
				ch=q->arr[q->front];
				//printf("Ch = %c", ch);
				if (ch=='L')
					printf("No\n");
				else
					printf("Yes\n");		
			}
			//printf("popped 3\n");	
		}
	}

}



