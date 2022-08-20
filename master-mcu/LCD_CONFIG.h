/*
 * LCD_CONFIG.h
 * Description: 16x2 Character LCD for chip LMB161A
				if user choose 4-bit mode then he/she connect data pins on pin4->pin7 of the same port
				user can use: LCD_Init(); for LCD Initializing
							  LCD_SendCommand(cmd); for sending command
							  LCD_SendChar(ONE CHAR); for sending Date
							  LCD_SendString(ARRAY OF CHAR); for sending string
							  LCD_String_xy(x pos, y pos, string); to put string in xy position
							  LCD_Clear(); to clear lcd
							  LCD_SendNumber the function to send a 16-integer number
 * Created: 10/16/2020 5:23:49 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"

/* Select mode 4-bit or 8-bit mode */
#define mode 4

/* select Data port */ 
#define Date	PORTC

/* select control port */
#define Control	PORTB


/* select RS pin number in control port */
#define	RS	PIN2

/* select R_W pin number in control port */
#define R_W	PIN1

/* select EN pin number in control port */
#define EN PIN3

#endif /* LCD_CONFIG_H_ */
