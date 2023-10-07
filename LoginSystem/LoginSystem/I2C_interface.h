/*
 * I2C_interface.h
 *
 * Created: 06-Oct-23 8:05:42 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


void I2C_initMaster            (void);
void I2C_sendStartCondition    (void);
void I2C_sendRepStartCondition (void);
void I2C_sendStopCondition     (void);
void I2C_sendSlaveAddWithWrite (u8 slaveAdd);
void I2C_sendSlaveAddWithRead  (u8 slaveAdd);
void I2C_sendMasterDataByte    (u8 TxData);
void I2C_recieveMasterDataByte (u8* RxData);

void I2C_initSlave             (void);
void I2C_sendSlaveDataByte     (u8 Txdata);
void I2C_recieveSlaveDataByte  (u8* Rxdata);
void I2C_SlaveListen           (void);

#endif /* I2C_INTERFACE_H_ */