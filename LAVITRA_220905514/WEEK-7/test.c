#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char *arr;
	int top;
	int max_size;
}Stack;

Stack* createStack(int max){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top=-1;
	s->max_size=max;
	s->arr = (char*)malloc(max*sizeof(char));
	return s;
}

void push(Stack *s, char x){
	if(s->top!=s->max_size-1){
		s->arr[++s->top]=x;
	}
}

int pop(Stack *s){
	if (s->top!=-1){
		return s->arr[s->top--];
	}
}
/*
int main(){
	//Evaluate postfix expression
	printf("Enter postfix expression: ");
	char str[50];
	scanf("%s", str);
	int i=0;
	Stack* s= createStack(20);
	int op1,op2;
	char c;
	while(str[i]!='\0'){
		c=str[i];
		if (c=='+'|c=='-'|c=='*'|c=='/'){
			op2=pop(s);
			op1=pop(s);
			switch(c){
			case '+': push(s,op1+op2);break;
			case '-': push(s,op1-op2);break;
			case '*': push(s,op1*op2);break;
			case '/': push(s,op1/op2);break;
			}
		}
		else{
			int num = c-'0';
			push(s,num);
		}
		i++;
	}
	printf("Result: %d\n", pop(s));
	return 0;
}*/
/////////////////////////////////////////////////////////////////////
/*
int main(){
	//Evaluate prefix expression
	printf("Enter prefix expression: ");
	char str[50];
	scanf("%s", str);
	int i=strlen(str)-1;
	Stack* s= createStack(20);
	int op1,op2;
	char c;
	while(i>=0){
		c=str[i];
		if (c=='+'|c=='-'|c=='*'|c=='/'){
			op1=pop(s);
			op2=pop(s);
			switch(c){
			case '+': push(s,op1+op2);break;
			case '-': push(s,op1-op2);break;
			case '*': push(s,op1*op2);break;
			case '/': push(s,op1/op2);break;
			}
		}
		else{
			int num = c-'0';
			push(s,num);
		}
		i--;
	}
	printf("Result: %d\n", pop(s));
	return 0;
}
*/
////////////////////////////////////////////////////////////////////////

int isOp(char c){
	return (c=='+'|c=='-'|c=='*'|c=='/');
}

int precedence(char c){
	switch(c){
	case '+': return 12;
	case '-': return 12;
	case '*': return 13;
	case '/': return 13;
	}
}

int main(){
	printf("Enter infix expression: ");
	char str[50];
	scanf("%s", str);
	Stack* s = createStack(20);
	int i=0;
	char c;
	while(str[i]!='\0'){
		if (isOp(c))
			push(s,c);
		else if (c=='(')
			push(s,c);
		else if (c==')'){
			while (s->top!=-1 && s->arr[s->top]!='('){
				pop()
			}
		}
	}
}
