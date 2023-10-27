/*
 * ButtonProgram.c
 *
 * Created: 01-Sep-23 10:41:32 PM
 *  Author: SEIF EL-DIN SOLTAN 
 */ 


#include "../../../UTILITIZE/STD_TYPE.h"
#include "../../../UTILITIZE/BIT_MATH.h"

#include "../../../MCAL/DIO/includes/DIO_config.h"
#include "../../../MCAL/DIO/includes/DIO_interface.h"
#include "../../../MCAL/DIO/includes/DIO_private.h"

#include "../includes/BUTTON_config.h"
#include "../includes/BUTTON_interface.h"
#include "../includes/BUTTON_private.h"

void BUTTON_init(u8 ButtonPort ,u8 ButtonPin)
{
	if (ButtonPort <=3 && ButtonPin<=7)
	{
		DIO_SetPinDirection(ButtonPort,ButtonPin,DIO_PIN_INPUT);
	}
	else
	{
		//No Thing
	}
}

void BUTTON_ActivePullUp(u8 ButtonPort ,u8 ButtonPin)
{
	if (ButtonPort <=3 && ButtonPin<=7)
	{
		DIO_activePinInPullUpResistance(ButtonPort,ButtonPin);
	}
	else
	{
		//No Thing
	}
}

void BUTTON_ReadValue(u8 ButtonPort ,u8 ButtonPin,u8* PinValue,u8 BUTTON_STATUE)
{
	if (ButtonPort <=3 && ButtonPin<=7)
	{
		DIO_ReadValue(ButtonPort,ButtonPin,PinValue);
	}
	else
	{
		//No Thing
	}
}
