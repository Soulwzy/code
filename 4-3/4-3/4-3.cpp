#include <stdio.h>
#include <stdlib.h>

void Sort(double *arr, int n)
{
	double tmp = 0;
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

void Save(double *arr, int n)
{
	double save = 0;
	int j = 5;
	for (int i = 0; i < n; i++)
	{	
		save += arr[i] * j;
		j--;
	}
	printf("%lf\n", save);
}

int main()
{
	double length[] = { 71, 46, 9, 73, 35 };
	int chance[] = { 872, 452, 265, 120, 85 };
	int sum = 0;
	int n = sizeof(chance) / sizeof(chance[0]);
	double *time = (double *)malloc(sizeof(double) * n);
	sum = Sum(chance, n);
	for (int i = 0; i < n; i++)
	{
		time[i] = chance[i] * length[i] / sum;
	}
	Sort(time, n);
	Save(time, n);
	free(time);

	return 0;
}