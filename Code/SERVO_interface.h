/*
 * SERVO_interface.h
 *
 * Created: 26-Sep-23 2:06:02 AM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void SERVO_init           (void);
void SERVO_TurnON         (u16 freq ,u16 Duty);
void SERVO_TurnOFF        (void);


#endif /* SERVO_INTERFACE_H_ */