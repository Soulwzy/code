#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "DStack.h"

void Initialize(PDStack pstack)
{
	assert(pstack != NULL);

	pstack->elem = (int *)malloc(sizeof(int) * INIT_SIZE);

	pstack->top = 0;
	pstack->size = INIT_SIZE;
}

void Push(PDStack pstack, int value)
{
	assert(pstack != NULL);

	if (pstack->top == pstack->size)
	{
		pstack->elem = (int *)realloc(pstack->elem, sizeof(int) * pstack->size * 2);

		pstack->size *= 2;
	}

	pstack->elem[pstack->top++] = value;
}

bool Get_Top(PDStack pstack, int *rtval)    //获取栈顶值，但不删除
{
	if (Is_Empty(pstack))
	{
		return false;
	}
	else
	{
		*rtval = pstack->elem[pstack->top - 1];

		return true;
	}
}

bool Pop(PDStack pstack, int *rtval)		//获取栈顶值，并删除
{
	if (Is_Empty(pstack))
	{
		return false;
	}
	else
	{
		*rtval = pstack->elem[--pstack->top];

		return true;
	}
}

int Get_Length(PDStack pstack)
{
	assert(pstack != NULL);

	return pstack->top - 1;
}

bool Is_Empty(PDStack pstack)
{
	assert(pstack != NULL);

	return pstack->top == 0;
}

void Destroy(PDStack pstack)
{
	assert(pstack != NULL);

	free(pstack);
}

void Clear(PDStack pstack)
{
	assert(pstack != NULL);

	pstack->top = 0;
}

bool Show(PDStack pstack)
{
	assert(pstack != NULL);

	int rtval;
	int tmp = pstack->top;

	if (Is_Empty(pstack))
	{
		return false;
	}
	else
	{
		while (!Is_Empty(pstack))
		{
			Pop(pstack, &rtval);
			printf("%d ", rtval);
		}

		printf("\n");
		pstack->top = tmp;

		return true;
	}
}

bool Match(PDStack pstack, const char *string)
{
	while (*string != '\0')
	{
		if (Is_Empty(pstack))
		{
			if (*string == '(' || *string == ')' || *string == '[' || *string == ']' || *string == '{' || *string == '}')
			{
				Push(pstack, *string);
			}
		}
		else
		{
			if (*string == '(' || *string == '[' || *string == '{')
			{
				Push(pstack, *string);
			}
			else if (*string == ')')
			{
				int rtval;

				Get_Top(pstack, &rtval);

				if (rtval == '(')
				{
					Pop(pstack, &rtval);
				}
				else
				{
					return false;
				}
			}
			else if (*string == ']')
			{
				int rtval;

				Get_Top(pstack, &rtval);

				if (rtval == '[')
				{
					Pop(pstack, &rtval);
				}
				else
				{
					return false;
				}
			}
			else if (*string == '}')
			{
				int rtval;

				Get_Top(pstack, &rtval);

				if (rtval == '{')
				{
					Pop(pstack, &rtval);
				}
				else
				{
					return false;
				}
			}
		}

		string++;
	} 

	if (Is_Empty(pstack))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Get_Value(PDStack pstack, const char *string)                 //正确逆波兰式
{
	int tmp;

	while (*string != '\0')
	{
		if (isdigit(*string))
		{
			Push(pstack, *string - '0');
		}
		else
		{
			int a;
			int b;

			Pop(pstack, &b);
			Pop(pstack, &a);

			switch (*string)
			{
			case '*':
				Push(pstack, a * b);
				break;
			case '/':
				Push(pstack, a / b);
				break;
			case '+':
				Push(pstack, a + b);
				break;
			case '-':
				Push(pstack, a - b);
				break;
			default:
				break;
			}
		}

		string++;
	}

	Pop(pstack, &tmp);

	return tmp;
}

void Simulate_PushQueue(PDStack pstack_A, int value)
{
	assert(pstack_A != NULL);

	Push(pstack_A, value);
}

bool Simulate_PopQueue(PDStack pstack_A, PDStack pstack_B,int *rtval)
{
	if (Is_Empty(pstack_A))
	{
		return false;
	}

	int val;

	while (!Is_Empty(pstack_A))
	{
		Pop(pstack_A, &val);
		Push(pstack_B, val);
	}

	Pop(pstack_B, rtval);

	while (!Is_Empty(pstack_B))
	{
		Pop(pstack_B, &val);
		Push(pstack_A, val);
	}

	return true;
}

void Mid_ToBack(PDStack pstack_Num, PDStack pstack_Opr, const char *string)    //中缀转后缀
{
	int val;
	int rtval;

	while (*string != '\0')
	{
		if (isdigit(*string))
		{
			Push(pstack_Num, *string);
		}
		else if (*string == '(')
		{
			Push(pstack_Opr, *string);
		}
		else if (*string == ')')
		{
			Get_Top(pstack_Opr, &rtval);

			while (rtval != '(')
			{
				Pop(pstack_Opr, &val);
				Push(pstack_Num, val);
				Get_Top(pstack_Opr, &rtval);
			} 

			Pop(pstack_Opr, &val);
		}
		else
		{
			Get_Top(pstack_Opr, &rtval);
			
			if (Is_Empty(pstack_Opr) || *string == '(')
			{
				Push(pstack_Opr, *string);
			}
			else if (*string == '*' || *string == '/')
			{
				Push(pstack_Opr, *string);
			}
			else if (*string == '-' || *string == '+')
			{
				if (rtval == '+' || rtval == '-')
				{
					Push(pstack_Opr, *string);
				}
				else
				{
					while (!(Is_Empty(pstack_Opr) || rtval == '+' || rtval == '-' || rtval == '('))
					{
						Pop(pstack_Opr, &val);
						Push(pstack_Num, val);
					}

					Push(pstack_Opr, *string);
				}
			}	
		}
		string++;
	}
	while (!Is_Empty(pstack_Opr))
	{
		Pop(pstack_Opr, &val);
		Push(pstack_Num, val);
	}

	while (!Is_Empty(pstack_Num))
	{
		Pop(pstack_Num, &val);
		Push(pstack_Opr, val);
	}

	while (!Is_Empty(pstack_Opr))
	{
		Pop(pstack_Opr, &val);
		printf("%c ", val);
	}
}

void Mid_ToFront(PDStack pstack_Num, PDStack pstack_Opr, const char *pristring)    //中缀转前缀
{
	int val;
	int rtval;
	const char *string = pristring;

	while (*string != '\0')
	{
		string++;
	}

	while (*string-- != *pristring)
	{
		if (isdigit(*string))
		{
			Push(pstack_Num, *string);
		}
		else if (*string == ')')
		{
			Push(pstack_Opr, *string);
		}
		else if (*string == '(')
		{
			Get_Top(pstack_Opr, &rtval);

			while (rtval != ')')
			{
				Pop(pstack_Opr, &val);
				Push(pstack_Num, val);
				Get_Top(pstack_Opr, &rtval);
			}

			Pop(pstack_Opr, &val);
		}
		else
		{
			Get_Top(pstack_Opr, &rtval);

			if (Is_Empty(pstack_Opr) || *string == ')')
			{
				Push(pstack_Opr, *string);
			}
			else if (*string == '*' || *string == '/')
			{
					Push(pstack_Opr, *string);
			}
			else if (*string == '-' || *string == '+')
			{
				while (!(Is_Empty(pstack_Opr) || rtval == '+' || rtval == '-' || rtval == ')'))
				{
					Pop(pstack_Opr, &val);
					Push(pstack_Num, val);
				}

				Push(pstack_Opr, *string);
			}
		}
	}
	while (!Is_Empty(pstack_Opr))
	{
		Pop(pstack_Opr, &val);
		Push(pstack_Num, val);
	}

	while (!Is_Empty(pstack_Num))
	{
		Pop(pstack_Num, &val);
		printf("%c ", val);
	}
}