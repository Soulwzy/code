#include <stdio.h>

int del_substr(char* str, char const* substr)
{

	bool flg = false;
	const char *p_su = substr;
	char *q_st = str;
	char *tmp;
	while (*q_st != '\0')
	{
		if (*q_st == *p_su)
		{
			tmp = q_st;
			flg = true;
			int i = 0;
			while (*p_su != '\0')
			{
				if (*q_st == *p_su)
				{
					q_st++;
					p_su++;
					i++;
					continue;
				}
				else
				{
					flg = false;
					break;
				}
			}
			if (flg == true)
			{
				//printf("Æ¥Åä");
				while (*(tmp + i) != '\0')
				{
					*tmp = *(tmp + i);
					tmp++;
				}
				*tmp = '\0';
				return 1;
			}
			else
			{
				p_su = substr;
				continue;
			}
		}
		q_st++;
	}
	return 0;
}

int main()
{
	char arr[] = "abcde";
	char brr[] = "cd";
	del_substr(arr, brr);
	printf("%s\n", arr);
	return 0;
}