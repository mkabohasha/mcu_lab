/*
 * PUSH_BUTTON.c
 *
 *  Created on: Sep 4, 2020
 *      Author: mkabo
 */
#include"../LIB/STD_types.h"
#include"../MCAL/DIO/DIO_types.h"
#include"../MCAL/DIO/DIO.h"

void PUSH_BUTTON()
{
	DIO_SetPinDirection (PORTD,Pin2,Input);
	// output led bd3
	DIO_SetPinDirection (PORTD,Pin3,Output);
while(1){
	if(GetPinValue (PORTD,Pin2) == HIGH)
		{
				DIO_SetPinValue (PORTD,Pin3,HIGH);
		}
	else if (GetPinValue (PORTD,Pin2) == LOW)
	{
		DIO_SetPinValue (PORTD,Pin3,LOW);

	}
}

}


