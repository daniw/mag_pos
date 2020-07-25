/*
 * uart.h
 *
 *  Created on: 11.07.2020
 *      Author: daniw
 */

#ifndef UART_H_
#define UART_H_

#include <msp430.h>
#include <stdint.h>
#include "platform.h"
#include "clock.h"
#include "gpio.h"

/* USCI module selection */
#if PL_IS_DEMO
    #define UART_MODULE A0
#endif /* PL_IS_DEMO */

/* Baud rate selection */
#ifndef UART_BAUD
    #define UART_BAUD 115200
#endif

/* UART configuration */
#ifndef UART_PARITY
    #define UART_PARITY         0   // Parity check enabled?
#endif /* UART_PARITY */
#ifndef UART_PARITY_EVEN
    #define UART_PARITY_EVEN    0   // Even (1) or odd (0) parity?
#endif /* UART_PARITY_EVEN */
#ifndef UART_MSB_FIRST
    #define UART_MSB_FIRST      0   // MSB first (1) or LSB first (0)?
#endif /* UART_MSB_FIRST */
#ifndef UART_CHAR_LEN
    #define UART_CHAR_LEN       8   // Charachter length
#endif /* UART_CHAR_LEN */
#ifndef UART_STOP_LEN
    #define UART_STOP_LEN       1   // Number of stop bits
#endif /* UART_STOP_LEN */
#ifndef UART_LOOPBACK
    #define UART_LOOPBACK       0   // TXD is internally fed back to the receiver
#endif /* UART_LOOPBACK */
#ifndef UART_AUTOBAUD
    #define UART_AUTOBAUD       0   // Automatic baud rate detection
#endif /* UART_AUTOBAUD */
#if UART_AUTOBAUD
    #ifndef UART_AUTOBAUD_BREAK_TIMEOUT
        #define UART_AUTOBAUD_BREAK_TIMEOUT     0   // Break field time out error
    #endif /* UART_AUTOBAUD_BREAK_TIMEOUT */
    #ifndef UART_AUTOBAUD_SYNC_TIMEOUT
        #define UART_AUTOBAUD_SYNC_TIMEOUT      0   // Synch field time out error
    #endif /* UART_AUTOBAUD_SYNC_TIMEOUT */
    #ifndef UART_AUTOBAUD_LEN
        #define UART_AUTOBAUD_LEN               1   // Break/Synch delimiter length
    #endif /* UART_AUTOBAUD_LEN */
#endif /* UART_AUTOBAUD */
#ifndef UART_IRDA
    #define UART_IRDA           1   // Use IrDA pulses for UART communication
#endif /* UART_IRDA */
#if UART_IRDA
    #define UART_IRDA_TX_PULSE_3_16     0   // Use a pulse width of 3/16 bit period as defined by the IrDA standard
    #define UART_IRDA_TX_PULSE_NS       1628LL  // Pulse length in ns
    #define UART_NS_PER_SECOND          1000000000LL // Number of nanoseconds in a second
    #define UART_IRDA_RX_POL_INV        1       // Low pulses are detected
    #define UART_IRDA_RX_FILTER_EN      0       // Use digital filter for RX signal
    #define UART_IRDA_RX_FILTER_NS      814LL   // Minimum pulse width in ns for digital filter, ignoring wakeup time
#endif /* UART_IRDA */

/* USCI register redefinition */
/* CTL0 */
#define UART_CTL0_(module)    UART_CTL0__(module)
#define UART_CTL0__(module)   UC##module##CTL0
#define UART_CTL0             UART_CTL0_(UART_MODULE)
/* CTL1 */
#define UART_CTL1_(module)    UART_CTL1__(module)
#define UART_CTL1__(module)   UC##module##CTL1
#define UART_CTL1             UART_CTL1_(UART_MODULE)
/* BR0 */
#define UART_BR0_(module)     UART_BR0__(module)
#define UART_BR0__(module)    UC##module##BR0
#define UART_BR0              UART_BR0_(UART_MODULE)
/* BR1 */
#define UART_BR1_(module)     UART_BR1__(module)
#define UART_BR1__(module)    UC##module##BR1
#define UART_BR1              UART_BR1_(UART_MODULE)
/* MCTL */
#define UART_MCTL_(module)    UART_MCTL__(module)
#define UART_MCTL__(module)   UC##module##MCTL
#define UART_MCTL             UART_MCTL_(UART_MODULE)
/* STAT */
#define UART_STAT_(module)    UART_STAT__(module)
#define UART_STAT__(module)   UC##module##STAT
#define UART_STAT             UART_STAT_(UART_MODULE)
/* RXBUF */
#define UART_RXBUF_(module)   UART_RXBUF__(module)
#define UART_RXBUF__(module)  UC##module##RXBUF
#define UART_RXBUF            UART_RXBUF_(UART_MODULE)
/* TXBUF */
#define UART_TXBUF_(module)   UART_TXBUF__(module)
#define UART_TXBUF__(module)  UC##module##TXBUF
#define UART_TXBUF            UART_TXBUF_(UART_MODULE)
/* ABCTL */
#define UART_ABCTL_(module)   UART_ABCTL__(module)
#define UART_ABCTL__(module)  UC##module##ABCTL
#define UART_ABCTL            UART_ABCTL_(UART_MODULE)
/* IRTCTL */
#define UART_IRTCTL_(module)  UART_IRTCTL__(module)
#define UART_IRTCTL__(module) UC##module##IRTCTL
#define UART_IRTCTL           UART_IRTCTL_(UART_MODULE)
/* IRRCTL */
#define UART_IRRCTL_(module)  UART_IRRCTL__(module)
#define UART_IRRCTL__(module) UC##module##IRRCTL
#define UART_IRRCTL           UART_IRRCTL_(UART_MODULE)
/* IE */
#define UCA0IE                UC0IE
#define UCB0IE                UC0IE
#define UART_IE_(module)      UART_IE__(module)
#define UART_IE__(module)     UC##module##IE
#define UART_IE               UART_IE_(UART_MODULE)
/* TXIE */
#define UART_TXIE_(module)    UART_TXIE__(module)
#define UART_TXIE__(module)   UC##module##TXIE
#define UART_TXIE             UART_TXIE_(UART_MODULE)
/* RXIE */
#define UART_RXIE_(module)    UART_RXIE__(module)
#define UART_RXIE__(module)   UC##module##RXIE
#define UART_RXIE             UART_RXIE_(UART_MODULE)
/* IFG */
#define UCA0IFG               UC0IFG
#define UCB0IFG               UC0IFG
#define UART_IFG_(module)     UART_IFG__(module)
#define UART_IFG__(module)    UC##module##IFG
#define UART_IFG              UART_IFG_(UART_MODULE)
/* TXIFG */
#define UART_TXIFG_(module)   UART_TXIFG__(module)
#define UART_TXIFG__(module)  UC##module##TXIFG
#define UART_TXIFG            UART_TXIFG_(UART_MODULE)
/* RXIFG */
#define UART_RXIFG_(module)   UART_RXIFG__(module)
#define UART_RXIFG__(module)  UC##module##RXIFG
#define UART_RXIFG            UART_RXIFG_(UART_MODULE)

/* CTL0 -> Basic UART setup */
#if ((UART_CHAR_LEN < 7) || (UART_CHAR_LEN > 8))
    #error "Invalid character length specified. Valid range is [7..8]"
#endif /* UARC_CHAR_LEN */
#if ((UART_STOP_LEN < 1) || (UART_STOP_LEN > 2))
    #error "Invalid number of stop bits specified. Valid range is [1..2]"
#endif /* UARC_CHAR_LEN */
#define UART_CTL0_INIT ((UART_PARITY?UCPEN:0x00) \
                        (UART_PARITY_EVEN?UCPAR:0x00) \
                        (UART_MSB_FIRST?UCMSB:0x00) \
                        (UART_CHAR_LEN==7?UC7BIT:0x00) \
                        (UART_STOP_LEN==2?UCSPB:0x00))

/* baud rate clock generation */
#define UART_CTL1_INIT UCSSEL_2 /* Use SMCLK */
#define UART_INPUT_FREQ SMCLK_FREQ
/* UCBR_INIT = floor(Input freq / Baud) */
#define UART_BR0_INIT  ((UART_INPUT_FREQ / UART_BAUD) % 256)
#define UART_BR1_INIT  ((UART_INPUT_FREQ / UART_BAUD) / 256)
#if UART_BR1_INIT > 255
    #error "Baud rate not achievable with input clock"
#endif /* UART_BR1_INIT */
/* UCBRS_VALUE = mod(round(Input freq * 8 / Baud), 8) */
#define UART_UCBRS_VALUE (((UART_INPUT_FREQ * 8 + (UART_BAUD/2)) / UART_BAUD) % 8)
#if UART_UCBRS_VALUE == 0
    #define UART_UCBRS_INIT UCBRS_0
#elif UART_UCBRS_VALUE == 1
    #define UART_UCBRS_INIT UCBRS_1
#elif UART_UCBRS_VALUE == 2
    #define UART_UCBRS_INIT UCBRS_2
#elif UART_UCBRS_VALUE == 3
    #define UART_UCBRS_INIT UCBRS_3
#elif UART_UCBRS_VALUE == 4
    #define UART_UCBRS_INIT UCBRS_4
#elif UART_UCBRS_VALUE == 5
    #define UART_UCBRS_INIT UCBRS_5
#elif UART_UCBRS_VALUE == 6
    #define UART_UCBRS_INIT UCBRS_6
#elif UART_UCBRS_VALUE == 7
    #define UART_UCBRS_INIT UCBRS_7
#else
    #error "Error occured during Baud rate setup, check baud rate and input clock"
#endif
#define UART_MCTL_INIT (UART_UCBRS_INIT)
#define UART_STAT_INIT (UART_LOOPBACK?UCLISTEN:0x00)
#if UART_AUTOBAUD
    #if ((UART_AUTOBAUD_LEN < 1) || (UART_AUTOBAUD_LEN > 4))
        #error "Invalid autobaud break/synch delimiter length specified. Valid range is [1..4]"
    #endif /* UARC_CHAR_LEN */
    #define UART_ABCTL_INIT (((UART_AUTOBAUD_LEN+1) << 4) | \
                             (UART_AUTOBAUD_SYNC_TIMEOUT?UCSTOE:0x00) | \
                             (UART_AUTOBAUD_BREAK_TIMEOUT?UCBTOE:0x00) | \
                             (UART_AUTOBAUD?UCABDEN:0x00) )
#else
    #define UART_ABCTL_INIT 0x00
#endif /* UART_AUTOBAUD */
#if UART_IRDA
    #define UART_IRDA_TX_PULSE ((UART_IRDA_TX_PULSE_NS * 2 * UART_INPUT_FREQ + (UART_NS_PER_SECOND/2)) / UART_NS_PER_SECOND - 1)
    #if ((UART_IRDA_TX_PULSE < 0) || (UART_IRDA_TX_PULSE > 63))
        #error "UART IRDA pulse width out of range"
    #endif /* UART_IRDA_TX_PULSE */
    #define UART_IRTCTL_INIT ((UART_IRDA_TX_PULSE_3_16?(5<<2):(UART_IRDA_TX_PULSE<<2)) | \
                              (UART_IRDA_TX_PULSE_3_16?IRTXCLK:0x00) | \
                              (UART_IRDA?IREN:0x00) )
    #if UART_IRDA_RX_FILTER_EN
        #define UART_IRDA_RX_FILTER ((UART_IRDA_RX_FILTER_NS * 2 * UART_INPUT_FREQ + (UART_NS_PER_SECOND/2)) / UART_NS_PER_SECOND - 4)
        #if ((UART_IRDA_RX_FILTER < 0) || (UART_IRDA_RX_FILTER > 63))
            #error "UART IRDA filter length out of range"
        #endif /* UART_IRDA_RX_FILTER */
    #else
        #define UART_IRDA_RX_FILTER 0x00
    #endif /* UART_IRDA_RX_FILTER_EN */
    #define UART_IRRCTL_INIT ((UART_IRDA_RX_FILTER<<2) | \
                              (UART_IRDA_RX_POL_INV?IRRXPL:0x00) | \
                              (UART_IRDA_RX_FILTER_EN?IRRXFE:0x00) )
#else
    #define UART_IRTCTL_INIT 0x00
    #define UART_IRRCTL_INIT 0x00
#endif /* UART_IRDA */

/* ISR handler
 * Created as macro to eliminate function call in ISR
 */
#if PL_IS_DEMO // UART ISR for for demo platform
    #define UART_RX_ISR \
       if (UCA0RXBUF == 'h') \
       { \
          i = 0; \
          UC0IE |= UCA0TXIE; \
          UCA0TXBUF = string[i++]; \
       } \
       else if (UCA0RXBUF == 'r') \
       { \
           LED_RED_TOGGLE(); \
       } \
       else if (UCA0RXBUF == 'g') \
       { \
           LED_GREEN_TOGGLE(); \
       } \
       else if (UCA0RXBUF == 'b') \
       { \
           LED_BLUE_TOGGLE(); \
       } \
       else if (UCA0RXBUF == 'y') \
       { \
           LED_YELLOW_TOGGLE(); \
       } \
       else if (UCA0RXBUF == 'w') \
       { \
           LED_WHITE_TOGGLE(); \
       } \
       else if (UCA0RXBUF == 'd') \
       { \
           led_off(); \
       }

    #define UART_TX_ISR \
       UCA0TXBUF = string[i++]; \
       if (i == sizeof string - 1) \
          UC0IE &= ~UCA0TXIE;
#endif /* PL_IS_DEMO */

void init_uart(void);

#endif /* UART_H_ */
