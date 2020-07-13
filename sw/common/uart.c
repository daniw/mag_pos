/*
 * uart.c
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#include "uart.h"

const char string[] = { "Hello World\r\n" };
unsigned int i; //Counter

void init_uart(void){
    UCA0CTL1 |= UCA0CTL1_INIT;
    UCA0BR0 = UCA0BR0_INIT;
    UCA0BR1 = UCA0BR1_INIT;
    UCA0MCTL = UCA0MCTL_INIT;
    UCA0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**
    UC0IE |= UCA0RXIE; // Enable USCI_A0 RX interrupt
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
