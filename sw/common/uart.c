/*
 * uart.c
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#include "uart.h"

const char string[] = { "Hello World\r\n" };
uint8_t i; //Counter

void init_uart(void){
    UART_CTL1  = UCSWRST; // Reset USCI module

    #if CTL0_INIT != 0
        UART_CTL0 = UART_CTL0_INIT;
    #endif /* UART_CTL0 */
    #if UART_CTL1_INIT != 0
        UART_CTL1 |= UART_CTL1_INIT; // |= to keep UCSWRST set and keep USCI module in reset
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

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
   if (UCA0RXBUF == 'h') // 'h' received?
   {
      i = 0;
      UC0IE |= UCA0TXIE; // Enable USCI_A0 TX interrupt
      UCA0TXBUF = string[i++];
   }
   else if (UCA0RXBUF == 'r') // 'r' received?
   {
       LED_RED_TOGGLE();
   }
   else if (UCA0RXBUF == 'g') // 'g' received?
   {
       LED_GREEN_TOGGLE();
   }
   else if (UCA0RXBUF == 'b') // 'b' received?
   {
       LED_BLUE_TOGGLE();
   }
   else if (UCA0RXBUF == 'y') // 'y' received?
   {
       LED_YELLOW_TOGGLE();
   }
   else if (UCA0RXBUF == 'w') // 'w' received?
   {
       LED_WHITE_TOGGLE();
   }
   else if (UCA0RXBUF == 'd') // 'd' received?
   {
       led_off();
   }
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{
   UCA0TXBUF = string[i++]; // TX next character
   if (i == sizeof string - 1) // TX over?
      UC0IE &= ~UCA0TXIE; // Disable USCI_A0 TX interrupt
}
