#include <stdio.h>
#include <stdlib.h>

void Sort(float *arr, float *brr, int n)
{
	float tmp = 0;
	int half = n / 2;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] >= arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	int j = half - 1;
	for (int i = n - 1 ; i >= 0;)
	{
		brr[half] = arr[i--];
		brr[j] = arr[i--];
		half++;
		j--;
	}
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%f\n", arr[i]);
	//}
	//printf("\n");
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%f\n", brr[i]);
	//}
}

int Sum(int *arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

float Time(float *arr, int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			sum += arr[i] * arr[j] * (j - i);
		}
	return sum;
}

int main()
{
	int time[] = { 33, 55, 22, 11, 9 };
	int n = sizeof(time) / sizeof(time[0]);
	int sum = Sum(time, n);
	float* chance1 = (float*)malloc(sizeof(float)*n);
	float* chance2 = (float*)malloc(sizeof(float)*n);
	for (int i = 0; i < n; i++)
	{
		chance1[i] = (float)time[i] / sum;
	}
	Sort(chance1, chance2, n);
	printf("%f\n", Time(chance2, n));
	free(chance1);
	free(chance2);

	return 0;
}