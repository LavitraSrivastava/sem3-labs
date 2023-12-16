#include <stdio.h>

int display_mat(int mat[][50], int m, int n)
{
	int i,j;
	for (i=0; i<m; i++)
	{
		for(j=0; j<n;j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}
int multiply_mat(int mat1[][50], int m1, int n1, int mat2[][50], int m2, int n2)
{
	int i,j,k;
	int mat3[50][50];
	for (i=0; i<m1; i++)
		for (j=0; j<n2; j++)
		{	
			mat3[i][j]=0;
			for (k=0; k<m2; k++)
				mat3[i][j]+=mat1[i][k]*mat2[k][j];
		}
	printf("Product matrix:\n");
	display_mat(mat3,m1,n2);
}

int main()
{
	int mat1[50][50], mat2[50][50];
	int m1,n1,m2,n2, i,j;
	printf("Enter no of rows and cols for mat1:\n");
	scanf("%d %d", &m1, &n1);
	printf("Enter no of rows and cols for mat2:\n");
	scanf("%d %d", &m2, &n2);
	printf("Start entering elements of mat1:\n");
	for (i=0; i<m1; i++)
		for (j=0; j<n1; j++)
			scanf("%d", &mat1[i][j]);
	printf("Start entering elements of mat2:\n");
	for (i=0; i<m2; i++)
		for (j=0; j<n2; j++)
			scanf("%d", &mat2[i][j]);
	printf("Matrix 1\n");
	display_mat(mat1,m1,n1);
	printf("Matrix 2\n");
	display_mat(mat2,m2,n2);
	if (n1==m2)
		multiply_mat(mat1,m1,n1,mat2,m2,n2);
	else
		printf("Mutliplication not possible");
	return 0;
}