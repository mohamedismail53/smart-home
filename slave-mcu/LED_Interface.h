/*************************************************************/
/* LED_Interface.h                                           */
/* Description: Interfacing - ATMega32 LED driver            */
/* Author: Abdulrahman Elsayed                               */
/* Date: 4/17/2021                                           */
/* Version: 01                                               */
/*************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "std_types.h"
#include "DIO_Interface.h"

void LED_Init(uint8 portno, uint8 pinno);
void LED_On(uint8 portno, uint8 pinno);
void LED_Off(uint8 portno, uint8 pinno);
void LED_Toggle(uint8 portno, uint8 pinno);
uint8 LED_Rdstatus(uint8 portno, uint8 pinno);

#endif