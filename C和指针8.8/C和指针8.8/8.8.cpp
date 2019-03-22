#include <stdio.h>
#include <stdlib.h>

int num = 0;

void Int(char(*arr)[8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = '0';
		}
	}
}


void Show(char (*arr)[8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%c  ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	num++;
}

bool Judge(int row, int colum, char(*arr)[8])
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (arr[i][j] == 'X')
			{
				if ((j == colum) || abs(i - row) == abs(j - colum))
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Eight_queen(int n, char(*arr)[8])
{
	if (n > 7)
	{
		Show(arr);
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			arr[n][i] = 'X';
			if (Judge(n, i, arr))
			{
				Eight_queen(n + 1, arr);
			}
			arr[n][i] = '0';
		}
	}
}

int main()
{
	char arr[8][8] = {};
	Int(arr);
	Eight_queen(0, arr);
	printf("%d\n", num);
	return 0;
}



