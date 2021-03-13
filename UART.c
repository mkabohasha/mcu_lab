/*
 * UART.c
 *
 *  Created on: Sep 29, 2020
 *      Author: mkabo
 */
#include<util/delay.h>
#include"../LIB/STD_types.h"
#include"../LIB/Bit_Math.h"
#include"../MCAL/DIO/DIO_types.h"
#include"../MCAL/DIO/DIO.h"
#include"../MCAL/DIO/DIO_UART_REG.h"
#include"../MCAL/DIO/DIO_UART_PIN.h"
#include"../HAL/LCD/LCD.h"
#include"UART.h"
void uart_init(void)
{
	//8000000/16/9600-1
  uint16  baud = 50 ;
	UBRRL = (uint8)(baud); // assgin low 8 bits
	UBRRH = (uint8)(baud>>8); // assgin high 8 bits
	//UBRRL = 0x33;
	USCRB |= ((1<<4)|(1<<3)); //enable TXEN & RXEN
	USCRC |= ((1<<2)|(1<<1)) ; //8-bit mode | no parity | asynchronuce mode


}

void uart_send(uint8 ch)
{
			while(!(UCSRA &(1<<5)))
			{
				UDR = ch;
				_delay_ms(500);
			}

}

uint8 uart_read()
{
	while(!(UCSRA &(1<<7)))//wait until recieve RXCN
				{
					return UDR;
				}
	return UDR;
}

