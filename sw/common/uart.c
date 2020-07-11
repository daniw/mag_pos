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
    UCA0CTL1 |= UCSSEL_2; // SMCLK
    UCA0BR0 = 0x08; // 1MHz 115200
    UCA0BR1 = 0x00; // 1MHz 115200
    UCA0MCTL = UCBRS2 + UCBRS0; // Modulation UCBRSx = 5
    UCA0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**
    UC0IE |= UCA0RXIE; // Enable USCI_A0 RX interrupt
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
   if (UCA0RXBUF == 'a') // 'u' received?
   {
      i = 0;
      UC0IE |= UCA0TXIE; // Enable USCI_A0 TX interrupt
      UCA0TXBUF = string[i++];
   }
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{
   UCA0TXBUF = string[i++]; // TX next character
   if (i == sizeof string - 1) // TX over?
      UC0IE &= ~UCA0TXIE; // Disable USCI_A0 TX interrupt
}
