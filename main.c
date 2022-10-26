/* 
MCU: ATMega328p 
Tim Toikkanen
Labb 3, deluppgift 3, inbyggda system
*/



#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "ADC.h"

//Declaring globale variable to store conversion results
volatile int conversion_complete = 0;

volatile int counter = 0;

ISR(ADC_vect){

	//Storing the results that's in the most significant bits in the global variable
	conversion_complete = ADCH;
}

//Interrupt for Compare match A
ISR(TIMER2_COMPA_vect){

	//Start a single conversion
	ADCSRA |= (1 << ADSC);

	//Every time interrupt occurs the counter increments
	counter++;

	// store ADCH value in OCR0A register
	OCR0A = conversion_complete;
}

void main (void) {
	
	// OCR0A = conversion_complete; I while loopen
	LED_init();
	uart_init();
	timer_init();
	adc_setup();
	sei();
	
	while (1) 
	{

	}
}

