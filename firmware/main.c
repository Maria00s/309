/*
 * main.c
 *
 */ 

#include "main.h"

int main()
{
	CLKPR = 0x80;
	CLKPR = 0x00;

	initPorts();
	initTimer0();
	initUSART();
	sei();
	data = 'R';
	
	while(data != 'Q')
	{
		receiveData();	//receives data from USART
		transmitData(data);	//transmits data back to the USART
	}
    return 0;
}
