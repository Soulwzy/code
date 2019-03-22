#include <stdio.h>
#include "SeqList.h"

int main()
{
	SeqList SeqList_A;
	Init_SeqList(&SeqList_A);
	Creat_SeqList(&SeqList_A, 10);

	SeqList SeqList_B;
	Init_SeqList(&SeqList_B);
	Creat_SeqList(&SeqList_B, 8);

	SeqList SeqList_C;
	Init_SeqList(&SeqList_C);
	int j = 0;
	for (int i = 5; i < 8; i++)
	{
		Insert_SeqList(&SeqList_C, i, j);
		j++;
	}

	//Show_SeqList(&SeqList_A);
	//Delete_more(&SeqList_A, &SeqList_B, &SeqList_C);
	//Show_SeqList(&SeqList_A);
	//Insert(&SeqList_A, 2);
	//Insert(&SeqList_A, -1);
	//Insert(&SeqList_A, 5);
	//Show_SeqList(&SeqList_A);
	
	//Delete1_SeqList(&SeqList_D, 9);

	//Delete2_SeqList(&SeqList, 10);
	//Delete2_SeqList(&SeqList, 1);
	//Show_SeqList(&SeqList);

	/*Show_SeqList(&SeqList);
	Insert(&SeqList, 11);
	Show_SeqList(&SeqList);*/

	//printf("%d\n", Compare(&SeqList_A, &SeqList_B));
	//Show_SeqList(&SeqList_A);
	//Show_SeqList(&SeqList_B);



	//Show_SeqList(&SeqList_C);

	//Delete_more(&SeqList_A, &SeqList_B, &SeqList_C);
	//Show_SeqList(&SeqList_A);

	Show_SeqList(&SeqList_A);
	Show_SeqList(&SeqList_B);
	Show_SeqList(Combine(&SeqList_B, &SeqList_A));

	return 0;
}