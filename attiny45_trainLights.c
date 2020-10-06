/*
 * atTiny45 interrupt INT0
 *
 * Created: 2020-10-04 17:44:05
 * Author : Jringstad
 */ 


#ifndef F_CPU
#define F_CPU 1152000UL
#endif
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
int run = 0;

int main(void)
{	
	DDRB=0b10011;
	GIMSK = 1<<INT0;		/* Enable INT0*/
	MCUCR = 1<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
	sei();			/* Enable Global Interrupt */	
    while (1) 
    {
		PORTB = 0b00000;
		_delay_ms(1000);
		PORTB = 0x00001;
		_delay_ms(3000);
		
		run=0;	
    }
}
ISR(INT0_vect)
{	
	
	while(run<=5)
		{			
			PORTB = 0b10000;
			_delay_ms(500);
			PORTB = 0b00010;
			_delay_ms(500);
			run++;
		}
	
	
}

