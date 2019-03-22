#include "DLinkList.h"
#include <stdio.h>

int main()
{
	PDLinkList plist_A;

	Initialize(&plist_A);
	for (int i = 0; i < 5; i++)
	{
		Insert_tail(&plist_A, i);
	}
	PDLinkList plist_B;

	Initialize(&plist_B);
	for (int i = 0; i < 8; i++)
	{
		Insert_tail(&plist_B, i);
	}
	//Show(plist);
	//Delete(&plist, 0);
	//Delete(&plist, 5);
	//Delete(&plist, 10);
	//Show(plist);
	//Clear(plist);

	printf("%d\n", Get_length(plist_A));

	return 0;
}