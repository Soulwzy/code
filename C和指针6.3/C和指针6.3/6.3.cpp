#include<stdio.h>

void reverse_string(char* string)
{
	char* p = string;
	char* q = string;
	char ch;
	while (*q != '\0')
	{
		q++;
	}
	q--;
	while (p != q && (p - 1) != q)
	{
		ch = *p;
		*p = *q;
		*q = ch;
		p++;
		q--;
	}
}

int main()
{
	char arr[] = "abcdefghi";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}