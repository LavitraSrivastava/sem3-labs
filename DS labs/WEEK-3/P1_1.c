#include<stdio.h>

void ReverseArr(int *arr,int n)
{
	int *s=arr;
	int *e=arr+n-1;
    int temp;
    while(s<e)
    {
    	temp=*s;
    	*s=*e;
    	*e=temp;
        s++;
        e--;
    }


}
int main()
{
	int n;
	printf("Enter size: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements of array\n");
    for(int i=0;i<n;i++)
    	scanf("%d",&arr[i]);
    printf("Before reversing: ");
    for(int i=0;i<n;i++)
    	printf("%d ",arr[i]);

	ReverseArr(arr,n);

	printf("\nAfter reversing ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}