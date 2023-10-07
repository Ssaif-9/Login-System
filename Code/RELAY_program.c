/*
 * RELAY_program.c
 *
 * Created: 24-Sep-23 8:22:40 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 


#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "RELAY_config.h"
#include "RELAY_interface.h"
#include "RELAY_private.h"


void RELAY_init(u8 RelayPort,u8 RelayPin)
{
	if (RelayPort <= 3 && RelayPin <=7 )
	{
		DIO_SetPinDirection(RelayPort,RelayPin,DIO_PIN_OUTPUT);
	}
	else
	{
		//No Thing
	}
}

void RELAY_TurnON(u8 RelayPort,u8 RelayPin)
{
	if (RelayPort <= 3 && RelayPin <=7 )
	{
		DIO_SetPinValue(RelayPort,RelayPin,DIO_PIN_HIGH);
	}
	else
	{
		//No Thing
	}
}

void RELAY_TurnOFF(u8 RelayPort,u8 RelayPin)
{
	if (RelayPort <= 3 && RelayPin <=7 )
	{
		DIO_SetPinValue(RelayPort,RelayPin,DIO_PIN_LOW);
	}
	else
	{
		//No Thing
	}
}

void RELAY_Toggle(u8 RelayPort,u8 RelayPin)
{
	if (RelayPort <= 3 && RelayPin <=7 )
	{
		DIO_TogglePinValue(RelayPort,RelayPin);
	}
	else
	{
		//No Thing
	}
}