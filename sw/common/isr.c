/*
 * isr.c
 *
 *  Created on: 25.07.2020
 *      Author: daniw
 */

#include "isr.h"

const char string[] = { "Hello World\r\n" };
uint8_t i; //Counter

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
    #if PL_HAS_UART
        if (UART_IFG & UART_RXIFG) {
            UART_RX_ISR
        }
    #endif /* PL_HAS_UART */
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{
    #if PL_HAS_UART
        if (UART_IFG & UART_TXIFG) {
            UART_TX_ISR
        }
    #endif /* PL_HAS_UART */
}
