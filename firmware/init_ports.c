/*
 * init_ports.c
 *
 */ 

#include "main.h"

/* PORTS INITIALIZATION */
void initPorts(void)
{
	DDRB = 0xFF;
	PORTB = 0xFF;
	
	DDRA = 0xFF;
	PORTA = 0xFF;
}
