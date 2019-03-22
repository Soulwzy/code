#include <stdio.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int bit = 0;
	for (int i = 0; i < sizeof(int) * 8; i++)
	{
		bit = bit * 2 + value % 2;
		value /= 2;
	}
	return bit;
}

int main()
{
	printf("%u\n", reverse_bit(25));
	return 0;
}