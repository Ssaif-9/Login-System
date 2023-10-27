/*
 * RELAY_interface.h
 *
 * Created: 24-Sep-23 8:22:59 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_


void RELAY_init        (u8 RelayPort,u8 RelayPin);
void RELAY_TurnON      (u8 RelayPort,u8 RelayPin);
void RELAY_TurnOFF     (u8 RelayPort,u8 RelayPin);
void RELAY_Toggle      (u8 RelayPort,u8 RelayPin);

#endif /* RELAY_INTERFACE_H_ */