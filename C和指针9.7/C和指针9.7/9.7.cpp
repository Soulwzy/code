#include <stdio.h>
#include <string.h>

char *my_strrchr(char const *str, char ch)
{
	char const *p = str;
	while (*str != '\0')
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