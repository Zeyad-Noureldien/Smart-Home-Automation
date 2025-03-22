#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DCMOTOR_ENABLE_PORT, DCMOTOR_ENABLE_PIN, PIN_OUTPUT); /* Configures the enable pin as output */

	GPIO_setupPinDirection(DCMOTOR_IN1_PORT, DCMOTOR_IN1_PIN, PIN_OUTPUT); /* Configures the input 1 pin as output */
	GPIO_setupPinDirection(DCMOTOR_IN2_PORT, DCMOTOR_IN2_PIN, PIN_OUTPUT); /* Configures the input 2 pin as output */

	DcMotor_Rotate(STOP, LOGIC_LOW); /* Stops the motor at the start */
}

void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	if (state == CLOCKWISE) /* Rotates the motor clockwise at the desired speed */
	{
		GPIO_writePin(DCMOTOR_IN1_PORT, DCMOTOR_IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(DCMOTOR_IN2_PORT, DCMOTOR_IN2_PIN, LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
	else if (state == ANTICLOCKWISE) /* Rotates the motor anti-clockwise at the desired speed */
	{
		GPIO_writePin(DCMOTOR_IN1_PORT, DCMOTOR_IN1_PIN, LOGIC_LOW);
		GPIO_writePin(DCMOTOR_IN2_PORT, DCMOTOR_IN2_PIN, LOGIC_HIGH);
		PWM_Timer0_Start(speed);
	}
	else /* Stops the motor */
	{
		GPIO_writePin(DCMOTOR_IN1_PORT, DCMOTOR_IN1_PIN, LOGIC_LOW);
		GPIO_writePin(DCMOTOR_IN2_PORT, DCMOTOR_IN2_PIN, LOGIC_LOW);
		PWM_Timer0_Start(LOGIC_LOW);
	}
}
