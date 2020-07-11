/*
 * uart.h
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#ifndef COMMON_UART_H_
#define COMMON_UART_H_

#include <msp430.h>

void init_uart(void);

__interrupt void USCI0RX_ISR(void);

__interrupt void USCI0TX_ISR(void);

#endif /* COMMON_UART_H_ */
