#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "ldr_sensor.h"

#include "adc.h"

int main()
{
	LCD_init();
	LEDS_init();
	BUZZER_init();
	DcMotor_Init();
	FlameSensor_init();
	ADC_init();

	uint8 Temperature = 0;
	uint16 LightIntensity = 0;

	LCD_displayStringRowColumn(0, 4, "FAN is");
	LCD_displayStringRowColumn(1, 0, "Temp=  ");
	LCD_displayStringRowColumn(1, 8, "LDR=   %");

	for(;;)
	{
		if (FlameSensor_getValue() == LOGIC_HIGH) /* Critical condition check */
		{
			LCD_clearScreen();
			LCD_displayString("Critical alert!");

			BUZZER_on();

			while (FlameSensor_getValue() == LOGIC_HIGH); /* Polling until the critical condition is cleared */

			BUZZER_off();

			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 4, "FAN is");
			LCD_displayStringRowColumn(1, 0, "Temp=  ");
			LCD_displayStringRowColumn(1, 8, "LDR=   %");
		}

		Temperature = LM35_getTemperature(); /* Temperature check */

		LCD_moveCursor(1, 5);
		if (Temperature >= 0 && Temperature < 100)
		{
			LCD_integerToString(Temperature);
			LCD_displayCharacter(' ');
		}
		else if (Temperature >= 100)
		{
			LCD_integerToString(Temperature);
		}

		if (Temperature < 25)
		{
			DcMotor_Rotate(STOP, 0);
			LCD_displayStringRowColumn(0, 11, "OFF");
		}
		else if (Temperature >= 25 && Temperature < 30)
		{
			DcMotor_Rotate(CLOCKWISE, 25);
			LCD_displayStringRowColumn(0, 11, "ON ");
		}
		else if (Temperature >= 30 && Temperature < 35)
		{
			DcMotor_Rotate(CLOCKWISE, 50);
			LCD_displayStringRowColumn(0, 11, "ON ");
		}
		else if (Temperature >= 35 && Temperature < 40)
		{
			DcMotor_Rotate(CLOCKWISE, 75);
			LCD_displayStringRowColumn(0, 11, "ON ");
		}
		else
		{
			DcMotor_Rotate(CLOCKWISE, 100);
			LCD_displayStringRowColumn(0, 11, "ON ");
		}

		LightIntensity = LDR_getLightIntensity(); /* Light intensity check */

		LCD_moveCursor(1, 12);
		if (LightIntensity == 100)
		{
			LCD_integerToString(LightIntensity);
		}
		else if (LightIntensity >= 10 && LightIntensity < 100)
		{
			LCD_displayCharacter(' ');
			LCD_integerToString(LightIntensity);
		}
		else
		{
			LCD_displayString("  ");
			LCD_integerToString(LightIntensity);
		}

		if (LightIntensity > 70) /* LEDs control */
		{
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if (LightIntensity >= 51 && LightIntensity <= 70)
		{
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if (LightIntensity >= 16 && LightIntensity <= 50)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if (LightIntensity >= 0 && LightIntensity <= 15)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
		}
	}
}

