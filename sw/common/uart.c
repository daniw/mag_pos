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
    UART_CTL1 |= UART_UCA_CTL1_INIT;
    UART_BR0   = UART_UCA_BR0_INIT;
    UART_BR1   = UART_UCA_BR1_INIT;
    UART_MCTL  = UART_UCA_MCTL_INIT;
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
