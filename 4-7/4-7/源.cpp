#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Sort(int *Ptime,int n)
{
	int tmp = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (Ptime[j] > Ptime[j + 1])
			{
				tmp = Ptime[j];
				Ptime[j] = Ptime[j + 1];
				Ptime[j + 1] = tmp;
			}
		}
}

float Serve(int *Ptime, int n)
{
	int* arr1 = (int *)calloc(n, sizeof(int));
	int* arr2 = (int *)calloc(n, sizeof(int));
	int sum1 = 0;
	int sum2 = 0;
	int j = 0;
	int k = 0;
	float time = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum1 <= sum2)
		{
			arr1[j] = Ptime[i];
			sum1 += Ptime[i];
			j++;
		}
		else
		{
			arr2[k] = Ptime[i];
			sum2 += Ptime[i];
			k++;
		}
	}
	int i = 0;
	while (arr1[i] != 0)
	{
		printf("%d ", arr1[i]);
		time += arr1[i] * j;
		i++;
		j--;
	}
	printf("\n");
	i = 0;
	while (arr2[i] != 0)
	{
		printf("%d ", arr2[i]);
		time += arr2[i] * k;
		i++;
		k--;
	}
	free(arr1);
	free(arr2);
	return time / n;
}


int main()
{
	int Ptime[] = { 56, 12, 1, 99, 1000, 234, 33, 55, 99, 812 };
	int n = sizeof(Ptime) / sizeof(Ptime[0]);
	Sort(Ptime, n);
	printf("\n%.2f\n", Serve(Ptime, n));
	/*for (int i = 0; i < n; i++)
	{
		printf("%d ", Ptime[i]);
	}*/
	return 0;
}