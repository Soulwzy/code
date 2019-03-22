#include <stdio.h>
#include <string.h>

char *my_strrchr(char const *str, char ch, int which)
{
	char const *p = str;
	for (int i = 0; i < which; i++);
	{
		if (*str == ch)
		{
			p = str;
		}
		str++;
	}
	return (char*)p;
}

int main()
{
	printf("%c\n", *my_strrchr("asdfdgfg", 'f'));
	return 0;
}