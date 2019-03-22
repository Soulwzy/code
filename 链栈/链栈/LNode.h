#pragma once

typedef struct node
{
	int data;
	struct node *next;
}Linklist,*PLinklist;

void Init_Linklist(PLinklist plist);

bool Insert_head(PLinklist plist, int value);

bool Insert_tail(PLinklist plist, int value);

PLinklist Search(PLinklist plist, int value);

bool Delete(PLinklist plist, int value);                               //若重复删除第一个i

int GetLength(PLinklist plist);

bool IsEmpty(PLinklist plist);

void Show(PLinklist plist);

void Clear(PLinklist plist);

void Destory(PLinklist plist);

bool Have_Circle(PLinklist plist);                                    //是否有环

PLinklist Have_Commom(PLinklist plist_A, PLinklist plist_B);          //是否有焦点

void Delete_Particular(PLinklist p);                                   //删除后一个节点

void Insert_Particular(PLinklist p, char value);                       //插入到 p 前

void Delete_back(PLinklist p, int k);                                  // 删除倒数第k个节点

void Reverse(PLinklist plist);                                         //逆置

void Add_ABC(PLinklist plist_A, PLinklist plist_B, PLinklist plist_C);  //AU(BnC)
 
void Delete_k(PLinklist plist, int k);                                   //删除倒数第k个

PLinklist Return_Circle(PLinklist plist);								//返回环
