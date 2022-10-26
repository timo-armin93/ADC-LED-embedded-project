#include <avr/io.h>
#include <avr/interrupt.h>

#include "ADC.h"

void adc_setup() { 

    ADCSRA = 0;

    ADMUX = 0;

    //Selecting voltage reference AVCC in datasheet
    ADMUX |= (1 << REFS0);

    //Setting the clock's prescaler value (8)
    ADCSRA |= (1 << ADPS0);
    ADCSRA |= (1 << ADPS1);

    //Enabling the A/D converter interrupt
    ADCSRA |= (1 << ADIE);

    //Setting ADLAR bit to 1 to get 8-bit conversion results
    ADMUX |= (1 << ADLAR);

    //Setting bits MUX[3:0] to zero to use the channel ADC0 (potentiometer)
    ADMUX |= (0 << MUX0) && (0 << MUX1) && (0 << MUX2) && (0 << MUX3);

    //Enabling the ADC to be able to do conversions
    ADCSRA |= (1 << ADEN);



}