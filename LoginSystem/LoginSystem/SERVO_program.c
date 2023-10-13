/*
 * SERVO_program.c
 *
 * Created: 26-Sep-23 2:05:47 AM
 *  Author: SEIF EL-DIN SOLTAN OSMAN
 */ 



#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"

#include "SERVO_config.h"
#include "SERVO_interface.h"
#include "SERVO_private.h"


void SERVO_init(void)
{
	DIO_SetPinDirection(SERVO_PORT,SERVO_PIN,DIO_PIN_INPUT);
	DIO_SetPinDirection(TMR1_OC1A_PORT,TMR1_OC1A_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(TMR1_OC1B_PORT,TMR1_OC1B_PIN,DIO_PIN_OUTPUT);
}

void SERVO_TurnON(u16 freq ,f32 Duty)
{	
	TMR1_init();
	TMR1_SetDutyCycle_And_Freq_Value(freq,Duty);
	TMR1_Start();
}

void SERVO_TurnOFF()
{
	TMR1_Stop();	
}
