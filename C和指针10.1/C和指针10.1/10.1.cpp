#include <stdio.h>

typedef struct Phone_num
{
	int street;
	int exchange;
	int station;
}Phone_num;

typedef struct Message 
{
	Phone_num your_phone;
	Phone_num call_phone;
	Phone_num pay_phone;
}Message;

int main()
{
	struct Message m;
	m.call_phone = { 123, 456, 789 };
	printf("%d\n", m.call_phone.exchange);
	printf("%d\n", m.call_phone);
	return 0;
}