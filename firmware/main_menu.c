/*
 * main_menu.c
 *

 */ 

#include "main.h"

/* MODES FOR USER INTERFACE */
void main_menu(char mode)
{
	static int doNotDisplay;
	
	switch(mode)
	{
		/* RESTART */
		case 'R':
			run(msec, sec);
			doNotDisplay = 0;
			break;
		
		/* STOP	*/
		case 'S':
			stop(msec, sec);
			doNotDisplay = 1;
			break;
		
		/* DISPLAY MESSAGE */
		case 'D':
			if (doNotDisplay)
			{
				data = 'S';
				transmitData(data);
			}		
			else
			{
				displayMessage();
				data = 'R';
			}

			break;
		
		/* QUIT */
		case 'Q':
			quit();
		break;
		
		default:
			mode = mode;
		
	}
	
}

/* RUN MODE */
void run(unsigned int msec, unsigned int sec)
{
	if (msec >= 5)
	{
		//PORTB ^= (1 << PINB7);		//toggles LED7
		PORTB = (0x7F | ~PORTB);		//toggles LED7 and turns all other LED's off
		//PORTB = ~(PINB & sec);	//used to test functionality of counter within the timer
		
		#ifdef debug_run_and_stop_on_oscilloscope
		PORTA = (0xFE | ~PORTB);
		#endif
	}
}

/* STOP MODE */
void stop(unsigned int msec,unsigned int sec)
{

	sec = sec % 10;
	
	if (((msec == 0)&(sec == 0)) | ((msec == 0)&(sec == 5)))
	{
		PORTB = 0xFE; 	// LED on (100ms)
		#ifdef debug_run_and_stop_on_oscilloscope
		PORTA = 0xFE;	// Used for testing on scope
		#endif
	}
	
	if (((msec == 1)&(sec == 0)) | ((msec == 1)&(sec == 5)))
	{
		PORTB = 0xFF; 	// LED off (4900ms)
		#ifdef debug_run_and_stop_on_oscilloscope
		PORTA = 0xFF;	// Used for testing on scope
		#endif
	}
	
}

/* DISPLAY MESSAGE MODE */

 


void displayMessage(const char message[])
{
	message = "Good choice. You chose Display Message. \n";
    int k;
	for (k = 0; k < strlen(message); k++)
	{
		transmitData(message[k]);
	}
}

/* QUIT MODE */
void quit()
{
	PORTB = 0xFF;
	cli();
	PORTB = 0xFF;
	PRR0 = 0xFF;
}