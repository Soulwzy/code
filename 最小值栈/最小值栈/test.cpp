#include <stdio.h>
#include "MinStack.h"

int main()
{
	int min;
	MStack stack;
	Initialize(&stack);

	for (int i = 5; i >= 0; i--)
	{
		Push(&stack, i);
	}

	Pop(&stack, &min);
	Get_Min(&stack, &min);

	printf("%d\n", min);

	return 0;
}