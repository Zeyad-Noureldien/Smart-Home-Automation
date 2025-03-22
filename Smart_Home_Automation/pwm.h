#ifndef PWM_H_
#define PWM_H_

#include "standard_types.h"

#define WGM00_BIT LOGIC_HIGH
#define WGM01_BIT LOGIC_HIGH

#define COM00_BIT LOGIC_LOW
#define COM01_BIT LOGIC_HIGH

#define CS00_BIT LOGIC_HIGH
#define CS01_BIT LOGIC_LOW
#define CS02_BIT LOGIC_HIGH

#define OCR0_PORT PORTB_ID
#define OCR0_PIN PIN3_ID

void PWM_Timer0_Start(uint8 duty_cycle);

#endif
