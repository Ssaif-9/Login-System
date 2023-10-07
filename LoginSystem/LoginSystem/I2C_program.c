/*
 * I2C_program.c
 *
 * Created: 06-Oct-23 8:05:26 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "I2C_config.h"
#include "I2C_interface.h"
#include "I2C_private.h"

void I2C_initMaster(void)
{
	/*	SCL 400KHZ	*/
	TWBR=0b00001100;       //12
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	
	/*	Enable Acknowledge	*/
	SET_BIT(TWCR,TWEA);

	/*	Enable interrupt if work by call back	*/
	//SET_BIT(TWCR,TWIE);
	
	/*	Enable I2C	*/
	SET_BIT(TWCR,TWEN);
}

void I2C_sendStartCondition(void)
{
	/*	Enable Start Condition	*/
	SET_BIT(TWCR,TWSTA);
	
	/*	Clear Flag to request Start Condition */
	SET_BIT(TWCR,TWINT);
	
	/*Busy Wait The Flag	*/
	while(0 == GET_BIT(TWCR,TWINT));
	
	/*	Check StatsValue to make sure start Condition is true */
	while(I2C_StatsValue != I2C_StartCondotioanAck);       
	 
}

void I2C_sendRepStartCondition(void)
{
	/*	Enable Start Condition	*/
	SET_BIT(TWCR,TWSTA);
	
	/*	Clear Flag to request Start Condition */
	SET_BIT(TWCR,TWINT);
	
	/*Busy Wait The Flag	*/
	while(0 == GET_BIT(TWCR,TWINT));
	
	/*	Check StatsValue to make sure Repeated start Condition is true */
	while(I2C_StatsValue != I2C_RepeatedStartCondotioanAck);       
}

void I2C_sendStopCondition(void)
{
	/*	Enable Stop Condition	*/
	SET_BIT(TWCR,TWSTO);
	
	/*	Clear Flag to request Start Condition */
	SET_BIT(TWCR,TWINT);
}

void I2C_sendSlaveAddWithWrite(u8 slaveAdd)
{
	/*	Validation Address	*/
	if(slaveAdd<128)
	{
		TWDR=slaveAdd<<1;
		
		/*	Select Write Operation	*/
		CLR_BIT(TWDR,TWD0);
		
		/*	Clear Start Condition	*/
		CLR_BIT(TWCR,TWSTA);
		
		/*	Clear Flag to  Send Address To Bus	 */
		SET_BIT(TWCR,TWINT);
		
		/*Busy Wait The Flag	*/
		while(0 == GET_BIT(TWCR,TWINT));
		
		/*	Check Slave Address  */
		while(I2C_StatsValue != I2C_SlaveAddressWrireAck);
	}
	else
	{
		//No Thing
	}
}

void I2C_sendSlaveAddWithRead(u8 slaveAdd)
{
	/*	Validation Address	*/
	if(slaveAdd<128)
	{
		TWDR=slaveAdd<<1;
		
		/*	Select Read Operation	*/
		SET_BIT(TWDR,TWD0);
		
		/*	Clear Start Condition	*/
		CLR_BIT(TWCR,TWSTA);
		
		/*	Clear Flag to  Send Address To Bus	 */
		SET_BIT(TWCR,TWINT);
		
		/*Busy Wait The Flag	*/
		while(0 == GET_BIT(TWCR,TWINT));
		
		/*	Check Slave Address  */
		while(I2C_StatsValue != I2C_SlaveAddressReadAck);
	}
	else
	{
		//No Thing 
	}
}

void I2C_sendMasterDataByte(u8 TxData)
{
	/*	Send Data To Data Register	*/
	TWDR=TxData;
	
	/*	Clear Flag to  Send Address To Bus	 */
	SET_BIT(TWCR,TWINT);
	
	/*Busy Wait The Flag	*/
	while(0 == GET_BIT(TWCR,TWINT));
	
	/*	Check Master Data Send   */
	while(I2C_StatsValue != I2C_MasterSendDataAck);
	
}

void I2C_recieveMasterDataByte(u8* RxData)
{
	if(RxData!=NULL)
	{
		/*	Clear Flag to  Send Address To Bus	 */
		SET_BIT(TWCR,TWINT);
		
		/*	Busy Wait The Flag	*/
		while(0 == GET_BIT(TWCR,TWINT));
		
		/*	Check Master Data Receive  */
		while(I2C_StatsValue != I2C_MasterReceiveDataAck);
		
		/*	Receive Data From Data Register	*/
		*RxData=TWDR;
	}
	else
	{
		//No Thing
	}
}
