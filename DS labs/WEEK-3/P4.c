#include<stdio.h>
#include<stdlib.h>

void input_matrix(int** mat, int r, int c)
{
	for (int i=0;i<r;i++)
	{
		mat[i]=(int*)malloc(c*sizeof(int));
		for (int j=0; j<c; j++)
			scanf("%d", &mat[i][j]);
	}
}

void display_matrix(int** mat, int r, int c)
{
	for (int i=0; i<r; i++)
	{
		for (int j=0; j<c; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}
void multiply_mat(int** mat1, int** mat2, int** pr, int r1, int r2, int c1, int c2)
{
	int i,j,k;
	for (i=0; i<r1; i++)
	{
		pr[i]=(int*)malloc(c2*sizeof(int));
		for (j=0; j<c2; j++)
		{	
			pr[i][j]=0;
			for (k=0; k<r2; k++)
				pr[i][j]+=mat1[i][k]*mat2[k][j];
		}
	}
}

int main()
{
	int r1,c1,r2,c2;
	printf("Enter no of rows and cols for matrix 1: ");
	scanf("%d %d", &r1,&c1);
	printf("Enter no of rows and cols for matrix 2: ");
	scanf("%d %d", &r2,&c2);
	if (c1!=r2)
	{
		printf("Multiplication not possible\n");
		return 1;
	}
	int **mat1=(int**)malloc(r1*sizeof(int*));
	int **mat2=(int**)malloc(r2*sizeof(int*));
	int **pr = (int**)malloc(r1*sizeof(int*));
	printf("Enter elements for matrix 1:-\n");
	input_matrix(mat1,r1,c1);
	printf("Enter elements for matrix 2:-\n");
	input_matrix(mat2,r2,c2);
	multiply_mat(mat1,mat2,pr,r1,r2,c1,c2);
	printf("Matrix 1:-\n");
	display_matrix(mat1, r1, c1);
	printf("Matrix 2:-\n");
	display_matrix(mat2, r2, c2);
	printf("Product matrix:-\n");
	display_matrix(pr,r1,c2);
	return 0;
}