//Program to check for palindrome using recursion

#include<stdio.h>
#include<string.h>
int palindrome_check(char* start, char* end)
{
	if (start>=end)
		return 1;
	else if (*start==*end)
		palindrome_check(start+1, end-1);
	else
		return 0;
}

int main()
{
	char str[100];
	printf("Enter string: ");
	scanf("%s", str);
	palindrome_check(str, str+strlen(str)-1) ? printf("It is a palindrome\n") : printf("Not a palindrome\n");
	return 0;
}