#include<stdio.h>
#include<stdlib.h>

int Smallest(int *arr,int size)
{
  int smallest=*arr;
	for(int i=0;i<size;i++)
	{
		if(*(arr+i)<smallest)
			smallest=*(arr+i);
	}
  return smallest;
}

int main()
{
  int size;
  printf("Enter size of the array: ");
  scanf("%d",&size);
  int *arr=(int*)malloc(size*sizeof(int));

  printf("Enter elements of array:-\n");
  for(int i=0;i<size;i++)
    scanf("%d",arr+i);

  printf("Smallest element of array is %d\n",Smallest(arr,size));

  return 0;

}	