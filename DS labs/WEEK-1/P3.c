#include <stdio.h>
int Lsearch(int arr[], int ele, int n)
{
	int flag=0, ind, i;
	for (i=0; i<n; i++)
	{
		if (arr[i]==ele)
		{
			flag=1;
			ind=i;
		}
	}
	if (flag==0)
		printf("Element not found\n");
	else
		printf("Element found at position %d\n", ind+1);
	return 0;

}

int main()
{
	int arr[50], n, i, ele;
	printf("Enter no of elements:\n");
	scanf("%d", &n);
	printf("Start entering elements:\n");
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("Enter element to be searched:\n");
	scanf("%d", &ele);
	Lsearch(arr,ele,n);
	return 0;
}