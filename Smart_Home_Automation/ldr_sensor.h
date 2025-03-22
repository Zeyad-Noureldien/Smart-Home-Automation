#ifndef LDR_SENSOR_H_
#define LDR_SENSOR_H_

#include "standard_types.h"

#define LDR_SENSOR_CHANNEL_ID          0    /* ADC channel connected to the LDR sensor */
#define LDR_SENSOR_MAX_VOLT_VALUE      2.56 /* Maximum voltage that the LDR sensor can output */
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100  /* Highest light intensity level measurable by the LDR sensor */

uint16 LDR_getLightIntensity(void); /* Returns the percentage light intensity level (0 to LDR_SENSOR_MAX_LIGHT_INTENSITY) */

#endif
