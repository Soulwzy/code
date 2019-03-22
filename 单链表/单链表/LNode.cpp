#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vld.h>
#include "LNode.h"

void Init_Linklist(PLinklist plist)
{
	assert(plist != NULL);

	plist->next = NULL;
}

static PLinklist Bulid(int value)
{
	PLinklist node = (PLinklist)malloc(sizeof(Linklist));

	node->data = value;

	return node;
}

bool Insert_head(PLinklist plist, int value)
{
	assert(plist != NULL);

	PLinklist node = Bulid(value);

	node->next = plist->next;
	plist->next = node;

	return true;
}

bool Insert_tail(PLinklist plist, int value)
{
	assert(plist != NULL);

	PLinklist node = Bulid(value);
	PLinklist p;

	for (p = plist; p->next != NULL; p = p->next);
	node->next = NULL;
	p->next = node;

	return true;
}

PLinklist Search(PLinklist plist, int value)
{
	assert(plist != NULL);

	PLinklist p;
	for (p = plist->next; p != NULL; p = p->next)
	{
		if (p->data == value)
		{
			return p;
		}
	}
	return NULL;
}

bool Delete(PLinklist plist, int value)
{
	assert(plist != NULL);

	PLinklist p,q;
	for (p = plist; p->next != NULL; p = p->next)
	{
		if (p->next->data == value)
		{
			break;
		}
	}
	if (p->next == NULL)
	{
		return false;
	}
	
	q = p->next;
	p->next = p->next->next;
	free(q);

	return true;

}

int GetLength(PLinklist plist)
{
	assert(plist != NULL);

	PLinklist p;
	int count = 0;
	
	for (p = plist->next; p != NULL; p = p->next)
	{
		count++;
	}

	return count;
}

bool IsEmpty(PLinklist plist)
{
	assert(plist != NULL);

	return plist->next == NULL;
}

void Show(PLinklist plist)
{
	assert(plist != NULL);

	PLinklist p;

	for (p = plist->next; p != NULL; p = p->next)
	{
		printf("%d ", p->data);
	}

	printf("\n");

}

void Clear(PLinklist plist)
{
	assert(plist != NULL);

	PLinklist p = plist->next;
	PLinklist q; //******

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

void Destory(PLinklist plist)
{
	Clear(plist);
}

bool Have_Circle(PLinklist plist)     //是否有环
{
	assert(plist != NULL);

	for (PLinklist p = plist, q = plist; q != NULL && p != NULL; p = p->next, q = q->next->next)
	{
		if (q == p && q != plist)
		{
			return true;
		}
	}

	return false;
}

PLinklist Have_Commom(PLinklist plist_A, PLinklist plist_B)     //是否有交点
{
	assert(plist_A != NULL && plist_B != NULL);

	for (PLinklist p = plist_A; p->next != NULL; p = p->next)
	{
		for (PLinklist q = plist_B; q->next != NULL; q = q->next)
		{
			if (p == q)
			{
				printf("有\n");
				return p;
			}
		}
	}

	return NULL;
}

void Delete_Particular(PLinklist p)               //将下一个节点复制到这个节点中 删除下个节点
{
	PLinklist q = p->next;
	p->data = p->next->data;
	p->next = p->next->next;
	q->next = NULL;
	free(q);
}

void Insert_Particular(PLinklist p , char value)               //插入一个节点到p后 复制信息到p中
{
	PLinklist q = Bulid(p->data);
	p->data = value;
	q->next = p->next;
	p->next = q;
}

void Delete_back(PLinklist plist, int k)                        //求长查找
{
	int count = GetLength(plist);
	count -= k;
	//printf("%d", count);
	PLinklist p = plist;

	for (int i = 0; i < count && p->next != NULL; i++, p = p->next);

	PLinklist q = p->next;
	p->next = p->next->next;
	free(q);
}

void Reverse(PLinklist plist)                                   //逆置
{
	assert(plist != NULL);

	PLinklist head = NULL;
	PLinklist p = plist->next;
	PLinklist q;

	while (p)
	{
		q = p->next;
		p->next = head;
		head = p;
		p = q;
	}

	plist->next = head;
}

void Add_ABC(PLinklist plist_A, PLinklist plist_B, PLinklist plist_C)       
{
	PLinklist p = plist_A;
	PLinklist q = plist_B->next;
	PLinklist r = plist_C->next;
	
	for (; r != NULL; r = r->next)
	{
		for (; q != NULL; q = q->next)
		{
			if (r->data == q->data)
			{
				for (; p->next != NULL; p = p->next)
				{
					if (p->next->data < q->data)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				if (p->next == NULL)
				{
					Insert_tail(plist_A, q->data);
				}

				else if (p->next->data != q->data)
				{
					PLinklist s = Bulid(q->data);
					s->next = p->next;
					p->next = s;
				}
			}
			else if (r->data < q->data)
			{
				break;
			}
			else
			{
				continue;
			}
		}
	}
}

void Delete_k(PLinklist plist, int k)
{
	PLinklist p = plist;
	PLinklist q = plist->next;

	for (int i = 0; i < k; i++)
	{
		q = q->next;
	}

	for (; q != NULL; p = p->next, q = q->next);

	q = p->next;
	p->next = p->next->next;
	free(q);
}

PLinklist Return_Circle(PLinklist plist)     
{
	assert(plist != NULL);

	for (PLinklist p = plist, q = plist; q != NULL && p != NULL; p = p->next, q = q->next->next)
	{
		if (q == p && q != plist)
		{
			p = plist;
			while (p != q)
			{
				p = p->next;
				q = q->next;
			}

			return p;
		}
	}
}