#include "List.h"

int main()
{
	Plist plist;
	Initialize(&plist);
	for (int i = 0; i < 10; i++)
	{
		Insert_head(&plist, i);
	}

	Show(plist);
	//Delete(&plist, 0);
	//Delete(&plist, 3);
	//Delete(&plist, 8);
	//Show(plist);

	Clean(plist);

	return 0;
}