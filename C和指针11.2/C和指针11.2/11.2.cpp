#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <vld.h>

int* Arrary()
{
	char ch;
	int n = 0;
	int num = 0;
	bool flg = false;

	int* arr = (int *)malloc((n + 1)* sizeof(int));

	while ((ch = getchar()) != EOF)
	{
		if (isdigit(ch))
		{
			flg = true;
			num = num * 10 + ch - '0';
			continue;
		}
		else if (flg)
		{
			n++;
			arr = (int *)realloc(arr, (n + 1) * sizeof(int));
			arr[n] = num;
			num = 0;
			flg = false;
		}
	}

	arr[0] = n;

	return arr;
}

int main()
{
	int* arr = Arrary();

	//for (int i = 0; i < 2 + 1; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	free(arr);

	return 0;
}