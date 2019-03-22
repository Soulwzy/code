#include <stdio.h>
#include "LinkStack.h"

int main()
{
	LStack stack;
	int value;

	Initialize(&stack);
	for (int i = 0; i < 20; i++)
	{
		Push(&stack, i);
	}

	Pop(&stack, &value);
	Show_Stack(&stack);
	Clear_Stack(&stack);

	return 0;
}