#include <stdio.h>
#include "DStack.h"

int main()
{
	DStack pstack_A;
	Initialize(&pstack_A);

	DStack pstack_B;
	Initialize(&pstack_B);
	//for (int i = 0; i < 15; i++)
	//{
	//	Push(&pstack, i);
	//}
	//Show(&pstack);

	//char *str ="(3*[5 + 4] * {[3 + 5] * [40 - 2 * (5 - 3)]})";

	//printf("%d ", Match(&pstack, str));

	//char *str = "435*+23*-";
	//printf("%d", Get_Value(&pstack, str));

	//for (int i = 0; i < 1; i++)
	//{
	//	Simulate_PushQueue(&pstack_A, i);
	//}

	//int rtval;
	//Simulate_PopQueue(&pstack_A, &pstack_B, &rtval);
	//printf("%d ", rtval);
	char *string = "1+2*(3-4)-5/6";   //

	Mid_ToFront(&pstack_A, &pstack_B, string);

	return 0;
}