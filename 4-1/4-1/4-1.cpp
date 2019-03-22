#include <stdio.h>
#include <stdlib.h>
//#include <vld.h>

int Arrange(int n, int *start, int *final)
{
	bool* arrange = (bool*)calloc(n, sizeof(bool));
	int count = 0;
	int tmp = 0;
	while (count < n)
	{
		count++;
		tmp++;
		int j = 0;
		for (int i = 0; i < n; i++)
		{

			if (arrange[i] == true)
			{
				j++;
				continue;
			}
			if (start[i] >= final[j])
			{
				arrange[i] = true;
				arrange[0] = true;
				j = i;
				count++;
			}
		}
	}

//	printf("%x", arrange);
	free(arrange);
	return tmp;
}

int main()
{
	int start[] = { 1, 12, 25, 27, 36 };
	int final[] = { 23, 28, 35, 80, 50 };
	int n = sizeof(start) / sizeof(start[0]);
	printf("%d\n", Arrange(n, start, final));
}