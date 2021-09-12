/*
 * isr.c
 *
 *  Created on: 25.07.2020
 *      Author: daniw
 */

#include "isr.h"

#ifdef __MSP430FR2355__
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
    #pragma vector=USCI_A1_VECTOR
    __interrupt void USCI_A1_ISR(void)
#elif defined(__GNUC__)
    void __attribute__ ((interrupt(USCI_A1_VECTOR))) USCI_A1_ISR(void)
#else
    #error "Compiler not supported!"
#endif
{
    switch(__even_in_range(UART_IV, USCI_UART_UCTXCPTIFG)) {
        case USCI_NONE: // No interrupts
        break;
        case USCI_UART_UCRXIFG:
            #if PL_HAS_UART
                uart_rx_isr();
            #endif /* PL_HAS_UART */
        break;
        case USCI_UART_UCTXIFG:
            #if PL_HAS_UART
                uart_tx_isr();
            #endif /* PL_HAS_UART */
        break;
        case USCI_UART_UCSTTIFG:
        break;
        case USCI_UART_UCTXCPTIFG:
        break;
        default: break;
    }
}

#if PL_HAS_SPI
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
    #pragma vector=SPI_VECTOR
    __interrupt void SPI_ISR(void)
#elif defined(__GNUC__)
    void __attribute__ ((interrupt(SPI_VECTOR))) SPI_ISR(void)
#else
    #error "Compiler not supported!"
#endif
{
    switch(__even_in_range(SPI_IV, USCI_SPI_UCTXIFG)) {
        case USCI_NONE:
            break;
        case USCI_SPI_UCRXIFG:
            spi_rx_isr();
            break;
        case USCI_SPI_UCTXIFG:
            spi_tx_isr();
            break;
        default: break;
    }
}
#endif /* PL_HAS_UART */

#elif __MSP430G2553__
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
    #pragma vector=USCIAB0TX_VECTOR
    __interrupt void USCI0TX_ISR(void)
#elif defined(__GNUC__)
    void __attribute__ ((interrupt(USCIAB0TX_VECTOR))) USCI0TX_ISR(void)
#else
    #error "Compiler not supported!"
#endif
{
    #if PL_HAS_UART
        if (UART_IFG & UART_TXIFG) {
            uart_tx_isr();
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
#endif /* Microcontroller */
