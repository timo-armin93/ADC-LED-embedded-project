#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"

void timer_init() {

	//					TIMER0 Init

	//Clearing previous settings
	TCCR0B = 0;
	TCCR0A = 0;

	//Setting prescaler value to 64
	TCCR0B |= (1 << CS00);
	TCCR0B |= (1 << CS01);

	//Fast PWM mode
	TCCR0A |= (1 << WGM00);
	TCCR0A |= (1 << WGM01);

	//Clear OC0A on compare MAtch, set OC0A at BOTTOM
	TCCR0A |= (1 << COM0A1);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	//					TIMER2 Init

	//Clearing previous settings
	TCCR2A = 0;
	TCCR2B = 0;

	//Setting bits CS[22:20] to 1 to get prescaler value of 1024
	TCCR2B |= (1 << CS20);
	TCCR2B |= (1 << CS21);
	TCCR2B |= (1 << CS22);

	//Enabling CTC mode 
	TCCR2A |= (1 << WGM21);

	//Enabling interrupt for Compare Match A
	TIMSK2 |= (1 << OCIE2A);
	
	OCR2A = 156;
}

