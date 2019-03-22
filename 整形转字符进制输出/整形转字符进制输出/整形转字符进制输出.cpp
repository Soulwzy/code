#include <stdio.h>
#include <stdlib.h>

void My_itoc(int num, int cir)
{
	int n = num;
	int i = 0;

	while (n != 0)
	{
		n /= cir;
		i++;
	}

	char* arr = (char*)malloc(i * sizeof(char));

	n = num;

	for (int j = 0; j < i; j++)
	{
		if (n % cir > 9)
		{
			arr[j] = n % cir - 10 + 'A';
		}
		else
		{
			arr[j] = n % cir + '0';
		}
		n /= cir;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		putchar(arr[j]);
	}

	free(arr);
	arr = NULL;
	printf("\n");
}

int main()
{
	My_itoc(1000, 24);
	return 0;
}