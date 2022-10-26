#include <avr/io.h>
#include "led.h"

// configure LED pin
void LED_init() {
	DDRB &= ~(1 << DDB3);
	DDRD |= (1 << DDD6); 
	DDRD &= ~(1 << DDD2); 
}

