/*
 * uart.h
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#ifndef UART_H_
#define UART_H_

#include <msp430.h>
#include "clock.h"
#include "gpio.h"

/* USCI module selection */
#if PL_IS_DEMO
    #define UART_MODULE 0
#endif /* PL_IS_DEMO */

/* Baud rate selection */
#ifndef UART_BAUD
    #define UART_BAUD 115200
#endif

/* USCI register redefinition */
/* CTL0 */
#define UART_CTL0(module) UART_CTL0_(module)
#define UART_CTL0_(module) UCA##module##CTL0
/* CTL1 */
#define UART_CTL1(module) UART_CTL1_(module)
#define UART_CTL1_(module) UCA##module##CTL1
/* BR0 */
#define UART_BR0(module) UART_BR0_(module)
#define UART_BR0_(module) UCA##module##BR0
/* BR1 */
#define UART_BR1(module) UART_BR1_(module)
#define UART_BR1_(module) UCA##module##BR1
/* MCTL */
#define UART_MCTL(module) UART_MCTL_(module)
#define UART_MCTL_(module) UCA##module##MCTL
/* IE */
#define UART_IE(module) UART_IE_(module)
#define UART_IE_(module) UC##module##IE
/* RXIE */
#define UART_RXIE(module) UART_RXIE_(module)
#define UART_RXIE_(module) UCA##module##RXIE

/* baud rate clock generation */
#define UART_UCA_CTL1_INIT UCSSEL_2 /* Use SMCLK */
#define UART_INPUT_FREQ SMCLK_FREQ
/* UCBR_INIT = floor(Input freq / Baud) */
#define UART_UCA_BR0_INIT  ((UART_INPUT_FREQ / UART_BAUD) % 256)
#define UART_UCA_BR1_INIT  ((UART_INPUT_FREQ / UART_BAUD) / 256)
/* UCBRS_VALUE = mod(round(Input freq * 8 / Baud), 8) */
#define UART_UCBRS_VALUE (((UART_INPUT_FREQ * 8 + (UART_BAUD/2)) / UART_BAUD) % 8)
#if UART_UCBRS_VALUE == 0
    #define UART_UCBRS_INIT UCBRS_0
#elif UART_UCBRS_VALUE == 1
    #define UART_UCBRS_INIT UCBRS_1
#elif UART_UCBRS_VALUE == 2
    #define UART_UCBRS_INIT UCBRS_2
#elif UART_UCBRS_VALUE == 3
    #define UART_UCBRS_INIT UCBRS_3
#elif UART_UCBRS_VALUE == 4
    #define UART_UCBRS_INIT UCBRS_4
#elif UART_UCBRS_VALUE == 5
    #define UART_UCBRS_INIT UCBRS_5
#elif UART_UCBRS_VALUE == 6
    #define UART_UCBRS_INIT UCBRS_6
#elif UART_UCBRS_VALUE == 7
    #define UART_UCBRS_INIT UCBRS_7
#else
    #error "Error occured during Baud rate setup, check baud rate and input clock"
#endif
#define UART_UCA_MCTL_INIT (UART_UCBRS_INIT)

void init_uart(void);

#endif /* UART_H_ */
