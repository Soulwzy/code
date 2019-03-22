#include <stdio.h>
#include <stdlib.h>
#include <vld.h>

#if 0
void Matrix_multiply(int (*m1)[2], int (*m2)[4], int (*r)[4], int x, int y, int z)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < z; j++)
		{
			int num = 0;
			for (int k = 0; k < y; k++)
			{
				num += m1[i][k] * m2[k][j];
			}
			r[i][j] = num;
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < z; j++)
		{
			printf("%d\t", r[i][j]);
		}
		printf("\n");
	}
}
#endif

void Matrix_multiply(int* m1, int* m2, int* m3, int x, int y, int z)
{

	int k = 0;

	for (int i = 0; i < 2 * x; i = i+2)
	{
		for (int j = 0; j < z; j++)
		{
			m3[k] = m1[i] * m2[j] + m1[i + 1] * m2[j + 4];
			k++;
		}
	}
	for (int i = 0; i < x * z; i++)
	{
		printf("%d\t",m3[i]);
		if ((i + 1) % z == 0)
		{
			printf("\n");
		}
	}
}

int main()
{
	int arr[3][2] = { { 2, -6 }, { 3, 5 }, {1, -1} };
	int brr[2][4] = { { 4, -2, -4, -5 }, { -7, -3, 6, 7, } };
	int crr[3][4];
	Matrix_multiply(arr[0], brr[0], crr[0], 3, 2, 4);

	return 0;
}