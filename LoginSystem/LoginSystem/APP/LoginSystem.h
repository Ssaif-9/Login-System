/*
 * PRIVATE_PASSWARD.h
 *
 * Created: 07-Oct-23 9:15:16 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef PRIVATE_PASSWARD_H_
#define PRIVATE_PASSWARD_H_

/*Mode Config	*/

#define BluetoothMode     0
#define KeypadMode        1


/*	Password Config	*/

#define MaxPasswardSize       3
#define PASSWARD_VALUE        123


/*	LED Config	*/

#define WARNING_LED_PORT    DIO_PORTB
#define WARNING_LED_PIN     DIO_PIN5

#define NOK_LED_PORT        DIO_PORTB
#define NOK_LED_PIN         DIO_PIN6

#define OK_LED_PORT         DIO_PORTB
#define OK_LED_PIN          DIO_PIN7


/*	LCD Config	*/

#define LCD_MODE        LCD_FourBitMode   // LCD_FourBitMode ||  LCD_EightBitMode

#define LCD_PORT        DIO_PORTA

#define LCD_RS_PORT     DIO_PORTB
#define LCD_RS_PIN      DIO_PIN1

#define LCD_RW_PORT     DIO_PORTB
#define LCD_RW_PIN      DIO_PIN2

#define LCD_EN_PORT     DIO_PORTB
#define LCD_EN_PIN      DIO_PIN3

#define LCD_D4_PORT     DIO_PORTA
#define LCD_D4_PIN      DIO_PIN4

#define LCD_D5_PORT     DIO_PORTA
#define LCD_D5_PIN      DIO_PIN5

#define LCD_D6_PORT     DIO_PORTA
#define LCD_D6_PIN      DIO_PIN6

#define LCD_D7_PORT     DIO_PORTA
#define LCD_D7_PIN      DIO_PIN7

#define LCD_GO_TO_2ND_LINE                    0b11000000


/*	Keypad Config	*/

#define KEYPAD_ROW0_PORT         DIO_PORTA
#define KEYPAD_ROW0_PIN          DIO_PIN0

#define KEYPAD_ROW1_PORT         DIO_PORTA
#define KEYPAD_ROW1_PIN          DIO_PIN1

#define KEYPAD_ROW2_PORT         DIO_PORTA
#define KEYPAD_ROW2_PIN          DIO_PIN2

#define KEYPAD_ROW3_PORT         DIO_PORTA
#define KEYPAD_ROW3_PIN          DIO_PIN3

#define KEYPAD_COL0_PORT         DIO_PORTC
#define KEYPAD_COL0_PIN          DIO_PIN4

#define KEYPAD_COL1_PORT         DIO_PORTC
#define KEYPAD_COL1_PIN          DIO_PIN5

#define KEYPAD_COL2_PORT         DIO_PORTC
#define KEYPAD_COL2_PIN          DIO_PIN6

#define KEYPAD_COL3_PORT         DIO_PORTC
#define KEYPAD_COL3_PIN          DIO_PIN7


#define KEYPAD_PATTERN     { { 7 ,8, 9 ,'/'},      \
                             { 4 ,5, 6 ,'*'},      \
                             { 1 ,2, 3 ,'-'},      \
                             {'#',0,'=','+'}       \
	                       }
						   
						   
/*	Relay Config	*/

#define RELAY_PORT    DIO_PORTB
#define RELAY_PIN     DIO_PIN4


/*	Servo Config	*/

#define CLOSE_Angle    0
#define OPEN_Angle     90

#define SERVO_PORT DIO_PORTD
#define SERVO_PIN  DIO_PIN7

#define TMR1_OC1A_PORT DIO_PORTD
#define TMR1_OC1A_PIN  DIO_PIN5

/*	Bluetooth Config*/

#define  UART_SelectedBoudRate 9600 // 2400 || 4800 || 9600 || 14400 || 19200 || 28800 || 38400 || 57600 || 76800 || 115200 || 230400 ||250000

#define UART_TX_PORT   DIO_PORTD
#define UART_TX_PIN    DIO_PIN1

#define UART_RX_PORT   DIO_PORTD
#define UART_RX_PIN    DIO_PIN0

/*	Button Config	*/

#define SwitchMode_BUTTON_PORT    DIO_PORTB
#define SwitchMode_BUTTON_PIN     DIO_PIN0

#endif /* PRIVATE_PASSWARD_H_ */