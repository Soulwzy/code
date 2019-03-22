#include <stdio.h>
#define N 15

bool Identity_matrix(int(*arr)[N], int n)
{
	bool flg = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
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
	int arr[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
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

	printf("%d\n", Identity_matrix(arr, sizeof(arr) / sizeof(arr[0])));

	arr[3][3] = 2;
	printf("%d\n", Identity_matrix(arr, sizeof(arr) / sizeof(arr[0])));

	return 0;
}