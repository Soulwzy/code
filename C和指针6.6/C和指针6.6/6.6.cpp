#include <stdio.h>
#include <stdlib.h>

int Prime_number(int num1, int num2)
{
	int n = 0;
	char* arr = (char *)malloc((num2 - num1)*sizeof(char));
	for (int i = 0; i < (num2 - num1); i++)
	{
		arr[i] = 1;
	}
	for (int i = 0; i < (num2 - num1); i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				arr[i] = 0;
				continue;
			}
		}
	}
	for (int i = 0; i < (num2 - num1); i++)
	{
		if (arr[i])
		{
			n++;
			//printf("%d\n", i);
		}
	}
	return n;
}

int main()
{
	printf("%d\n", Prime_number(5000, 5100));
	return 0;
}