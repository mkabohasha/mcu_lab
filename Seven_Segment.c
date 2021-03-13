/*
 * Seven_Segment.c
 *
 *  Created on: Sep 6, 2020
 *      Author: mkabo
 */
#include"../LIB/STD_types.h"

#include"../MCAL/DIO/DIO_types.h"
#include"../MCAL/DIO/DIO.h"
#include"../LIB/Bit_Math.h"

void Seven_Segment_Intlisation()
{
	DIO_SetPinDirection (PORTC,Pin7,Output);
	DIO_SetPinValue (PORTC,Pin7,HIGH);
	DIO_SetPortDirection(PORTA,Output);
	DIO_SetPortValue (PORTA ,0b11111100);
}
void Seven_Segment_Write_Number(uint8 number)
{
	if(number < 10)
	{
		switch(number)
		{
                                        //  abcdefg
		case 0 : DIO_SetPortValue (PORTD ,0b11111100);break;
		case 1 : DIO_SetPortValue (PORTD ,0b10011111);break;
		case 2 : DIO_SetPortValue (PORTD ,0b11011010);break;
		case 3 : DIO_SetPortValue (PORTD ,0b11110010);break;
		case 4 : DIO_SetPortValue (PORTD ,0b00000000);break;
		case 5 : DIO_SetPortValue (PORTD ,0b00000000);break;
		case 6 : DIO_SetPortValue (PORTD ,0b00000000);break;
		case 7 : DIO_SetPortValue (PORTD ,0b00000000);break;
		case 8 : DIO_SetPortValue (PORTD ,0b00000000);break;
		case 9 : DIO_SetPortValue (PORTD ,0b00000000);break;

		}
	}
}

