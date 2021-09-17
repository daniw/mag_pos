/*
 * spi.h
 *
 *  Created on: 31.03.2021
 *      Author: daniw
 */

#ifndef COMMON_SPI_H_
#define COMMON_SPI_H_

#include <msp430.h>
#include <stdint.h>
#include "platform.h"
#include "gpio.h"
#include "clock.h"

/* USCI module selection */
#ifndef SPI_MODULE
    #define SPI_MODULE          B0
#endif /* SPI_MODULE */

/* Baud rate selection */
#ifndef SPI_BAUD
    #define SPI_BAUD            (SMCLK_FREQ / 2)
#endif /* SPI_BAUD */
// Todo: Check if Baud rate compatible with input frequency

/* SPI configuration */
#ifndef SPI_CLK_SRC_SMCLK
    #define SPI_CLK_SRC_SMCLK   1
#endif /* SPI_CLK_SRC_SMCLK */
#ifndef SPI_CLK_SRC_ACLK
    #define SPI_CLK_SRC_ACLK    0
#endif /* SPI_CLK_SRC_ACLK */
#ifndef SPI_LEN
    #define SPI_LEN             8
#endif /* SPI_LEN */
#ifndef SPI_CLK_POLARITY
    #define SPI_CLK_POLARITY    1
#endif /* SPI_CLK_POLARITY */
#ifndef SPI_CLK_PHASE
    #define SPI_CLK_PHASE       0
#endif /* SPI_CLK_PHASE */
#ifndef SPI_MSB_FIRST
    #define SPI_MSB_FIRST       1
#endif /* SPI_MSB_FIRST */
#ifndef SPI_MASTER
    #define SPI_MASTER          1
#endif /* SPI_MASTER */
#ifndef SPI_CHIP_SELECT
    #define SPI_CHIP_SELECT     0
#endif /* SPI_CHIP_SELECT */
#ifndef SPI_CS_LOW_ACTIVE
    #define SPI_CS_LOW_ACTIVE   1
#endif /* SPI_CS_LOW_ACTIVE */
#ifndef SPI_MULTIMASTER
    #define SPI_MULTIMASTER     0
#endif /* SPI_MULTIMASTER */
#ifndef SPI_RX_INTERRUPT
    #define SPI_RX_INTERRUPT    1
#endif /* SPI_RX_INTERRUPT */
#ifndef SPI_TX_INTERRUPT
    #define SPI_TX_INTERRUPT    0
#endif /* SPI_TX_INTERRUPT */

/* SPI buffer */
#ifndef SPI_BUFFER_LEN
    #define SPI_BUFFER_LEN      16
#endif /* SPI_BUFFER_LEN */

/* Configuration validity check */
#if ((SPI_CLK_SRC_SMCLK + SPI_CLK_SRC_ACLK) > 1)
    #error "Multiple clock sources selected for SPI module"
#endif /* Multiple clock sources */
#if ((SPI_CLK_SRC_SMCLK + SPI_CLK_SRC_ACLK) < 1)
    #error "No clock source selected for SPI module"
#endif /* No clock sources */
#if (SPI_CHIP_SELECT && SPI_MULTIMASTER)
    #error "Hardware chip select and multimaster functionality not available simultaneous. "
#endif /* STE pin function */

/* USCI register redefinition */
/* CTLW0 */
#define SPI_CTLW0_(module)      SPI_CTLW0__(module)
#define SPI_CTLW0__(module)     UC##module##CTLW0
#define SPI_CTLW0               SPI_CTLW0_(SPI_MODULE)
/* CTL0 */
#define SPI_CTL0_(module)       SPI_CTL0__(module)
#define SPI_CTL0__(module)      UC##module##CTL0
#define SPI_CTL0                SPI_CTL0_(SPI_MODULE)
/* CTL1 */
#define SPI_CTL1_(module)       SPI_CTL1__(module)
#define SPI_CTL1__(module)      UC##module##CTL1
#define SPI_CTL1                SPI_CTL1_(SPI_MODULE)
/* BRW */
#define SPI_BRW_(module)        SPI_BRW__(module)
#define SPI_BRW__(module)       UC##module##BRW
#define SPI_BRW                 SPI_BRW_(SPI_MODULE)
/* BR0 */
#define SPI_BR0_(module)        SPI_BR0__(module)
#define SPI_BR0__(module)       UC##module##BR0
#define SPI_BR0                 SPI_BR0_(SPI_MODULE)
/* BR1 */
#define SPI_BR1_(module)        SPI_BR1__(module)
#define SPI_BR1__(module)       UC##module##BR1
#define SPI_BR1                 SPI_BR1_(SPI_MODULE)
/* STATW */
#define SPI_STATW_(module)      SPI_STATW__(module)
#define SPI_STATW__(module)     UC##module##STATW
#define SPI_STATW               SPI_STATW_(SPI_MODULE)
/* RXBUF */
#define SPI_RXBUF_(module)      SPI_RXBUF__(module)
#define SPI_RXBUF__(module)     UC##module##RXBUF
#define SPI_RXBUF               SPI_RXBUF_(SPI_MODULE)
/* TXBUF */
#define SPI_TXBUF_(module)      SPI_TXBUF__(module)
#define SPI_TXBUF__(module)     UC##module##TXBUF
#define SPI_TXBUF               SPI_TXBUF_(SPI_MODULE)
/* IE */
#define SPI_IE_(module)         SPI_IE__(module)
#define SPI_IE__(module)        UC##module##IE
#define SPI_IE                  SPI_IE_(SPI_MODULE)
/* IFG */
#define SPI_IFG_(module)        SPI_IFG__(module)
#define SPI_IFG__(module)       UC##module##IFG
#define SPI_IFG                 SPI_IFG_(SPI_MODULE)
/* IV */
#define SPI_IV_(module)         SPI_IV__(module)
#define SPI_IV__(module)        UC##module##IV
#define SPI_IV                  SPI_IV_(SPI_MODULE)
/* SPI_VECTOR */
#define SPI_VECTOR_(module)     SPI_VECTOR__(module)
#define SPI_VECTOR__(module)    USCI_##module##_VECTOR
#define SPI_VECTOR              SPI_VECTOR_(SPI_MODULE)

/* CTLW0 */
#if SPI_CLK_SRC_SMCLK
    #define SPI_UCSSEL_INIT     UCSSEL__SMCLK
#elif SPI_CLK_SRC_ACLK
    #define SPI_UCSSEL_INIT     UCSSEL__ACLK
#else
    #error "No clock source selected"
#endif
#if SPI_LEN == 7
    #define SPI_LEN_INIT        UC7BIT__7BIT
#elif SPI_LEN == 8
    #define SPI_LEN_INIT        UC7BIT__8BIT
#else
    #error "SPI data length out of range"
#endif
#if SPI_CHIP_SELECT
    #if SPI_CS_LOW_ACTIVE
        #define SPI_MODE_INIT       UCMODE_2
    #else
        #define SPI_MODE_INIT       UCMODE_1
    #endif
#else
    #define SPI_MODE_INIT       UCMODE_0
#endif
#define SPI_CTLW0_INIT  ((SPI_CLK_PHASE?UCCKPH:0) | \
                         (SPI_CLK_POLARITY?UCCKPL__HIGH:UCCKPL__LOW) | \
                         (SPI_MSB_FIRST?UCMSB:0) | \
                         (SPI_LEN_INIT) | \
                         (SPI_MASTER?UCMST__MASTER:UCMST__SLAVE) | \
                         (SPI_MODE_INIT) | \
                         (UCSYNC) | \
                         (SPI_UCSSEL_INIT) | \
                         (SPI_MULTIMASTER?UCSTEM_0:UCSTEM_1) | \
                         (UCSWRST))
/* Check setting of UCSYNC for SPI functionality */

/* BRW */
#if SPI_CLK_SRC_SMCLK
    #define SPI_INPUT_FREQ      SMCLK_FREQ
#elif SPI_CLK_SRC_ACLK
    #define SPI_INPUT_FREQ      ACLK_FREQ
#endif
#define SPI_BRW_INIT           (SPI_INPUT_FREQ / SPI_BAUD)
#if ((SPI_BAUD * SPI_BRW_INIT) != SPI_INPUT_FREQ)
    #error "SPI baud rate not achievable"
#endif

/* STATW */
#define SPI_STATW_INIT  ((UCLISTEN_0) | \
                         (UCFE_0) | \
                         (UCOE_0))

/* IE */
#define SPI_IE_INIT     ((SPI_RX_INTERRUPT?UCRXIE:0) | \
                         (SPI_TX_INTERRUPT?UCTXIE:0))

void init_spi(void);
void spi_disable(void);
void spi_enable(void);
uint8_t spi_write(uint8_t *data, uint8_t len);
uint8_t spi_read(uint8_t *data, uint8_t len);
void spi_tx_isr(void);
void spi_rx_isr(void);

#endif /* COMMON_SPI_H_ */
