/*
 * LedProgram.c
 *
 * Created: 01-Sep-23 9:43:55 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#include "../../../UTILITIZE/STD_TYPE.h"
#include "../../../UTILITIZE/BIT_MATH.h"

#include "../../../MCAL/DIO/includes/DIO_config.h"
#include "../../../MCAL/DIO/includes/DIO_interface.h"
#include "../../../MCAL/DIO/includes/DIO_private.h"

#include "../includes/LED_config.h"
#include "../includes/LED_interface.h"
#include "../includes/LED_private.h"


void LED_init(u8 LedPort,u8 LedPin)
{
	if (LedPort <=3 && LedPin<=7)
	{
		DIO_SetPinDirection(LedPort,LedPin,DIO_PIN_OUTPUT);
	}
	
	else
	{
		//No Thing
	}
}


void LED_TurnON(u8 LedPort,u8 LedPin)
{
	if (LedPort <=3 && LedPin<=7)
	{
		DIO_SetPinValue(LedPort,LedPin,DIO_PIN_HIGH);
	}
	
	else
	{
		//No Thing
	}
}


void LED_TurnOFF(u8 LedPort,u8 LedPin)
{
	if (LedPort <=3 && LedPin<=7)
	{
		DIO_SetPinValue(LedPort,LedPin,DIO_PIN_LOW);
	}
	
	else
	{
		//No Thing
	}
}


void LED_Toggle(u8 LedPort,u8 LedPin)
{
	 if (LedPort <=3 && LedPin<=7)
	 {
		DIO_TogglePinValue(LedPort,LedPin);
	 }
	 
	 else
	 {
		 //No Thing
	 }
}

