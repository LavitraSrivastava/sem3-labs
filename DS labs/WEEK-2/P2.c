//Program to copy one string to another using recursion

#include<stdio.h>

void str_copy(char* source, char* destination)
{
	if (*source == '\0')
		*destination = '\0';

	else
	{	
		*destination = *source;
		destination++;
		source++;
		str_copy(source, destination);
	}
}

int main()
{
	char source[100], destination[100];
	printf("Enter source string: ");
	scanf("%s", source);
	str_copy(source, destination);	
	printf("Destination string: %s", destination);
	return 0;
}