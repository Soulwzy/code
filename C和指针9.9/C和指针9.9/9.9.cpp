#include <stdio.h>
#include <string.h>

int count_chars(char const *str, char const* chars)
{
	char const *p = str;
	char const *q = chars;
	int num = 0;
	while (*p != '\0')
	{
		if (*p == *q)
		{
			while (*p == *q)
			{
				p++;
				q++;
			}
			if (*q == '\0')
			{
				num++;
			}
			p--;
		}
		q = chars;
		p++;
	}

	return num;
}

int main()
{
	printf("%d\n", count_chars("aasdasdassd", "asd"));

	return 0;
}
