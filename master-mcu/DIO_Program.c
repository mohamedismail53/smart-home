/*************************************************************/
/* DIO_Program.c                                             */
/* Description: Implementaion - ATMega32 DIO driver          */
/* Author: Abdulrahman Elsayed                               */
/* Date: 4/16/2021                                           */
/* Version: 03                                               */
/*************************************************************/


#include "Bit_Math.h"

#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "DIO_Config.h"

void DIO_Init(void) {
    DDRA_REG = DDRA_INIT;
    DDRB_REG = DDRB_INIT;
    DDRC_REG = DDRC_INIT;
    DDRD_REG = DDRD_INIT;
    PORTA_REG = PORTA_INIT; 
    PORTB_REG = PORTB_INIT;
    PORTC_REG = PORTC_INIT;
    PORTD_REG = PORTD_INIT;
} 

void DIO_SetPinDirection(uint8 portno, uint8 pinno, uint8 state) {

    if (state == INPUT) {
        switch(portno) {
            case PORTA: CLR_BIT(DDRA_REG, pinno); break;
            case PORTB: CLR_BIT(DDRB_REG, pinno); break;
            case PORTC: CLR_BIT(DDRC_REG, pinno); break;
            case PORTD: CLR_BIT(DDRD_REG, pinno); break;       
            default: break;  
        }
    }
    else if (state == OUTPUT) {
        switch(portno) {
            case PORTA: SET_BIT(DDRA_REG, pinno); break;
            case PORTB: SET_BIT(DDRB_REG, pinno); break;
            case PORTC: SET_BIT(DDRC_REG, pinno); break;
            case PORTD: SET_BIT(DDRD_REG, pinno); break;    
            default: break;     
        }
    }
}

void DIO_SetPortDirection(uint8 portno, uint8 state) {
    switch(portno) {
        case PORTA: DDRA_REG = state; break;
        case PORTB: DDRB_REG = state; break;
        case PORTC: DDRC_REG = state; break;
        case PORTD: DDRD_REG = state; break;        
        default: break; 
        }
}

void DIO_SetPinValue(uint8 portno, uint8 pinno, uint8 value) {
    if (value == LOW) {
        switch(portno) {
            case PORTA: CLR_BIT(PORTA_REG, pinno); break;
            case PORTB: CLR_BIT(PORTB_REG, pinno); break;
            case PORTC: CLR_BIT(PORTC_REG, pinno); break;
            case PORTD: CLR_BIT(PORTD_REG, pinno); break;   
            default: break;      
        }
    }
    else if (value == HIGH) {
        switch(portno) {
            case PORTA: SET_BIT(PORTA_REG, pinno); break;
            case PORTB: SET_BIT(PORTB_REG, pinno); break;
            case PORTC: SET_BIT(PORTC_REG, pinno); break;
            case PORTD: SET_BIT(PORTD_REG, pinno); break;    
            default: break;     
        }
    }
}

void DIO_SetPortValue(uint8 portno, uint8 value) { 
    switch(portno) {
        case PORTA: PORTA_REG = value; break;
        case PORTB: PORTB_REG = value; break;
        case PORTC: PORTC_REG = value; break;
        case PORTD: PORTD_REG = value; break;      
        default: break;  
        }
}

uint8 DIO_RdPinValue(uint8 portno, uint8 pinno) {
    switch(portno) {
            case PORTA: return RD_BIT(PINA_REG, pinno); break;
            case PORTB: return RD_BIT(PINB_REG, pinno); break;
            case PORTC: return RD_BIT(PINC_REG, pinno); break;
            case PORTD: return RD_BIT(PIND_REG, pinno); break;     
            default: break;    
        } 
}

uint8 DIO_RdPortValue(uint8 portno) { 
    switch(portno) {
            case PORTA: return PINA_REG; break;
            case PORTB: return PINB_REG; break;
            case PORTC: return PINC_REG; break;
            case PORTD: return PIND_REG; break;        
            default: break; 
    } 
}