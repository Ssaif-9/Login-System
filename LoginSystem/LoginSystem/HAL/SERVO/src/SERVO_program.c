/*
 * SERVO_program.c
 *
 * Created: 26-Sep-23 2:05:47 AM
 *  Author: SEIF EL-DIN SOLTAN OSMAN
 */ 



#include "../../../UTILITIZE/STD_TYPE.h"
#include "../../../UTILITIZE/BIT_MATH.h"

#include "../../../MCAL/DIO/includes/DIO_config.h"
#include "../../../MCAL/DIO/includes/DIO_interface.h"
#include "../../../MCAL/DIO/includes/DIO_private.h"

#include "../../../MCAL/TMR1/includes/TIMER1_config.h"
#include "../../../MCAL/TMR1/includes/TIMER1_interface.h"
#include "../../../MCAL/TMR1/includes/TIMER1_private.h"


#include "../includes/SERVO_config.h"
#include "../includes/SERVO_interface.h"
#include "../includes/SERVO_private.h"


void SERVO_init(void)
{
	DIO_SetPinDirection(TMR1_OC1A_PORT,TMR1_OC1A_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(TMR1_OC1B_PORT,TMR1_OC1B_PIN,DIO_PIN_OUTPUT);
	TMR1_init();
}

void SERVO_TurnON(f32 Angle)
{	
	f32 DutyCycle;
	DutyCycle=5.0+(Angle/36.0);
	TMR1_SetDutyCycle_And_Freq_Value(50,DutyCycle);
	TMR1_Start();
}

void SERVO_TurnOFF()
{
	TMR1_Stop();	
}
