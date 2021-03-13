/*
 * UART_APP.c
 *
 *  Created on: Oct 1, 2020
 *      Author: mkabo
 */
#include<util/delay.h>
#include"../LIB/STD_types.h"
#include"../LIB/Bit_Math.h"
#include"../MCAL/DIO/DIO_types.h"
#include"../MCAL/DIO/DIO.h"
#include"../MCAL/DIO/DIO_UART_REG.h"
#include"../MCAL/DIO/DIO_UART_PIN.h"
#include"UART.h"
void UART_APP(void)
{
	char x;
	DIO_SetPinDirection (PORTA,Pin0,Output);
	DIO_SetPinValue (PORTA, Pin0 ,LOW);
	uart_init();
	while(1)
	{
		x = uart_read();
		if (x == '0')
		{
			DIO_SetPinValue (PORTA, Pin0 ,HIGH);
		}
		if (x == '1')
				{
					DIO_SetPinValue (PORTA, Pin0 ,LOW);
					uart_send('a');
				}
	}

}
