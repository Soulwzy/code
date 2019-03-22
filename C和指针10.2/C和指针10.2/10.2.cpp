#include <stdio.h>

typedef struct Message
{
	char custom_name[20];
	char custom_address[40];
	char custom_model[20];
}Message;

typedef struct Trade_cash
{
	int  lease_term;
	//... ÂÔ
	float sale_tax;
	Message message;
}Trade_cash;

typedef struct Trade_rent
{
	int loan_duration;
	//... ÂÔ
	float sales_tax;
	Message message;
}Trade_rent;

int main()
{
	return 0;
}