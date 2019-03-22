#include <stdio.h>
#include <stdlib.h>

void Puts()
{
	int line = 0;
	bool begin = true;
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (begin == true)
		{
			printf("%d", line);
			line++;
			begin = false;
		}
		putchar(ch);
		if (ch == '\n')
		{
			begin = true;
		}
	}
}

int main()
{
	Puts();
	return 0;
}