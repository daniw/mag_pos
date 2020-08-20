/*
 * isr.c
 *
 *  Created on: 25.07.2020
 *      Author: daniw
 */

#include "isr.h"

//const char string[] = { "Hello World\r\n" };
//uint8_t i; //Counter

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
    #if PL_HAS_UART
        if (UART_IFG & UART_RXIFG) {
            uart_rx_isr();
            //UART_RX_ISR
        }
    #endif /* PL_HAS_UART */
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{
    #if PL_HAS_UART
        if (UART_IFG & UART_TXIFG) {
            uart_tx_isr();
            //UART_TX_ISR
        }
    #endif /* PL_HAS_UART */

    #if PL_HAS_I2C
        if (IFG2 & UCB0RXIFG) {
            mlx90393_i2c_rx_interrupt();
        }
        if (IFG2 & UCB0TXIFG) {
            mlx90393_i2c_tx_interrupt();
        }
    #endif /* PL_HAS_I2C */

}
