#include <stdio.h>

int main()
{
	int N,i,j;
	printf("Enter no of days: ");
	scanf("%d", &N);
	int arr[N];
	printf("Enter stock prices for each day: ");
	for (i=0; i<N; i++)
		scanf("%d", &arr[i]);
	int profit=0;
	int buy,sell;
	for (i=0; i<N; i++)
	{
		for (j=i; j<N; j++)
		{
			if (profit<(arr[j]-arr[i]))
			{
				profit=arr[j]-arr[i];
				buy=i;
				sell=j;
			}
		}
	}
	printf("%d %d %d", profit, i,j);
	return 0;
}
