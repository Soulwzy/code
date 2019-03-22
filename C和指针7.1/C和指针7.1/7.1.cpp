#include <stdio.h>

int Hermite(int n, int x)
{
	if (n <= 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return 2 * x;
	}
	else
	{
		return 2 * x * Hermite(n - 1, x) - 2 * (n - 1) * Hermite(n - 2, x);
	}
}

int main()
{
	printf("%d\n", Hermite(3, 2));
	return 0;
}