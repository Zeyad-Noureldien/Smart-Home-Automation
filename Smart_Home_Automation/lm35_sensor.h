#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "standard_types.h"

#define SENSOR_CHANNEL_ID         1   /* ADC channel connected to the sensor */
#define SENSOR_MAX_VOLT_VALUE     1.5 /* Maximum output voltage of the LM35 sensor */
#define SENSOR_MAX_TEMPERATURE    150 /* Maximum temperature the sensor can measure in °C */

uint8 LM35_getTemperature(void); /* Returns the temperature value from the LM35 sensor */

#endif
