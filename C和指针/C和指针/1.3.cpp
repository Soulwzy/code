#include <stdio.h>

int Checksum()
{
	char ch;
	signed char checksum = -1;
	while ((ch = getchar()) != '\n')
	{
		checksum += ch;
		//putchar(ch);
	}
	return checksum + '\n';
}

int main()
{
	printf("%d\n", Checksum());
	return 0;
}
