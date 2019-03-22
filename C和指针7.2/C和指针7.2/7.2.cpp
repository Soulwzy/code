# include <stdio.h>
# include <assert.h>

int Gcd(int M, int N)
{
	if (M <= 0 && N <= 0)
	{
		return 0;
	}
	else if (M % N == 0)
	{
		return N;
	}
	else
	{
		int R = M % N;
		assert(R > 0);
		return Gcd(N, R);
	}
}

int main()
{
	printf("%d\n", Gcd(80, 120));
	return 0;
}