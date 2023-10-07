/*
 * I2C.c
 *
 * Created: 06-Oct-23 8:04:56 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "TIMER1_interface.h"

#include "UART_interface.h"

#include "I2C_interface.h"
#include "I2C_private.h"

#include "KEYPAD_interface.h"

#include "SERVO_interface.h"

#include "LCD_interface.h"

#include "LED_interface.h"

#include "RELAY_interface.h"

#include "BUTTON_interface.h"

#include "PRIVATE_PASSWARD.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"

u8 WrongCounter=2;

int main(void)
{
	u8 TakenPassword[MaxPasswardSize];
	u8 StoagePassword;
	
	u16 password;
	u8 passwordSize=0;
	u8 ReceiveValue;
	u8 KeypadValue;
	u8 Index=0;
	u8 ButtonValue;
    
	
	
	KEYPAD_init();
	UART_init();
	SERVO_init();
	SERVO_TurnON(4999,374);
	LCD_init();
	RELAY_init(RELAY_PORT,RELAY_PIN);
	LED_init(WARNING_LED_PORT,WARNING_LED_PIN);
	LED_init(NOK_LED_PORT,NOK_LED_PIN);
	LED_init(OK_LED_PORT,OK_LED_PIN);
	BUTTON_init(SwitchMode_BUTTON_PORT,SwitchMode_BUTTON_PIN);
	
	LCD_SendString("    WELCOME    ");
	_delay_ms(1500);
	LCD_ClearDesplay();
	LCD_SendString("PASSWORD:");
	
	EEPROM_init();
	
    while(1)
    {
		EEPROM_WriteByte(200,PASSWARD_VALUE);
		_delay_ms(10);
		EEPROM_ReadByte(200,&StoagePassword);
		_delay_ms(10);
		BUTTON_ReadValue(SwitchMode_BUTTON_PORT,SwitchMode_BUTTON_PIN,&ButtonValue,BUTTON_PullDown);
		
		/*	BLUETOTH MODE	*/
		if (ButtonValue == BluetoothMode)
		{
			UART_ReceiveChar(&ReceiveValue);
		    if(ReceiveValue>=48 && ReceiveValue<=57  && passwordSize!=3)
		    {
		  		TakenPassword[Index]=ReceiveValue-48;
		  		Index++;
		  		passwordSize++;
		  		LCD_sendChar('*');
		    }
		    
		    password =TakenPassword[0]*100+TakenPassword[1]*10+TakenPassword[2]*1;
		    
		    if(ReceiveValue == '=' && passwordSize ==3 )
		    {
		  		if(password==StoagePassword)
		  		{
		  			WrongCounter=2;
		  			LCD_sendComnd(LCD_GO_TO_2ND_LINE);
					LCD_SendString("                 ");
					LCD_GoToLocation(1,2);
					LCD_SendString("TRUE");
					SERVO_TurnON(4999,499);
					LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
					LED_TurnOFF(NOK_LED_PORT,NOK_LED_PIN);
					LED_TurnON(OK_LED_PORT,OK_LED_PIN);
					RELAY_TurnOFF(RELAY_PORT,RELAY_PIN);
				}
				else
				{
					if(WrongCounter>0)
					{
						Index=0;
						passwordSize=0;
						LCD_sendComnd(LCD_GO_TO_2ND_LINE);
						LCD_SendString("Try Again [");
						LCD_SendIntegarNumber(WrongCounter);
						LCD_SendString("]");
						SERVO_TurnON(4999,374);
						LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
						LED_TurnOFF(NOK_LED_PORT,NOK_LED_PIN);
						LED_TurnON(WARNING_LED_PORT,WARNING_LED_PIN);
						RELAY_TurnOFF(RELAY_PORT,RELAY_PIN);
						LCD_GoToLocation(10,1);
						LCD_SendString("   ");
						LCD_GoToLocation(10,1);
						WrongCounter--;
					}
					else
					{
						LCD_ClearDesplay();
						LCD_GoToLocation(5,1);
						LCD_SendString("WARMING");
						LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
						LED_TurnON(NOK_LED_PORT,NOK_LED_PIN);
						LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
						RELAY_TurnON(RELAY_PORT,RELAY_PIN);
					}
				}
			}
			if(ReceiveValue== '#')
			{
				if (WrongCounter==0)
				{
					Index=0;
					passwordSize=0;
					LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
					LED_TurnON(NOK_LED_PORT,NOK_LED_PIN);
					LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
					RELAY_TurnON(RELAY_PORT,RELAY_PIN);
					SERVO_TurnON(4999,374);
					LCD_ClearDesplay();
					LCD_SendString("PASSWORD:");
				}
			    else
			    {
					Index=0;
					passwordSize=0;
					LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
					LED_TurnOFF(NOK_LED_PORT,NOK_LED_PIN);
					LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
					RELAY_TurnOFF(RELAY_PORT,RELAY_PIN);
					SERVO_TurnON(4999,374);
					LCD_ClearDesplay();
					LCD_SendString("PASSWORD:");  
			    }
		    }
			if(ReceiveValue!='0'|| ReceiveValue!='1'||ReceiveValue!='2' ||ReceiveValue!='3' ||ReceiveValue!='4' ||ReceiveValue!='5' ||ReceiveValue!='9' ||ReceiveValue!='7' ||ReceiveValue!='8'||ReceiveValue!='9'||ReceiveValue!='='|| ReceiveValue!= '#')
			{
				 //No Thing
		    }
		}
		
		/*	KEYPAD MODE	*/
		else 
		{
			KEYPAD_GetValue(&KeypadValue);
			if(KEYPAD_NOT_PRESSED!=KeypadValue)
			{
				if(KeypadValue!= '*' && KeypadValue!= '/' && KeypadValue!= '-' && KeypadValue!= '+' && KeypadValue!= '=' && KeypadValue!= '#' && passwordSize!=3)
				{
					TakenPassword[Index]=KeypadValue;
					Index++;
					passwordSize++;
					LCD_sendChar('*');
				}
				
				password =TakenPassword[0]*100+TakenPassword[1]*10+TakenPassword[2]*1;
				
				if(KeypadValue== '=' && passwordSize ==3)
				{
					 if(password==StoagePassword)
					 {
						 WrongCounter=2;
						 LCD_sendComnd(LCD_GO_TO_2ND_LINE);
						 LCD_SendString("                 ");
						 LCD_GoToLocation(1,2);
						 LCD_SendString("TRUE");
						 SERVO_TurnON(4999,499);
						 LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
						 LED_TurnOFF(NOK_LED_PORT,NOK_LED_PIN);
						 LED_TurnON(OK_LED_PORT,OK_LED_PIN);
						 RELAY_TurnOFF(RELAY_PORT,RELAY_PIN);
					 }
					 else
					 {
						 if(WrongCounter>0)
						 {
							 Index=0;
							 passwordSize=0;
							 LCD_sendComnd(LCD_GO_TO_2ND_LINE);
							 LCD_SendString("Try Again [");
							 LCD_SendIntegarNumber(WrongCounter);
							 LCD_SendString("]");
							 SERVO_TurnON(4999,374);
							 LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
							 LED_TurnOFF(NOK_LED_PORT,NOK_LED_PIN);
							 LED_TurnON(WARNING_LED_PORT,WARNING_LED_PIN);
							 RELAY_TurnOFF(RELAY_PORT,RELAY_PIN);
							 LCD_GoToLocation(10,1);
							 LCD_SendString("   ");
							 LCD_GoToLocation(10,1);
							 WrongCounter--;
						 }
						 else
						 {
							 LCD_ClearDesplay();
							 LCD_GoToLocation(5,1);
							 LCD_SendString("WARMING");
							 LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
							 LED_TurnON(NOK_LED_PORT,NOK_LED_PIN);
							 LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
							 RELAY_TurnON(RELAY_PORT,RELAY_PIN);
						 }
					 }
				}
				if(KeypadValue== '#')
				{
					if (WrongCounter==0)
					{
						Index=0;
						passwordSize=0;
						LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
						LED_TurnON(NOK_LED_PORT,NOK_LED_PIN);
						LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
						RELAY_TurnON(RELAY_PORT,RELAY_PIN);
						SERVO_TurnON(4999,374);
						LCD_ClearDesplay();
						LCD_SendString("PASSWORD:");
					}
					else
					{
						Index=0;
						passwordSize=0;
						LED_TurnOFF(OK_LED_PORT,OK_LED_PIN);
						LED_TurnOFF(NOK_LED_PORT,NOK_LED_PIN);
						LED_TurnOFF(WARNING_LED_PORT,WARNING_LED_PIN);
						RELAY_TurnOFF(RELAY_PORT,RELAY_PIN);
						SERVO_TurnON(4999,374);
						LCD_ClearDesplay();
						LCD_SendString("PASSWORD:");
					}
				}
				if(KeypadValue == '*' && KeypadValue== '/' && KeypadValue== '-' && KeypadValue== '+')
				{
					//No Thing
				}
			}
		}				 
    }
}