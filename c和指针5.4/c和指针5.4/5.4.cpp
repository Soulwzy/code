#include <stdio.h>

void Set_bit(char* bit_array, unsigned bit_number)
{
	char *p = bit_array;
	for (int i = 0; i < bit_number; i++)
	{
		p++;
	}
	*p = 1;
}

void Clear_bit(char* bit_array, unsigned bit_number)
{
	char *p = bit_array;
	for (int i = 0; i < bit_number; i++)
	{
		p++;
	}
	*p = 0;
}

void Assgin_bit(char* bit_array, unsigned bit_number, int value)
{
	char *p = bit_array;
	for (int i = 0; i < bit_number; i++)
	{
		p++;
	}
	if (value)
	{
		*p = 1;
	}
	else
	{
		*p = 0;
	}
}

int Test_bit(char* bit_array, unsigned bit_number)
{
	char *p = bit_array;
	for (int i = 0; i < bit_number; i++)
	{
		p++;
	}
	if (*p)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Set_bit(arr, 3);
	Set_bit(arr, 4);
	Clear_bit(arr, 3);
	Assgin_bit(arr, 5, 1);
	printf("%d\n", Test_bit(arr, 5));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}