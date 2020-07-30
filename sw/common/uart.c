/*
 * uart.c
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#include "uart.h"

void init_uart(void){
    UART_CTL1  = UCSWRST; // Reset USCI module

    #if CTL0_INIT != 0
        UART_CTL0 = UART_CTL0_INIT;
    #endif /* UART_CTL0 */
    #if UART_CTL1_INIT != 0
        UART_CTL1 = UART_CTL1_INIT | UCSWRST; // keep UCSWRST set to keep USCI module in reset
    #endif /* UART_CTL1 */
    #if UART_BR0_INIT != 0
        UART_BR0 = UART_BR0_INIT;
    #endif /* UART_BR0 */
    #if UART_BR1_INIT != 0
        UART_BR1 = UART_BR1_INIT;
    #endif /* UART_BR1 */
    #if UART_MCTL_INIT != 0
        UART_MCTL = UART_MCTL_INIT;
    #endif /* UART_MCTL */
    #if STAT_INIT != 0
        UART_STAT = UART_STAT_INIT;
    #endif /* UART_STAT */
    #if ABCTL_INIT != 0
        UART_ABCTL = UART_ABCTL_INIT;
    #endif /* AUART_BCTL */
    #if IRTCTL_INIT != 0
        UART_IRTCTL = UART_IRTCTL_INIT;
    #endif /* IRUART_TCTL */
    #if IRRCTL_INIT != 0
        UART_IRRCTL = UART_IRRCTL_INIT;
    #endif /* IRUART_RCTL */

    UART_CTL1 &= ~UCSWRST; // **Initialize USCI state machine**
    UART_IE   |= UART_RXIE; // Enable UART RX interrupt
}
