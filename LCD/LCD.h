/*
 * LCD.H
 *
 *  Created on: Sep 10, 2020
 *      Author: mkabo
 */

#ifndef REPO_HAL_LCD_LCD_H_
#define REPO_HAL_LCD_LCD_H_

void LCD_Init();
void LCD_WriteCMD(uint8 cmd);
void LCD_WriteData(uint8 data);
void LCD_Writestring(uint8* str);
void LCD_GoToPos(uint8 row,uint8 colm);

#endif /* REPO_HAL_LCD_LCD_H_ */
