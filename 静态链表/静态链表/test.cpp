#include <stdio.h>
#include "StaticList.h"

int main()
{
	StaticList Slist_A[SIZE];
	Initialise(Slist_A);
	for (int i = 0; i < 1; i++)
	{
		Insert_tail(Slist_A, i);
	}

	StaticList Slist_B[SIZE];
	Initialise(Slist_B);
	for (int i = 0; i < 5; i++)
	{
		Insert_tail(Slist_B, i);
	}

	
	//printf("%d\n", Serch(Slist_A,4));
	//printf("%d\n", Slist_A[5]);

	//Insert_tail(Slist_A, 20);
	Show(Slist_A);
	Show(Slist_B);
	//Delete(Slist_A, 0);
	//Delete(Slist_A, 5);
	//Delete(Slist_A, 9);

	Delete_Add(Slist_A, Slist_B);
	Show(Slist_A);

	return 0;
}