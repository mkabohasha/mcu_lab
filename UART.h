/*
 * UART.h
 *
 *  Created on: Sep 29, 2020
 *      Author: mkabo
 */

#ifndef REPO_APP_UART_H_
#define REPO_APP_UART_H_


void uart_init(void);
void uart_send(uint8 ch);
uint8 uart_read();


#endif /* REPO_APP_UART_H_ */
