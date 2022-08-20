/*
 * pro.c
 *
 *  Created on: Apr 19, 2021
 *      Author: dell
 */


#define F_CPU 8000000UL
#include <avr/delay.h>
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include <stdio.h>
#include <string.h>
#include <avr/eeprom.h>
#include"keyPad.h"
#include"LCD_CONFIG.h"
#include"LCD_INT.h"
#include "ultrasonic.h"
#include "timer.h"
#include "timer_config.h"
#include "SPI.h"

#define	LIVING_ROOM_ON	1
#define	LIVING_ROOM_OFF	2
#define	TV_ON			3
#define	TV_OFF			4
#define	BED_ROOM_ON		5
#define	BED_ROOM_OFF	6
#define	KIDS_ROOM_ON	7
#define	KIDS_ROOM_OFF	8
#define	AIR_COND_ON		9
#define	AIR_COND_OFF	10
#define	RIGHT_PASSWARD	11
#define WRONG_FOR_3TIMES 12
#define SET_TEMPERATURE	13
#define DOOR_DELAY 1000
#define LCD_DELAY 300

void show_all_options();
void Door();
void settings();
void AC_manager();
void device_manager(uint8 room_num,char *room,char *device,uint8 SPI_on_code,uint8 SPI_off_code);
void room_manager(uint8 room_num,char *room,uint8 SPI_on_code,uint8 SPI_off_code);
void set_temp();

uint8 main(void)
{
	uint8 read[5];
	uint8 read_1[5];
	uint8 j=0,i=0;
	uint8 out_1,out=0;
	uint8 key_in,key;
	uint8 count,count_1;
	uint8 o=0;
	uint8 o_1;
	uint8 wrong=0;

	SPI_init_as_master(false);
	LCD_init();
	DIO_SetPinDirection(PORTB,PIN0,INPUT);
	DIO_SetPinDirection(TRIGGER_PORT,7,OUTPUT);
	ultrasonic_init();
	SREG=SREG|(1<<7);


	if(PINB&(1<<0))
	{
		for ( count_1=0;count_1<5;count_1++)
		{
			eeprom_write_byte (count_1,0xFF);
		}
	}



	if(((eeprom_read_byte((const uint8_t *)(0))==0xFF)&&(eeprom_read_byte((const uint8_t *)(1))==0xFF)&&(eeprom_read_byte((const uint8_t *)(2))==0xFF)&&(eeprom_read_byte((const uint8_t *)(3))==0xFF)&&(eeprom_read_byte((const uint8_t *)(4))==0xFF)))
	{
		if(i!=5)
		{
			LCD_displayString("enter your first ");
			LCD_goToRowColumn(1,2);
			LCD_displayString(" password");
		}
		while((i!=5))
		{
			key = KeyPad_getPressedKey();
			if(!(i==5))
			{
				if(!(out==1)){out++;LCD_clearScreen();}
				if ((key>= 0) && (key<= 9))
				{
					eeprom_write_byte (i,key);
					LCD_intgerToString(key);
					_delay_ms(500);
					LCD_goToRowColumn(0,i);
					LCD_displayCharacter('*');
					i++;
				}
				else
				{
					eeprom_write_byte (i,key);
					if(key=='#'){LCD_displayCharacter('#');}else if(key=='*'){LCD_displayCharacter('*');};
					_delay_ms(500);
					LCD_goToRowColumn(0,i);
					LCD_displayCharacter('*');
					i++;
				}

				_delay_ms(100);

			}

		}

		if(i==5)
		{
			o++;
			LCD_clearScreen();
			LCD_displayString("please wait");
			_delay_ms(250);
		}

		if(o==1)
		{
			for ( count=0;count<5;count++)
			{
				read[count]=eeprom_read_byte((const uint8_t *)(count));
			}
		}
		_delay_ms(250);
		LCD_clearScreen();
		LCD_displayString("saved");
		_delay_ms(500);
		LCD_clearScreen();

	}

	for ( count=0;count<5;count++)
	{
		read[count]=eeprom_read_byte((const uint8_t *)(count));
	}
	if(j==0)
	{

		out_1=0;
		LCD_displayString("  enter your");
		LCD_goToRowColumn(1,2);
		LCD_displayString(" password");
		o_1=0;
	}

	//******************************writing the  password to enter home******************************************//

	while ((o_1!=1)){

		key_in = KeyPad_getPressedKey();

		if(!(j==5)){

			{if(!(out_1==1)){out_1++;LCD_clearScreen();}}

			if ((key_in>= 0) && (key_in<= 9))
			{read_1[j]=key_in;

			LCD_intgerToString(key_in);
			_delay_ms(50);
			LCD_goToRowColumn(0,j);
			LCD_displayCharacter('*');
			j++;
			}
			else
			{read_1[j]=key_in ;

			if(key_in=='#'){LCD_displayCharacter('#');}else if(key_in=='*'){LCD_displayCharacter('*');};
			_delay_ms(50);
			LCD_goToRowColumn(0,j);
			LCD_displayCharacter('*');
			j++;
			}

			_delay_ms(100);

		}


	if(j==5){

		LCD_clearScreen();
		LCD_displayString("please wait");
		_delay_ms(500);
		LCD_clearScreen();

		if((read[0]==read_1[0])&&(read[1]==read_1[1])&&(read[2]==read_1[2])&&(read[3]==read_1[3])&&(read[4]==read_1[4]))
		{

			LCD_clearScreen();
			o_1=1;

			show_all_options();

		}

		else
		{
			LCD_displayString("wrong password");
			_delay_ms(LCD_DELAY);
			LCD_clearScreen();o_1=0;j=0;
			wrong++;
			if(wrong==3)
			{
			SPI_send_char(WRONG_FOR_3TIMES);
			LCD_displayString("wait 6 sec");
			_delay_ms(6000);
			LCD_clearScreen();
			wrong=0;}
			LCD_displayString("  enter your ");
			LCD_goToRowColumn(1,2);
			LCD_displayString(" password");
			_delay_ms(1000);
			LCD_clearScreen();



			}


		}


	}

}



void show_all_options(){
	while(1)
	{
		LCD_clearScreen();
		LCD_displayString("Door     1");
		LCD_goToRowColumn(1,0);
		LCD_displayString("settings 2");
		if(KeyPad_getPressedKey()==1)
		{
			Door();
		}

		else if(KeyPad_getPressedKey()==2)
		{
			settings();
		}
		else
		{LCD_clearScreen();
			LCD_displayString("wrong no");
			_delay_ms(LCD_DELAY);

		}

	}
}

void Door(){
	while(1)
	{
		LCD_clearScreen();
		LCD_displayString("open door?");
		LCD_goToRowColumn(1,0);
		LCD_displayString("   yes1   no2");

		if(KeyPad_getPressedKey()==1)
		{
			SPI_send_char(RIGHT_PASSWARD);       //open door
			LCD_clearScreen();
			LCD_displayString(" the door is ");
			LCD_goToRowColumn(1,2);
			LCD_displayString(" opening ");
			_delay_ms(LCD_DELAY);
			LCD_clearScreen();
			LCD_displayString(" Welcome! ");
			for(uint16 i =0 ; i<2*
			DOOR_DELAY;i++)        //send until door closes and a while after it
			{
				ultrasonic_trigger();
				_delay_ms(1);

			}
			break;

		}

		else if(KeyPad_getPressedKey()!=2)
		{
			LCD_clearScreen();
			LCD_displayString("wrong no");
			_delay_ms(LCD_DELAY);
		}
		else{break;}


	}


}
void settings(){
	while(1)
	{
		LCD_clearScreen();
		LCD_displayString("show settings?");
		_delay_ms(500);
		LCD_goToRowColumn(1,0);
		LCD_displayString("   yes1   no2");
		_delay_ms(500);
		if(KeyPad_getPressedKey()==1)
		{
			LCD_clearScreen();
			//---------------AC-------------------
			AC_manager();
			//---------------living room-------------------
			room_manager(1,"living",LIVING_ROOM_ON,LIVING_ROOM_OFF);
			//---------------bed room-------------------
			room_manager(2,"bed",BED_ROOM_ON,BED_ROOM_OFF);
			//---------------kids room-------------------
			room_manager(3,"kids",KIDS_ROOM_ON,KIDS_ROOM_OFF);
		}

		else if(KeyPad_getPressedKey()!=2)
		{
			LCD_clearScreen();
			LCD_displayString("wrong no");
			_delay_ms(LCD_DELAY);
		}
		else{break;}

	}

}

void AC_manager(){
	while(1){

	LCD_clearScreen();
	LCD_displayString("  AC");
	LCD_goToRowColumn(1,0);
	LCD_displayString("   on1   off2");
	if(KeyPad_getPressedKey()==1)
	{
		set_temp();
		break;
	}


	else if(KeyPad_getPressedKey()!=2)
	{
		LCD_clearScreen();
		LCD_displayString("wrong no");
		_delay_ms(LCD_DELAY);
	}
	else
	{
		LCD_clearScreen();
		SPI_send_char(AIR_COND_OFF);
		LCD_displayString("off");
		_delay_ms(LCD_DELAY);
		break;

	}


}
}

void set_temp(){
	uint8 d1,d2;
	while(1){
		LCD_clearScreen();
		LCD_displayString("set AC temp ?");
		LCD_goToRowColumn(1,0);
		LCD_displayString("   yes1   no2");

		if(KeyPad_getPressedKey()==1)
		{
			while(1)
			{
				LCD_clearScreen();
				LCD_displayString("enter temp:");
				_delay_ms(300);
				do{d1 = KeyPad_getPressedKey();}
				while((d1== '#')||(d1== '*'));
				LCD_goToRowColumn(1,0);
				LCD_intgerToString(d1);
				_delay_ms(200);
				do{d2 = KeyPad_getPressedKey();}
				while((d2== '#')||(d2== '*'));
				LCD_goToRowColumn(1,1);
				LCD_intgerToString(d2);
				_delay_ms(200);
				SPI_send_char(SET_TEMPERATURE);

				uint8 temp = d1*10+d2;
				if((temp < 20)||(temp >= 45))
				{
					LCD_clearScreen();
					LCD_displayString("invalid temp");
					_delay_ms(LCD_DELAY);
				}
				else
				{
					SPI_send_char(temp);
					break;
				}

				_delay_ms(200);
				LCD_clearScreen();
			}
			break;
		}


		else if(KeyPad_getPressedKey()!=2)
		{
			LCD_clearScreen();
			LCD_displayString("wrong no");
			_delay_ms(LCD_DELAY);
		}
		else
		{
			LCD_clearScreen();
			SPI_send_char(AIR_COND_ON);
			LCD_displayString("on");
			_delay_ms(LCD_DELAY);
			break;
		}
	}
}



void room_manager(uint8 room_num,char *room,uint8 SPI_on_code,uint8 SPI_off_code){

	while(1){
	LCD_clearScreen();
	LCD_displayString(room);

	LCD_displayString(" room");
	_delay_ms(500);
	LCD_goToRowColumn(1,2);
	LCD_displayString("press ");
	_delay_ms(500);
	LCD_intgerToString(room_num);
	if (room_num==3)
	{
		LCD_displayString("  quit0");
		_delay_ms(500);
	}
	else
	{
		LCD_displayString("  next0");
		_delay_ms(500);
	}
	if(KeyPad_getPressedKey()==room_num)
	{
		if(room_num==1)    //living room
		{
			device_manager(room_num,room,"led",SPI_on_code,SPI_off_code);
			device_manager(room_num,room,"TV",TV_ON, TV_OFF);
		}
		else{
			device_manager(room_num,room,"led",SPI_on_code,SPI_off_code);
		}
	}
	else if(KeyPad_getPressedKey()!=0)
	{
		LCD_clearScreen();
		LCD_displayString("wrong no");
		_delay_ms(LCD_DELAY);
	}
	else{break;}

	}
}

void device_manager(uint8 room_num,char *room,char *device,uint8 SPI_on_code,uint8 SPI_off_code){
		LCD_clearScreen();
		LCD_displayString(room);
		LCD_displayString(" room");
		LCD_goToRowColumn(1,2);
		LCD_displayString(device);
		LCD_displayString(": on1 off2");
		_delay_ms(500);
		if(KeyPad_getPressedKey()==1)
		{
			LCD_clearScreen();
			SPI_send_char(SPI_on_code);
			LCD_displayString("on");
			_delay_ms(LCD_DELAY);
		}
		else if(KeyPad_getPressedKey()==2)
		{
			LCD_clearScreen();
			SPI_send_char(SPI_off_code);
			LCD_displayString("off");
			_delay_ms(LCD_DELAY);
		}
		else
		{
			LCD_clearScreen();
			LCD_displayString("wrong");
			_delay_ms(LCD_DELAY);
		}

}













































