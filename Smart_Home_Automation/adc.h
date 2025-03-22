#ifndef ADC_H_
#define ADC_H_

#include "standard_types.h"

void ADC_init(void);                          /* Initialises the ADC to the desired settings */
uint16 ADC_readChannel(uint8 channel_number); /* Returns the ADC value */

#endif
