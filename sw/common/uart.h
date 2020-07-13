/*
 * uart.h
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#ifndef COMMON_UART_H_
#define COMMON_UART_H_

#include <msp430.h>
#include "clock.h"
#include "gpio.h"

/* Baud rate selection */
#ifndef UART_BAUD
    #define UART_BAUD 115200
#endif

#define UCA0CTL1_INIT UCSSEL_2 /* Use SMCLK */
#define UART_INPUT_FREQ SMCLK_FREQ
#define UCA0BR0_INIT  ((UART_INPUT_FREQ / UART_BAUD) % 256)
#define UCA0BR1_INIT  ((UART_INPUT_FREQ / UART_BAUD) / 256)
#define UCBRS_VALUE ((UART_INPUT_FREQ * 8 / UART_BAUD) % 8)
#if UCBRS_VALUE == 0
    #define UCBRS_INIT UCBRS_0
#elif UCBRS_VALUE == 1
    #define UCBRS_INIT UCBRS_1
#elif UCBRS_VALUE == 2
    #define UCBRS_INIT UCBRS_2
#elif UCBRS_VALUE == 3
    #define UCBRS_INIT UCBRS_3
#elif UCBRS_VALUE == 4
    #define UCBRS_INIT UCBRS_4
#elif UCBRS_VALUE == 5
    #define UCBRS_INIT UCBRS_5
#elif UCBRS_VALUE == 6
    #define UCBRS_INIT UCBRS_6
#elif UCBRS_VALUE == 7
    #define UCBRS_INIT UCBRS_7
#else
    #error "Error occured during Baud rate setup, check baud rate and input clock"
#endif
#define UCA0MCTL_INIT (UCBRS_INIT)

void init_uart(void);

#endif /* COMMON_UART_H_ */
