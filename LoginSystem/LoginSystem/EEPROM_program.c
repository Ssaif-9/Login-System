/*
 * EEPROM_program.c
 *
 * Created: 07-Oct-23 11:54:12 AM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "I2C_config.h"
#include "I2C_interface.h"
#include "I2C_private.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"


void EEPROM_init(void)
{
	I2C_initMaster();
}

void EEPROM_WriteByte(u16 WordAdd,u8 Data)
{
	u8 SlaveAddress = (WordAdd>>8) | EEPROM_FIXED_ADDRESS ;
	
	I2C_sendStartCondition();
	
	I2C_sendSlaveAddWithWrite(SlaveAddress);
	
	I2C_sendMasterDataByte((u8)WordAdd);
	
	I2C_sendMasterDataByte(Data);
	
	I2C_sendStopCondition();
	
	_delay_ms(5);
}

void EEPROM_ReadByte(u16 WordAdd,u8* Data)
{
	if(Data != NULL)
	{
		u8 SlaveAddress = (WordAdd>>8) | EEPROM_FIXED_ADDRESS ;
		
		I2C_sendStartCondition();
		
		I2C_sendSlaveAddWithWrite(SlaveAddress);
		
		I2C_sendMasterDataByte((u8)WordAdd);
		
		I2C_sendRepStartCondition();
		
		I2C_sendSlaveAddWithRead(SlaveAddress);
		
		I2C_recieveMasterDataByte(Data);
		
		I2C_sendStopCondition();
		
		_delay_ms(5);
	}
	else
	{
		//No Thing 
	}
}