#include <stdio.h>

char *find_char(char const *sourse, char const *chars)
{
	char const* p = sourse;
	char const* q = chars;
	if (sourse == NULL || chars == NULL)
	{
		return NULL;
	}
	while (*p != '\0')
	{
		while (*q != '\0')
		{
			if (*q == *p)
			{
				return (char*)p;
				break;
			}
			q++;
		}
		q = chars;
		p++;
	}
	return NULL;
}

int main()
{
	char arr[] = "abcdefg";
	char brr[] = "ieda";
	int *a = 100;
	a  = 3-1;
	printf("%c\n", *find_char(arr, brr));
	return 0;
}