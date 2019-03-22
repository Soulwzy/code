#include <stdio.h>
#include <vld.h>
#include "DLinkList.h"

int main()
{
	DLinkList plist_A;
	Initialize(&plist_A);
	for (int i = 0; i < 10; i++)
	{
		Insert_tail(&plist_A, i);
	}

	DLinkList(plist_B);
	Initialize(&plist_B);
	for (int i = 0; i < 15; i++)
	{
		Insert_tail(&plist_B, i);
	}
	//Show(&plist_A);
	//Delete(&plist_A, 0);
	//Delete(&plist_A, 5);
	//Delete(&plist_A, 9);
	//Delete(&plist_A, 15);
	//Delete(&plist_A, 0);
	//Show(&plist_A);

	//printf("%d\n", Get_length(&plist_A));

	PDLinkList plist_C = Combine(&plist_A, &plist_B, Get_length(&plist_A), Get_length(&plist_B));
	Show(plist_C);

	Clear(&plist_A);
	Clear(&plist_B);
	Clear(plist_C);

	return 0;
}
