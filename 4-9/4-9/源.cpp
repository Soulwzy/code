#include <stdio.h>
#include <stdlib.h>

int Gas_Solution(int *station, int n)
{
	int gas = 7;
	int sta = 0;
	for (int i = 0; i < n; i++)
	{
		if (station[i] > 7)
		{
			printf("No Solution");
			return -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (gas >= station[i])
		{
			gas -= station[i];	
		}
		else
		{
			gas = 7 - station[i];
			sta++;
		}
	}
	return sta;
}

int main()
{
	int station[] = { 1, 2, 3, 4, 5, 1, 6, 6 };
	int n = sizeof(station) / sizeof(station[0]);
	printf("%d\n", Gas_Solution(station, n));
	return 0;
}