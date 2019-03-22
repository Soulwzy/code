#include "LNode.h"
#include <stdio.h>

int main()
{
	Linklist head;
	Init_Linklist(&head);
	for (int i = 15; i < 16; i++)
	{
		Insert_tail(&head,i);
	}

	Linklist head_1;
	Init_Linklist(&head_1);
	for (int i = 0; i < 25; i++)
	{
		Insert_tail(&head_1, i);
	}

	Linklist head_2;
	Init_Linklist(&head_2);
	for (int i = 5; i < 30; i++)
	{
		Insert_tail(&head_2, i);
	}
	//printf("%d\n", GetLength(&head));
	//Show(&head);
	//printf("\n");
	//Delete(&head, 15);
	//printf("%d\n", GetLength(&head));
	//Show(&head);

	//printf("%d\n", Have_Circle(&head));
	//PLinklist q = Search(&head, 6);
	//PLinklist p = &head;
	//for (; p->next != NULL; p = p->next)
	//{
	//	
	//}
	//p->next = (&head)->next;
	//printf("%d\n", Have_Circle(&head));

	//Have_Commom(&head, &head_1);
	//PLinklist q = &head, p = &head_1;
	//for (; p->next == Search(&head, 7); p = p->next);
	//for (; q->next == Search(&head, 7); q = q->next);
	//q->next = p->next;
	//Have_Commom(&head, &head_1);

	//Show(&head);
	//
	////Delete_Particular(Search(&head, 7));
	//Insert_Particular(Search(&head, 5),7);

	//Show(&head);

	//Show(&head);
	//Delete_back(&head, 3);
	//Show(&head);

	//Show(&head);
	////Reverse(&head);
	//Delete_k(&head,15);
	//Show(&head);
	Add_ABC(&head, &head_1, &head_2);
	Show(&head);
	Clear(&head);
	Clear(&head_1);
	Clear(&head_2);

	return 0;
}