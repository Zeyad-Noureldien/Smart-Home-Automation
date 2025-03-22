#include "pwm.h"
#include "common_macros.h"
#include "gpio.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle)
{
#if (WGM00_BIT == LOGIC_HIGH && WGM01_BIT == LOGIC_HIGH) /* WGM bits */
	{
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	}
#elif (WGM00_BIT == LOGIC_HIGH && WGM01_BIT == LOGIC_LOW)
	{
		SET_BIT(TCCR0, WGM00);
		CLEAR_BIT(TCCR0, WGM01);
	}
#elif (WGM00_BIT == LOGIC_LOW && WGM01_BIT == LOGIC_HIGH)
	{
		CLEAR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	}
#else
	{
		CLEAR_BIT(TCCR0, WGM00);
		CLEAR_BIT(TCCR0, WGM01);
	}
#endif

#if (COM00_BIT == LOGIC_HIGH && COM01_BIT == LOGIC_HIGH) /* COM bits */
	{
		SET_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	}
#elif (COM00_BIT == LOGIC_HIGH && COM01_BIT == LOGIC_LOW)
	{
		SET_BIT(TCCR0, COM00);
		CLEAR_BIT(TCCR0, COM01);

	}
#elif (COM00_BIT == LOGIC_LOW && COM01_BIT == LOGIC_HIGH)
	{
		CLEAR_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	}
#else
	{
		CLEAR_BIT(TCCR0, COM00);
		CLEAR_BIT(TCCR0, COM01);
	}
#endif

#if (CS00_BIT == LOGIC_HIGH && CS01_BIT == LOGIC_HIGH && CS02_BIT == LOGIC_HIGH) /* CS bits */
	{
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	}
#elif (CS00_BIT == LOGIC_HIGH && CS01_BIT == LOGIC_HIGH && CS02_BIT == LOGIC_LOW)
	{
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
	}
#elif (CS00_BIT == LOGIC_HIGH && CS01_BIT == LOGIC_LOW && CS02_BIT == LOGIC_HIGH)
	{
		SET_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	}
#elif (CS00_BIT == LOGIC_LOW && CS01_BIT == LOGIC_HIGH && CS02_BIT == LOGIC_HIGH)
	{
		CLEAR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	}
#elif (CS00_BIT == LOGIC_HIGH && CS01_BIT == LOGIC_LOW && CS02_BIT == LOGIC_LOW)
	{
		SET_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
	}
#elif (CS00_BIT == LOGIC_LOW && CS01_BIT == LOGIC_HIGH && CS02_BIT == LOGIC_LOW)
	{
		CLEAR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
	}
#elif (CS00_BIT == LOGIC_LOW && CS01_BIT == LOGIC_LOW && CS02_BIT == LOGIC_HIGH)
	{
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	}
#else
	{
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
	}
#endif

	GPIO_setupPinDirection(OCR0_PORT, OCR0_PIN, PIN_OUTPUT);

if (duty_cycle > 100 || duty_cycle < 0)
	{
		/* Do nothing */
	}
else
	{
		OCR0 = (((uint16)duty_cycle * 255) / 100);

		GPIO_writePin(OCR0_PORT, OCR0_PIN, duty_cycle);
	}
}
