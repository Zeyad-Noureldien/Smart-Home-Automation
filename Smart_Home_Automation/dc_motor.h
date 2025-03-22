#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "standard_types.h"

typedef enum
{
	CLOCKWISE,     /* Sets motor direction as clockwise */
	ANTICLOCKWISE, /* Sets motor direction as anti-clockwise */
	STOP           /* Stops the motor */
}DcMotor_State;

#define DCMOTOR_IN1_PORT    PORTB_ID /* Motor input 1 port */
#define DCMOTOR_IN1_PIN     PIN0_ID  /* Motor input 1 pin */

#define DCMOTOR_IN2_PORT    PORTB_ID /* Motor input 2 port */
#define DCMOTOR_IN2_PIN     PIN1_ID  /* Motor input 2 pin */

#define DCMOTOR_ENABLE_PORT PORTB_ID /* Motor enable port */
#define DCMOTOR_ENABLE_PIN  PIN3_ID  /* Motor enable pin */

void DcMotor_Init(void);                               /* Initialises the motor to the desired settings */
void DcMotor_Rotate(DcMotor_State state, uint8 speed); /* Rotates the motor at the desired direction at the desired speed */

#endif
