/*
 * BLUETOOTH_program.c
 *
 * Created: 09-Oct-23 3:09:27 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 

#include "../../../UTILITIZE/STD_TYPE.h"
#include "../../../UTILITIZE/BIT_MATH.h"

#include "../../../MCAL/UART/includes/UART_config.h"
#include "../../../MCAL/UART/includes/UART_interface.h"
#include "../../../MCAL/UART/includes/UART_private.h"




#include "../includes/BLUETOOTH_config.h"
#include "../includes/BLUETOOTH_interface.h"
#include "../includes/BLUETOOTH_private.h"



void BLUETOOTH_init(void)
{
	UART_init();
}

void BLUETOOTH_TransimitChar(u8 TransimitData)
{
	UART_TransmiteChar(TransimitData);
}

void BLUETOOTH_ReceiveChar(u8* ReceiveData)
{
	UART_ReceiveChar(ReceiveData);
}

void BLUETOOTH_TransimitString (u8* TransimitData)
{
	UART_TransmiteString(TransimitData);
}