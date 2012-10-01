/*
 * timer.c
 */ 

#include "main.h"

/* TIMER INITIALIZATION */
void initTimer0(void)
{
	TCNT0 = (256-125);	//f = 1kHz; TCNT1 = (256 - F_CPU/(prescaler*[desired]frequency)) = (256 - 94)
	TCCR0B = 0x03;			//prescaler = 64
	TIMSK0 = 0x01;			//enable timer0 overflow interrupt and match compare
	sei();
}

/* TIMER0 INTERRUPT HANDLER */
ISR (TIMER0_OVF_vect)
{
	/* DEBUGGING sec, msec, and counter functionality */
	#ifdef debug_sec
	PORTB = ~(PINB & sec);
	#elif debug_msec
	PORTB = ~(PINB & msec);
	#endif
	
	
	/* TIMING COUNTER */
	TCNT0 = (256-125);	//f = 1kHz; TCNT0 = (256 - F_CPU/(prescaler*[desired]frequency)) = (256 - 94)
	i++;
	if (i == 100)
	{
		i = 0;
		msec++;
		if (msec == 10)
		{
			msec = 0;
			sec++;

			if (sec == 60)
			sec = 0;
		}
	}//end if timing counter
	
	main_menu(data);
	
}//end ISR (TIMER0_OVF_vect)
