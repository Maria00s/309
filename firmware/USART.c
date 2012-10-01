/*
 * USART.c
 *
 */ 

#include "main.h"

/* UART INITIALIZATION */
void initUSART(void)
{
	// 	UBRR0L = (unsigned char)(MYUBRR);
	// 	UBRR0H = (unsigned char)(BAUD>>8);

	UBRR0 = MYUBRR;
	UCSR0B = (1<<RXEN0) | (1<<TXEN0)  | (1<<RXCIE0);			//enables transmit interrupt, receive interrupt, receive and transmitting data
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);		//UCSZ0 set to 3 -> data bits allowed = 8 bits
}

/* RECEIVE CHARACTER */
char receiveData(void)
{
	while ( !(UCSR0A & (1<<RXC0))); 	//wait to receive character
	
	
	data = UDR0;						//store character received from target into "data"
										//and to UDR0 (stores character that was sent by host)
	
	return data;
}


/* TRANSMIT CHARACTER */
char transmitData(char data)
{
	while ( !(UCSR0A & (1<<UDRE0))); 	//wait for empty transmit buffer

	UDR0 = data;					//transmit character from host to target

}

/* USART RECEIVE COMPLETE INTERRUPT */
ISR(USART0_RX_vect)
{

}