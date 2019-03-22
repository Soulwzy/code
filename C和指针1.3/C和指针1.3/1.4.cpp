#include <stdio.h>
#include <stdlib.h>

void Print_line()
{
	char ch;
	int sum = 0;	
	int max = 0;
	int line = 0;
	while ((ch = getchar()) != EOF)
	{
		sum++;
		if (ch = '\n')
		{
			if (max < sum)
			{
				max = sum;
			}
			line++;
		}
	}
}