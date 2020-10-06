/*
 * attiny45 interrupt INT0
 *
 * Created: 2020-10-04 17:44:05
 * Author : Jringstad
 */ 


#ifndef F_CPU
#define F_CPU 1152000UL // 16 MHz clock speed
#endif
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
int run = 0;

int main(void)
{	
	//   xx2x310
	DDRB=0b10011;
	GIMSK = 1<<INT0;		/* Enable INT0*/
	MCUCR = 0<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
	sei();			/* Enable Global Interrupt */
	
	
	
    /* Replace with your application code */
	
    while (1) 
    {
		PORTB = 0xFF;
		_delay_ms(5000);
		PORTB = 0x00;
		_delay_ms(50);
	
    }
}
ISR(INT0_vect)
{
	
	while(1)
		{
			PORTB = 0xFF;
			_delay_ms(200);
			PORTB = 0x00;
			_delay_ms(200);
			run++;
			if(run>=5){
				run=0;
				return;
			}
		}
	
	
}

