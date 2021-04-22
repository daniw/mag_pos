/*
 * uart.c
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#include "uart.h"

#if PL_HAS_UART

uint8_t *uart_tx_buffer_;
uint8_t uart_tx_count;
uint8_t uart_tx_i;
uint8_t uart_rx_expected = 1;
uint8_t uart_rx_i = 0;

uint8_t mlx_cmd[10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t mlx_data[sizeof(mlx_cmd)];
uint8_t mlx_spi_retval;

void init_uart(void){
#ifdef __MSP430FR2355__
    UART_CTLW0 |= UCSWRST; // Reset USCI module

    UART_CTLW0 = UART_CTLW0_INIT | UCSWRST; // keep UCSWRST set to keep USCI module in reset;
    UART_CTLW1 = UART_CTLW1_INIT;
    UART_BRW = UART_BRW_INIT;
    UART_MCTLW = UART_MCTLW_INIT;
    UART_STATW = UART_STATW_INIT;
    UART_ABCTL = UART_ABCTL_INIT;
    UART_IRTCTL = UART_IRTCTL_INIT;
    UART_IRRCTL = UART_IRRCTL_INIT;

    UART_CTLW0 &= ~UCSWRST; // **Initialize USCI state machine**
    UART_IE |= UART_RXIE; // Enable UART RX interrupt
#elif __MSP430G2553__
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
#endif /* Microcontroller */
}

void uart_transmit(uint8_t *data, uint8_t count)
{
    uart_tx_i = 0;
    uart_tx_buffer_ = data;
    uart_tx_count = count;

    UART_IE |= UART_TXIE;
    UART_TXBUF = uart_tx_buffer_[uart_tx_i++];
}

void uart_rx_isr()
{
    uint8_t data = UART_RXBUF;
    LED_GREEN_TOGGLE();
    uint8_t rx_bytes;
    if (uart_rx_expected <= 1)
    {
        mlx_cmd[0] = data;

        switch (data >> 4) {
        case 0b0000:
        case 0b0001:
        case 0b0010:
        case 0b0011:
        case 0b1000:
        case 0b1111:
        case 0b1101:
        case 0b1110:
            spi_write(mlx_cmd, 1);
            LED_BLUE_TOGGLE();
            do {
                mlx_spi_retval = spi_read(mlx_data, 1);
            } while (mlx_spi_retval);
            uart_transmit(mlx_data, 1);
            break;
        case 0b0100:
            rx_bytes = 1 + ((((data>>0) & 0x01) + ((data>>1) & 0x01) + ((data>>2) & 0x01) + ((data>>3) & 0x01))<<1);
            spi_write(mlx_cmd, rx_bytes);
            do {
                mlx_spi_retval = spi_read(mlx_data, rx_bytes);
            } while (mlx_spi_retval);
            uart_transmit(mlx_data, rx_bytes);
            break;
        case 0b0101:
            uart_rx_expected = 2;
            uart_rx_i = 1;
            break;
        case 0b0110:
            uart_rx_expected = 4;
            uart_rx_i = 1;
            break;
        default:
            break;
        }
    }
    else
    {
        mlx_cmd[uart_rx_i++] = data;
        if (uart_rx_i >= uart_rx_expected)
        {
            rx_bytes = (uart_rx_expected == 2) ? 3 : 1;
            spi_write(mlx_cmd, rx_bytes);
            do {
                mlx_spi_retval = spi_read(mlx_data, rx_bytes);
            } while (mlx_spi_retval);
            uart_transmit(mlx_data, rx_bytes);
            uart_rx_i = 0;
            uart_rx_expected = 1;
            mlx_cmd[1] = 0x00; mlx_cmd[2] = 0x00; mlx_cmd[3] = 0x00; mlx_cmd[4] = 0x00;
        }
    }
}

void uart_tx_isr()
{
    if (uart_tx_i >= uart_tx_count)
        UART_IE &= ~UART_TXIE;
    else
        UART_TXBUF = uart_tx_buffer_[uart_tx_i++];
}
#endif /* PL_HAS_UART */
