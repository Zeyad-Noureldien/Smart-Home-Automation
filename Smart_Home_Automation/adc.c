#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>

void ADC_init(void)
{
	SET_BIT(ADMUX, REFS0); /* Internal 2.56V */
	SET_BIT(ADMUX, REFS1);
	ADMUX &= 0xE0; /*ADC0*/

	SET_BIT(ADCSRA, ADEN); /*ADC enable bit*/
	CLEAR_BIT(ADCSRA, ADIE); /*turn off the adc interrupt (working with polling)*/

	SET_BIT(ADCSRA, ADIF); /* Clear ADIF */

	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2); /*Prescaler (division factor of 128)*/
}

uint16 ADC_readChannel(uint8 channel_number)
{
	channel_number &= 0x07; /* Masking the higher bits */

	ADMUX &= 0xE0; /* Clears the channel bits */

	ADMUX |= channel_number; /* Selects the channel bits based on the input */

	SET_BIT(ADCSRA, ADSC); /* Start analog to digital conversion */

	while(BIT_IS_CLEAR(ADCSRA, ADIF)); /* Polling on the flag */

	return ADC;
}
