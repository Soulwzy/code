#include <stdio.h>

bool Identity_matrix(int(*arr)[10])
{
	bool flg = true;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == j)
			{
				if (arr[i][j] != 1)
				{
					flg = false;
				}
			}
			else
			{
				if (arr[i][j] != 0)
				{
					flg = false;
				}
			}
		}
	}
	return flg;
}

int main()
{
	int arr[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == j)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}

	printf("%d\n", Identity_matrix(arr));

	arr[3][3] = 2;
	printf("%d\n", Identity_matrix(arr));

	return 0;
}