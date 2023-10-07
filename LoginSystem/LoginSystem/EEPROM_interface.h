/*
 * EEPROM_interface.h
 *
 * Created: 07-Oct-23 11:53:37 AM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_init             (void);
void EEPROM_WriteByte        (u16 WordAdd,u8 Data);
void EEPROM_ReadByte         (u16 WordAdd,u8* Data);

#endif /* EEPROM_INTERFACE_H_ */