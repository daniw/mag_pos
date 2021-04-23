/*
 * spi.c
 *
 *  Created on: 31.03.2021
 *      Author: daniw
 */

#include "spi.h"

#if PL_HAS_SPI

/* Variables */
static uint8_t spi_tx_buffer[SPI_BUFFER_LEN];
static uint8_t spi_tx_buf_idx = 0;
static uint8_t spi_tx_buf_len = 0;
static uint8_t spi_rx_buffer[SPI_BUFFER_LEN];
static uint8_t spi_rx_buf_idx = 0;
static uint8_t spi_comm_act = 0;

/* Functions */
void init_spi(void){
    /*
     * The recommended eUSCI initialization or reconfiguration process is:
     * 1. Set UCSWRST.
     *    BIS.B #UCSWRST,&UCxCTL1
     * 2. Initialize all eUSCI registers while UCSWRST = 1 (including UCxCTL1).
     * 3. Configure ports.
     * 4. Clear UCSWRST in software.
     *    BIC.B #UCSWRST,&UCxCTL1
     * 5. Enable interrupts (optional) by setting UCRXIE or UCTXIE.
     */
    /* Reset SPI module */
    SPI_CTLW0 |= UCSWRST;
    /* Initialize registers */
    #if SPI_CTLW0_INIT != 0
        SPI_CTLW0 = SPI_CTLW0_INIT;
    #endif
    #if SPI_BRW_INIT != 0
        SPI_BRW = SPI_BRW_INIT;
    #endif
    #if SPI_STATW_INIT != 0
        SPI_STATW = SPI_STATW_INIT;
    #endif
    /* Configure ports */
    #if SPI_CHIP_SELECT
        SPI_SEL0 |= (MASK_SPI_CS | MASK_SPI_SCLK | MASK_SPI_MOSI | MASK_SPI_MISO);
        SPI_SEL1 &= ~(MASK_SPI_CS | MASK_SPI_SCLK | MASK_SPI_MOSI | MASK_SPI_MISO);
    #else
        SPI_SEL0 |= (MASK_SPI_SCLK | MASK_SPI_MOSI | MASK_SPI_MISO);
        SPI_SEL1 &= ~(MASK_SPI_SCLK | MASK_SPI_MOSI | MASK_SPI_MISO);
        SPI_CS_PORT |= MASK_SPI_CS;
        SPI_CS_DIR  |= MASK_SPI_CS;
    #endif /* SPI_CHIP_SELECT */
    /* Release SPI module for normal operation */
    SPI_CTLW0 &= ~UCSWRST;
    /* Enable interrupts */
    SPI_IE = SPI_IE_INIT;
    return;
}

uint8_t spi_write(uint8_t *data, uint8_t len){
    uint8_t retval = 0;
    if (spi_comm_act == 0) {
        if (len <= SPI_BUFFER_LEN) {
            spi_tx_buf_len = len;
            spi_tx_buf_idx = 0;
            spi_rx_buf_idx = 0;
            uint8_t i;
            for (i = 0; i < len; i++){
                spi_tx_buffer[i] = *(data++);
            }
            spi_comm_act = 1;
            SPI_CS_PORT &= ~MASK_SPI_CS;
            SPI_TXBUF = spi_tx_buffer[spi_tx_buf_idx++];
            SPI_IE |= UCTXIE;
        }
        else {
            retval = 2;
        }
    }
    else {
        retval = 1;
    }
    return retval;
}

uint8_t spi_read(uint8_t *data, uint8_t len){
    uint8_t retval = 0;
    if (spi_comm_act == 0){
        if (len <= SPI_BUFFER_LEN){
            uint8_t i;
            for (i = 0; i < len; i++){
                *(data++) = spi_rx_buffer[i];
            }
        }
        else {
            retval = 2;
        }
    }
    else {
        retval = 1;
    }
    return retval;
}

void spi_tx_isr(void){
    if (spi_tx_buf_idx < spi_tx_buf_len) { // Data remaining in buffer?
        SPI_TXBUF = spi_tx_buffer[spi_tx_buf_idx++];
    }
    else {
        SPI_IE &= ~UCTXIE;
    }
    return;
}

void spi_rx_isr(void){
    if (spi_rx_buf_idx < SPI_BUFFER_LEN) {
        spi_rx_buffer[spi_rx_buf_idx++] = SPI_RXBUF;
    }
    else {
        SPI_IFG &= ~UCRXIFG;
    }
    if (spi_tx_buf_idx >= spi_tx_buf_len) {
        SPI_CS_PORT |= MASK_SPI_CS;
        spi_comm_act = 0;
    }
    return;
}

#endif /* PL_HAS_SPI */
