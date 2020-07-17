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
#define UART_CTL0_(module)  UART_CTL0__(module)
#define UART_CTL0__(module) UCA##module##CTL0
#define UART_CTL0           UART_CTL0_(UART_MODULE)
/* CTL1 */
#define UART_CTL1_(module)  UART_CTL1__(module)
#define UART_CTL1__(module) UCA##module##CTL1
#define UART_CTL1           UART_CTL1_(UART_MODULE)
/* BR0 */
#define UART_BR0_(module)  UART_BR0__(module)
#define UART_BR0__(module) UCA##module##BR0
#define UART_BR0           UART_BR0_(UART_MODULE)
/* BR1 */
#define UART_BR1_(module)  UART_BR1__(module)
#define UART_BR1__(module) UCA##module##BR1
#define UART_BR1           UART_BR1_(UART_MODULE)
/* MCTL */
#define UART_MCTL_(module)  UART_MCTL__(module)
#define UART_MCTL__(module) UCA##module##MCTL
#define UART_MCTL           UART_MCTL_(UART_MODULE)
/* IE */
#define UART_IE_(module)  UART_IE__(module)
#define UART_IE__(module) UC##module##IE
#define UART_IE           UART_IE_(UART_MODULE)
/* RXIE */
#define UART_RXIE_(module)  UART_RXIE__(module)
#define UART_RXIE__(module) UCA##module##RXIE
#define UART_RXIE           UART_RXIE_(UART_MODULE)

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
