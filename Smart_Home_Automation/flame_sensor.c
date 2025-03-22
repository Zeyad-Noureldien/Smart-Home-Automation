#include "flame_sensor.h"
#include "gpio.h"
#include "lcd.h"

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN, PIN_INPUT); /* Configures the flame sensor pin as input */
}

uint8 FlameSensor_getValue(void)
{
	return GPIO_readPin(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN); /* Returns the status fo the flame sensor */
}
