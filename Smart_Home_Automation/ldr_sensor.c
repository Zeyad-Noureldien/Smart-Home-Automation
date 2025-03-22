#include "ldr_sensor.h"
#include "adc.h"

uint16 LDR_getLightIntensity(void)
{
    uint16 adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    return (uint16)(((float)adc_value / 1023.0) * 100.0);
}
