/*
 * LED.c
 *
 *  Created on: Aug 27, 2020
 *      Author: mkabo
 */
#include<util/delay.h>
#include"../LIB/STD_types.h"
#include"../MCAL/DIO/DIO_types.h"
#include"../MCAL/DIO/DIO.h"
void LED(){

	DIO_SetPinDirection (PORTD,Pin6,Output);
	while(1){
	DIO_SetPinValue (PORTD,Pin6,LOW);
	_delay_ms(1000);
		DIO_SetPinValue (PORTD,Pin6,HIGH);
		_delay_ms(1000);

	}
}

