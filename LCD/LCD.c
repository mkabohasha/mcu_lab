/*
 * LCD.c
 *
 *  Created on: Sep 10, 2020
 *      Author: mkabo
 */
#include <util/delay.h>
#include"../../LIB/STD_types.h"
#include"../../LIB/Bit_Math.h"
#include"../../MCAL/DIO/DIO_types.h"
#include"../../MCAL/DIO/DIO.h"
#include"LCD.h"
static uint8 intSF = 0;



void LCD_Init()
{
	DIO_SetPortDirection(PORTD,Output);
	DIO_SetPortDirection(PORTB,Output);
	_delay_ms(30);
	LCD_WriteCMD(0x20);
	LCD_WriteCMD(0x20);
	LCD_WriteCMD(0x80);
	_delay_ms(1);
	LCD_WriteCMD(0x00);
	LCD_WriteCMD(0xF0);
	_delay_ms(1);
	LCD_WriteCMD(0x00);
	LCD_WriteCMD(0x10);
	_delay_ms(2);

	intSF = 1;
}

void LCD_WriteCMD(uint8 cmd)
{
	DIO_SetPinValue (PORTB, Pin1 ,LOW);//RS = 0
	DIO_SetPinValue (PORTB, Pin2 ,LOW);//RW=0

	DIO_SetPinValue (PORTD, Pin4 ,GET_BIT(cmd , 4));
	DIO_SetPinValue (PORTD, Pin5 ,GET_BIT(cmd , 5));
	DIO_SetPinValue (PORTD, Pin6 ,GET_BIT(cmd , 6));
	DIO_SetPinValue (PORTD, Pin7 ,GET_BIT(cmd , 7));
	DIO_SetPinValue (PORTB, Pin3 ,HIGH); // enable lower bits
	_delay_ms(1);
	DIO_SetPinValue (PORTB, Pin3 ,LOW);
	if (intSF){
	DIO_SetPinValue (PORTD, Pin4 ,GET_BIT(cmd , 0));
	DIO_SetPinValue (PORTD, Pin5 ,GET_BIT(cmd , 1));
	DIO_SetPinValue (PORTD, Pin6 ,GET_BIT(cmd , 2));
	DIO_SetPinValue (PORTD, Pin7 ,GET_BIT(cmd , 3));
	DIO_SetPinValue (PORTB, Pin3 ,HIGH); // enable lower bits
		_delay_ms(1);
		DIO_SetPinValue (PORTB, Pin3 ,LOW); // falling edge to read data

	}
	_delay_ms(2); // delay for call this fun 2 times
}

void LCD_WriteData(uint8 data)
{
	DIO_SetPinValue (PORTB, Pin1 ,HIGH);//RS = 1
		DIO_SetPinValue (PORTB, Pin2 ,LOW);//RW=0

		DIO_SetPinValue (PORTD, Pin4 ,GET_BIT(data , 4));
		DIO_SetPinValue (PORTD, Pin5 ,GET_BIT(data , 5));
		DIO_SetPinValue (PORTD, Pin6 ,GET_BIT(data , 6));
		DIO_SetPinValue (PORTD, Pin7 ,GET_BIT(data , 7));
		DIO_SetPinValue (PORTB, Pin3 ,HIGH); // enable lower bits
		_delay_ms(1);
		DIO_SetPinValue (PORTB, Pin3 ,LOW);

		DIO_SetPinValue (PORTD, Pin4 ,GET_BIT(data , 0));
		DIO_SetPinValue (PORTD, Pin5 ,GET_BIT(data , 1));
		DIO_SetPinValue (PORTD, Pin6 ,GET_BIT(data , 2));
		DIO_SetPinValue (PORTD, Pin7 ,GET_BIT(data , 3));
		DIO_SetPinValue (PORTB, Pin3 ,HIGH); // enable lower bits
			_delay_ms(1);
			DIO_SetPinValue (PORTB, Pin3 ,LOW); // falling edge to read data
		_delay_ms(2); // delay for call this fun 2 times
}

void LCD_Writestring(uint8* str)
{
	uint8 index = 0;
	while(str[index] !='\0')
	{
		LCD_WriteData(str[index]);
		index++;
	}
}
void LCD_GoToPos(uint8 row,uint8 colm)
{

}
