#include <stdio.h>

void Char_value()
{
	char arr[3][6][4][5] = {
		{ {}, {}, {}, {}, {}, {} },
		{ {}, { {}, { 0, ' ' } }, { {}, {}, { 0, 0, 0, 'A' }, }, {}, {}, {} },
		{ {}, {}, {}, {}, {}, {} } };

	printf("%c\n", arr[1][2][2][3]);
	printf("%c\n", arr[1][1][1][1]);
	printf("%c\n", arr[0][0][0][1 * 6 * 4 * 5 + 2 * 4 * 5 + 2 * 5 + 3]);
	for (int i = 0; i < 3 * 6 * 4 * 5; i++)
	{
		printf("%d ",i);
		printf("%c\n", arr[0][0][0][i]);
	}
}

int main()
{
	Char_value();
	return 0;
}