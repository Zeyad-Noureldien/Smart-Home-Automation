#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "standard_types.h"

#define FLAME_SENSOR_PORT PORTD_ID /* Flame sensor port */
#define FLAME_SENSOR_PIN  PIN2_ID  /* Flame sensor pin */

void FlameSensor_init(void);       /* Initialises the flame sensor at the desired settings */
uint8 FlameSensor_getValue(void);  /* Returns the value of the flame sensor */

#endif
