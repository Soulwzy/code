#include <stdio.h>

void Sort(int *Ptime, int n)
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
	float time = 0;
	int j = n;
	for (int i = 0; i < n; i++)
	{
		time += Ptime[i] * j;
		j--;
	}
	return time / n;
}

int main()
{
	int Ptime[] = { 56, 12, 1, 99, 1000, 234, 33, 55, 99, 812 };
	int n = sizeof(Ptime) / sizeof(Ptime[0]);
	Sort(Ptime, n);
	printf("%.2f\n", Serve(Ptime,n));
	return 0;
}