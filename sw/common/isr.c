/*
 * isr.c
 *
 *  Created on: 25.07.2020
 *      Author: daniw
 */

#include "isr.h"

//const char string[] = { "Hello World\r\n" };
//uint8_t i; //Counter

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    LED_BLUE_TOGGLE();
    switch(__even_in_range(UART_IV,18)) {
        case 0x00: // Vector 0: No interrupts
        break;
        case 0x02: // Vector 2: UCRXIFG
            #if PL_HAS_UART
                uart_rx_isr(); //UART_RX_ISR
            #endif /* PL_HAS_UART */
        break;
        case 0x04: // Vector 4: UCTXIFG
            #if PL_HAS_UART
                LED_RED_TOGGLE();
                uart_tx_isr(); //UART_TX_ISR
            #endif /* PL_HAS_UART */
        break;
        case 0x06: // Vector 6: UCSTTIFG
        break;
        case 0x08: // Vector 8: UCTXCPTIFG
        break;
        default: break;
    }
}
/*
#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{
    #if PL_HAS_UART
        if (UART_IFG & UART_TXIFG) {
            uart_tx_isr();
            //UART_TX_ISR
        }
    #endif

    #if PL_HAS_I2C
        if (IFG2 & UCB0RXIFG) {
            mlx90393_i2c_rx_interrupt();
        }
        if (IFG2 & UCB0TXIFG) {
            mlx90393_i2c_tx_interrupt();
        }
    #endif

}
*/
