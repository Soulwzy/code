#include <stdio.h>

int main()
{
	int index = 0;
	printf("%d%d\n", index,(index--) % 2);
	printf("%d%d\n", index, (index--) % 2);
	printf("%d%d\n", index, (index--) % 2);
	printf("%d%d\n", index, (index--) % 2);
}