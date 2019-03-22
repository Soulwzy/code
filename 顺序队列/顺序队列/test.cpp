#include <stdio.h>
#include "SeqQueue.h"

int main()
{
	Queue pqueue_A;
	Initialize(&pqueue_A);

	Queue pqueue_B;
	Initialize(&pqueue_B);

	int rtval;

	//for (int i = 0; i < 10; i++)
	//{
	//	Push(&pqueue, i);
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	Pop(&pqueue, &i);
	//}

	for (int i = 0; i < 5; i++)
	{
		Simulate_PushStack(&pqueue_A, i);
	}

	Simulate_PopStack(&pqueue_A, &pqueue_B, &rtval);

	printf("%d ", rtval);

	//while (!Is_Empty(&pqueue))
	//{
	//	Pop(&pqueue, &i);
	//	printf("%d ", i);
	//}

	//printf("%d ", Get_Length(&pqueue));

	return 0;
}