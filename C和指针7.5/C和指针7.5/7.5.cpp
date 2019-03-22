#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void print_integer(int num)
{
	int i = 0;
	int n = abs(num);

	while (n != 0)
	{
		i++;
		n /= 10;
	}
	n = abs(num);
	//printf("%d",i);

	char* arr = (char*)malloc(sizeof(char) * i);

	for (int j = 0; j<i; j++)
	{
		arr[j] = n % 10 + '0';
		n /= 10;
	}
	if (num < 0)
	{
		putchar('-');
	}

	for (int j = i - 1; j >= 0; j--)
	{
		putchar(arr[j]);
	}

	free(arr);
	arr = NULL;
}

void print_float(double num)
{
	double n = (double)num;
	print_integer((int)num);
	putchar('.');

	num -= (int)num;
	while (num - (int)num >= 0.000001)            //不太对
	{
		num *= 10;
	}
	//printf("%f", num);
	int m = (int)num;
	print_integer(m);
}

void My_printf(const char* str, ...)
{
	va_list list;
	va_start(list, str);

	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
			{
				print_integer(va_arg(list, int));
			}
			else if(*str == 'c')
			{
				putchar(va_arg(list, int));
			}
			else if (*str == 's')
			{
				char* ch = va_arg(list, char*);
				while (*ch != '\0')
				{
					putchar(*ch);
					ch++;
				}
			}
			else if (*str == 'f')
			{
				print_float(va_arg(list, double));
			}
		}
		else
		{
			putchar(*str);
		}
		str++;
	}

}

int main()
{
	My_printf("%d\n%c\n%f\n%s\n", 123456, '$',3.1415, "作业好多");
	return 0;
}
