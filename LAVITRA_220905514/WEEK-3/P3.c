#include<stdio.h>
int* Squarenum(int *ptr)
{
	*ptr=(*ptr)*(*ptr);
	return (ptr); // returning pointer to pointer

}
int main()
{
	int num, *p, *q, **r;
	p=&num;
	printf("enter the number");
	scanf("%d",p);
	printf("the entered number is %d\n",num);
    q = Squarenum(p); //passing pointer to function 
    r = &q; //pointer to pointer
	printf("the squared number is %d\n",**r);
	return 0;
}