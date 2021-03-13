/*
 * lcd_app.c
 *
 *  Created on: Sep 20, 2020
 *      Author: mkabo
 */
#include<util/delay.h>
#include"../LIB/STD_types.h"
#include"../LIB/Bit_Math.h"
#include"../MCAL/DIO/DIO_types.h"
#include"../MCAL/DIO/DIO.h"
#include"../HAL/LCD/LCD.h"

void lcd_app(void)
{
		LCD_Init();

		LCD_WriteData(' ');
		LCD_WriteData(' ');
	LCD_WriteData('E');
	LCD_WriteData('n');
	LCD_WriteData('g');
	LCD_WriteData(126);
	LCD_WriteData('M');
	LCD_WriteData('o');

}

