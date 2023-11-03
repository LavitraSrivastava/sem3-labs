//Check for sparse matrix
//Number of zeroes greater than number of non-zeroes

#include<stdio.h>
int sparse_check(int arr[][50])
{
	int m,n,i,j;
	printf("Enter no of rows:\n");
	scanf("%d", &m);
	printf("Enter no of columns:\n");
	scanf("%d", &n);
	printf("Start entering elements:\n");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
			scanf("%d", &arr[i][j]);
	}
	int c_z=0, c_nz=0;
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			if (arr[i][j]==0)
				c_z++;
			else
				c_nz++;
		}
	}
	if (c_z>c_nz)
		printf("It is a sparse matrix\n");
	else
		printf("Not a sparse matrix\n");
	return 0;
}



int main()
{
	int arr[50][50];
	sparse_check(arr);
	return 0;
}

