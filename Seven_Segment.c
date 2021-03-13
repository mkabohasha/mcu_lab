/*
 * Seven_Segment.c
 *
 *  Created on: Sep 6, 2020
 *      Author: mkabo
 */
#include"../LIB/STD_types.h"
#include"../MCAL/DIO/DIO_types.h"
#include"../MCAL/DIO/DIO.h"
#include <util/delay.h>
void Seven_Segment()
{
	//Seven_Segment_Intlisation();
//	Seven_Segment_Write_Number(1);
	DIO_SetPinDirection (PORTC,Pin7,Output);
		DIO_SetPinValue (PORTC,Pin7,HIGH);
		DIO_SetPortDirection(PORTA,Output);
		while(1)
		{
			DIO_SetPortValue (PORTA ,0b00000011); // 0
			_delay_ms(5000);
			DIO_SetPortValue (PORTA ,0b10011111); //1
			_delay_ms(5000);
			DIO_SetPortValue (PORTA ,0b00100101); // Number 2
		    _delay_ms(5000);
		    DIO_SetPortValue (PORTA ,0b00001101); //Number 3
		    _delay_ms(5000);
			DIO_SetPortValue (PORTA ,0b10011001); // Number 4
			_delay_ms(5000);
		}

}

