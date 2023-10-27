/*
 * I2C_private.h
 *
 * Created: 06-Oct-23 8:05:54 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define I2C_StatsValue                   (TWSR&0xF8)  
  
#define I2C_StartCondotioanAck           0x08
#define I2C_RepeatedStartCondotioanAck   0x10
#define I2C_SlaveAddressWrireAck         0x18       
#define I2C_SlaveAddressReadAck          0x40 
#define I2C_MasterSendDataAck            0x28
#define I2C_MasterReceiveDataAck         0x50


#define TWBR            (*(volatile u8*)0x20)
/*	TWI Bit Rate 	*/
#define TWBR0           0
#define TWBR1           1
#define TWBR2           2
#define TWBR3           3
#define TWBR4           4
#define TWBR5           5
#define TWBR6           6
#define TWBR7           7



#define TWCR            (*(volatile u8*)0x56)
#define TWIE            0
#define TWEN            2
#define TWWC            3
#define TWSTO           4
#define TWSTA           5
#define TWEA            6
#define TWINT           7

#define TWSR           (*(volatile u8*)0x21)
#define TWPS0           0
#define TWPS1           1
/*	TWI Status	*/
#define TWS3            3
#define TWS4            4
#define TWS5            5
#define TWS6            6
#define TWS7            7


#define TWDR           (*(volatile u8*)0x23)
/*	TWI Data 	*/
#define TWD0           0
#define TWD1           1
#define TWD2           2
#define TWD3           3
#define TWD4           4
#define TWD5           5
#define TWD6           6
#define TWD7           7



#define TWAR           (*(volatile u8*)0x22)
#define TWGCE          0
/*	TWI (Slave) Address 	*/
#define TWA0           1
#define TWA1           2
#define TWA2           3
#define TWA3           4
#define TWA4           5
#define TWA5           6
#define TWA6           7


#endif /* I2C_PRIVATE_H_ */