#include "lm35_sensor.h"
#include "adc.h"

uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
	uint16 adc_value = 0;

	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID); /* Read ADC channel where the temperature sensor is connected */

	temp_value = (uint8)(((uint32)adc_value * SENSOR_MAX_TEMPERATURE * 2.56) / (1023 * SENSOR_MAX_VOLT_VALUE)); /* Calculate the temperature from the ADC value*/

	return temp_value;
}

