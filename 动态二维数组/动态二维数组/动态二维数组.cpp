#include <stdio.h>
#include <stdlib.h>
#include <vld.h>

#define N 5
#define M 6

//void Dyadic_array()
//{
//	int** arr = (int **)malloc(sizeof(int*) * N);
//	{
//		for (int i = 0; i < N; i++)
//		{
//			arr[i] = (int *)malloc(sizeof(int) * M);
//		}
//	}
//
//
//	arr[3][4] = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		free(arr[i]);
//
//
//		arr[i] = NULL;
//	}
//	free(arr);
//	arr = NULL;
//}

void Dyadic_array()
{
	int(*arr)[M] = (int(*)[M])calloc(sizeof(int), N * M);
	arr[3][4] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	free(arr);
}

int main()
{
	Dyadic_array();
	return 0;
}