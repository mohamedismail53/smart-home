/*************************************************************/
/* DIO_Interface.h                                           */
/* Description: Interfacing - ATMega32 DIO driver            */
/* Author: Abdulrahman Elsayed                               */
/* Date: 4/16/2021                                           */
/* Version: 03                                               */
/*************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "std_types.h"

#define PORTA 0 
#define PORTB 1
#define PORTC 2 
#define PORTD 3 

#define PIN0 0 
#define PIN1 1
#define PIN2 2 
#define PIN3 3 
#define PIN4 4 
#define PIN5 5
#define PIN6 6 
#define PIN7 7

#define INPUT  0 
#define OUTPUT 1

#define LOW    0
#define HIGH   1

void DIO_Init(void);
void DIO_SetPinDirection(uint8 portno, uint8 pinno, uint8 state);
void DIO_SetPortDirection(uint8 portno, uint8 state);
void DIO_SetPinValue(uint8 portno, uint8 pinno, uint8 value);
void DIO_SetPortValue(uint8 portno, uint8 value);
uint8 DIO_RdPinValue(uint8 portno, uint8 pinno);
uint8 DIO_RdPortValue(uint8 portno);

#endif