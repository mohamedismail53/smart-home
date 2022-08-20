/*
 * Servo.h
 *
 * Created: 4/22/2021 10:37:24 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "Timer_INT.h"



/************************************************************************/
/*								Functions Prototypes                    */
/************************************************************************/


/*********************************************************************************************************
 * Function Name: Servo_Init
 *
 * Description:  Function to initialize servo first position 
 *
 * Function Parameters:	        NONE
 *
 * Returns:						NONE
 ********************************************************************************************************/
void Servo_Init(void);


/*********************************************************************************************************
 * Function Name: Servo_SetAngle
 *
 * Description:  Function to set angle for servo 
 *
 * Function Parameters:	 the only need parameter is servo desired angle
 *
 * Returns:						NONE
 ********************************************************************************************************/
void Servo_SetAngle(uint8 angle);


#endif /* SERVO_H_ */