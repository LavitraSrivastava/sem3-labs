//Program to simulate the working of Tower of Hanoi for n disks.

#include<stdio.h>

void Tower_of_hanoi(int n, char source, char temp, char dest)
{
	if (n==1)
	{
		printf("\nMove disk 1 from %c to %c", source, dest);
		return;
	}

	Tower_of_hanoi(n-1, source, dest, temp);
	printf("\nMove disk %d from %c to %c", n, source, dest);
	Tower_of_hanoi(n-1, temp, source, dest);
}



int main()
{
	int n;
	printf("Enter number of disks: ");
	scanf("%d", &n);
	int moves=1;
	for (int i=0; i<n; i++)
		moves=moves*2;
	printf("Number of moves required : %d\n", moves-1);
	Tower_of_hanoi(n,'A','B','C');
	return 0;
}