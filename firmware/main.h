/*
 * main.h
 *
 * Created: 9/13/2012 6:43:16 PM
 *  Author: Tom
 */ 


#ifndef MAIN_H_
#define MAIN_H_


/* DEBUGGING MECHANISMS */
// #define debug_run_and_stop_on_oscilloscope
// #define debug_sec
// #define debug_msec

/* USART CLOCK INITIALIZATION */
#define F_CPU 8000000
#define BAUD 9600
#define MYUBRR ((F_CPU/16/BAUD) - 1)

/* INCLUDE FILES */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

/* GLOBAL VARIABLES */
char data;
unsigned int i, msec, sec;

/* FUNCTIONS */
void initPorts(void);
void initTimer0(void);
void initUSART(void);
void timer(void);
char receiveData(void);
char transmitData(char data);
void main_menu(char mode);
void run(unsigned int msec, unsigned int sec);
void stop(unsigned int msec, unsigned int sec);
void displayMessage();
void quit();





#endif /* MAIN_H_ */