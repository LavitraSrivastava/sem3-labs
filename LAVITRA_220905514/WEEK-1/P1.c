
//Program to print triplets from entered elements

#include<stdio.h>
int main()
{
	int arr[100], n, i;
	printf("Enter no of elements:\n");
	scanf("%d", &n);
	printf("Start entering elements:\n");
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int n1, n2, n3;
	printf("Triplets are: \n");
	for (n1=0; n1<n; n1++)
	{
		for (n2=n1+1; n2<n; n2++)
		{
			for (n3=n2+1; n3<n; n3++)
			{
				if (arr[n1]+arr[n2]+arr[n3]==0)
				{
					printf("%d %d %d\n", arr[n1], arr[n2], arr[n3]);
				}
			}
		}
	}
	return 0;
}