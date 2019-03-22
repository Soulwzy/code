#include <iostream>
#include <time.h>


#define k  9//2^k个选手比赛

using namespace std;

void Table(int **table, int n)
{
	for (int i = 1; i <= n; i++)
	{
		table[1][i] = i;
	}
	int m = 1;
	for (int s = 1; s <= k; s++)
	{
		n /= 2;
		for (int t = 1; t <= n; t++)
		{
			for (int i = m + 1; i <= 2 * m; i++)
			{
				for (int j = m + 1; j <= 2 * m; j++)
				{
					table[i][j + (t - 1)* m * 2] = table[i - m][j + (t - 1)* m * 2 - m];
					table[i][j + (t - 1)* m * 2 - m] = table[i - m][j + (t - 1)* m * 2];
				}
			}
		}
		m *= 2;
	}
}

void Show(int **table, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << table[i][j] << "   ";
		}
		cout << endl;
	}
}
int main()
{
	
	clock_t start_time = clock();

	{
		int n = 1;
		for (int i = 1; i <= k; i++)
		{
			n *= 2;
		}
		int **table = new int *[n + 1];
		for (int i = 0; i <= n; i++)
		{
			table[i] = new int[n + 1];
		}
		Table(table, n);
		Show(table, n);
		for (int i = 0; i <= n; i++)
		{
			delete[] table[i];
		}
		delete[] table;
	}

	clock_t end_time = clock();
	cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//输出运行时间
	return 0;
}