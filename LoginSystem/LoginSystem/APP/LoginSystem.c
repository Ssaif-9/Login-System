/*
 * I2C.c
 *
 * Created: 06-Oct-23 8:04:56 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../UTILITIZE/STD_TYPE.h"
#include "../UTILITIZE/BIT_MATH.h"

#include "../MCAL/DIO/includes/DIO_interface.h"
#include "../MCAL/I2C/includes/I2C_interface.h"
#include "../MCAL/TMR1/includes/TIMER1_interface.h"
#include "../MCAL/UART/includes/UART_interface.h"

#include "../HAL/BUTTON/includes/BUTTON_interface.h"
#include "../HAL/EEPROM/includes/EEPROM_interface.h"
#include "../HAL/KEYPAD/includes/KEYPAD_interface.h"
#include "../HAL/LCD/includes/LCD_interface.h"
#include "../HAL/LED/includes/LED_interface.h"
#include "../HAL/RELAY/includes/RELAY_interface.h"
#include "../HAL/SERVO/includes/SERVO_interface.h"
#include "../HAL/BLUETOOTH/includes/BLUETOOTH_interface.h"

#include "LoginSystem.h"

u8 WrongCounter=2;

int main(void)
{
	u8 TakenPassword[MaxPasswardSize];
	u8 Index=0;
	u8 StoagePassword;
	
	u8 ButtonValue;
	u16 password;
	u8 passwordSize=0;
	u8 ReceiveValue;
	u8 KeypadValue;
	
	KEYPAD_init();
	SERVO_init();
	LCD_init();
	BLUETOOTH_init();
	LED_init(WARNING_LED_PORT,WARNING_LED_PIN);
	LED_init(NOK_LED_PORT,NOK_LED_PIN);
	LED_init(OK_LED_PORT,OK_LED_PIN);
	BUTTON_init(SwitchMode_BUTTON_PORT,SwitchMode_BUTTON_PIN);
	RELAY_init(RELAY_PORT,RELAY_PIN);
	EEPROM_init();
	
	SERVO_TurnON(CLOSE_Angle);
	
	EEPROM_WriteByte(0,PASSWARD_VALUE);
	_delay_ms(10);
	EEPROM_ReadByte(0,&StoagePassword);
	_delay_ms(10);
	
	LCD_SendString("    ENTER    ");
	LCD_sendComnd(LCD_GO_TO_2ND_LINE);
	LCD_SendString("    PASSWORD   ");
	_delay_ms(1500);
	LCD_ClearDesplay();
	LCD_SendString("PASSWORD:");
	
    while(1)
    {
		BUTTON_ReadValue(SwitchMode_BUTTON_PORT,SwitchMode_BUTTON_PIN,&ButtonValue,BUTTON_PullDown);
		
		/*	BLUETOTH MODE	*/
		if (ButtonValue == BluetoothMode)
		{
			BLUETOOTH_ReceiveChar(&ReceiveValue);
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
		  			 LCD_ClearDesplay();
		  			 LCD_SendString("    WELCOME    ");
		  			 LCD_sendComnd(LCD_GO_TO_2ND_LINE);
		  			 LCD_SendString("     USER     ");
					SERVO_TurnON(OPEN_Angle);
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
						SERVO_TurnON(CLOSE_Angle);
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
					SERVO_TurnON(CLOSE_Angle);
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
					SERVO_TurnON(CLOSE_Angle);
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
						 LCD_ClearDesplay();
						 LCD_SendString("    WELCOME    ");
						 LCD_sendComnd(LCD_GO_TO_2ND_LINE);
						 LCD_SendString("     USER     ");
						 SERVO_TurnON(OPEN_Angle);
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
							 SERVO_TurnON(CLOSE_Angle);
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
						SERVO_TurnON(CLOSE_Angle);
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
						SERVO_TurnON(CLOSE_Angle);
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