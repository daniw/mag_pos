/*
 * gpio.h
 *
 *  Created on: 01.07.2020
 *      Author: daniw
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <msp430.h>
#include <stdint.h>
#include "platform.h"

/* 
 * Hardware definitions
 *
 */
#if PL_HW_G2_LAUNCHPAD
    #define LED_RED_PORT    P1OUT
    #define LED_RED_DIR     P1DIR
    #define LED_RED_PIN     0
    #define LED_GREEN_PORT  P1OUT
    #define LED_GREEN_DIR   P1DIR
    #define LED_GREEN_PIN   6
    #define LED_BLUE_PORT   P2OUT
    #define LED_BLUE_DIR    P2DIR
    #define LED_BLUE_PIN    6
    #define LED_YELLOW_PORT P2OUT
    #define LED_YELLOW_DIR  P2DIR
    #define LED_YELLOW_PIN  7
    #define LED_WHITE_PORT  P2OUT
    #define LED_WHITE_DIR   P2DIR
    #define LED_WHITE_PIN   5
    #define SW0_PORT        P1IN
    #define SW0_PU          P1REN
    #define SW0_DIR         P1DIR
    #define SW0_PIN         3
    #define RXD_PORT        P1OUT
    #define RXD_SEL         P1SEL
    #define RXD_SEL2        P1SEL2
    #define RXD             1
    #define TXD             2
#endif // PL_HW_G2_LAUNCHPAD

#if PL_HW_FR2_LAUNCHPAD
    // GPIO LED
    #define LED_RED_PORT        P1OUT
    #define LED_RED_DIR         P1DIR
    #define LED_RED_PIN         0
    #define LED_GREEN_PORT      P6OUT
    #define LED_GREEN_DIR       P6DIR
    #define LED_GREEN_PIN       6
    #define LED_BLUE_PORT       P2OUT
    #define LED_BLUE_DIR        P2DIR
    #define LED_BLUE_PIN        0
    #define LED_YELLOW_PORT     P2OUT
    #define LED_YELLOW_DIR      P2DIR
    #define LED_YELLOW_PIN      2
    #define LED_WHITE_PORT      P4OUT
    #define LED_WHITE_DIR       P4DIR
    #define LED_WHITE_PIN       4
    // GPIO Switch
    #define SW0_PORT            P4IN
    #define SW0_PU              P4REN
    #define SW0_DIR             P4DIR
    #define SW0_PIN             1
    #define SW1_PORT            P2IN
    #define SW1_PU              P2REN
    #define SW1_DIR             P2DIR
    #define SW1_PIN             3
    // GPIO MLX90393
    #define MLX_INT_PORT        P1IN
    #define MLX_INT_DIR         P1DIR
    #define MLX_INT_PIN         3
    #define MLX_INT_TRIG_PORT   P1OUT
    #define MLX_INT_TRIG_DIR    P1DIR
    #define MLX_INT_TRIG_PIN    2
    // UART
    #define P_TRXD_SEL0         P4SEL0
    #define P_TRXD_SEL1         P4SEL1
    #define RXD                 2
    #define TXD                 3
    // SPI
    #define SPI_PORT            P4OUT
    #define SPI_DIR             P4DIR
    #define SPI_SEL0            P4SEL0
    #define SPI_SEL1            P4SEL1
    #define SPI_CS_PORT         P5OUT
    #define SPI_CS_DIR          P5DIR
    #define SPI_CS_SEL0         P5SEL0
    #define SPI_CS_SEL1         P5SEL1
    #define SPI_CS_PIN          2
    #define SPI_SCLK_PORT       SPI_PORT
    #define SPI_SCLK_DIR        SPI_DIR
    #define SPI_SCLK_SEL0       SPI_SEL0
    #define SPI_SCLK_SEL1       SPI_SEL1
    #define SPI_SCLK_PIN        5
    #define SPI_MOSI_PORT       SPI_PORT
    #define SPI_MOSI_DIR        SPI_DIR
    #define SPI_MOSI_SEL0       SPI_SEL0
    #define SPI_MOSI_SEL1       SPI_SEL1
    #define SPI_MOSI_PIN        6
    #define SPI_MISO_PORT       SPI_PORT
    #define SPI_MISO_DIR        SPI_DIR
    #define SPI_MISO_SEL0       SPI_SEL0
    #define SPI_MISO_SEL1       SPI_SEL1
    #define SPI_MISO_PIN        7
    // MLX90393
#endif // PL_HW_FR2_LAUNCHPAD


#if PL_HW_MAG_POS_V1
    // GPIO LED
    #define LED_RED_PORT        P2OUT
    #define LED_RED_DIR         P2DIR
    #define LED_RED_PIN         6
    #define LED_GREEN_PORT      P2OUT
    #define LED_GREEN_DIR       P2DIR
    #define LED_GREEN_PIN       5
    #define LED_BLUE_PORT       P2OUT
    #define LED_BLUE_DIR        P2DIR
    #define LED_BLUE_PIN        4
    // GPIO MLX90393
    #define MLX_INT_PORT        P2IN
    #define MLX_INT_DIR         P2DIR
    #define MLX_INT_PIN         7
    #define MLX_INT_TRIG_PORT   P3OUT
    #define MLX_INT_TRIG_DIR    P3DIR
    #define MLX_INT_TRIG_PIN    0
    // UART
    #define P_TRXD_SEL0         P4SEL0
    #define P_TRXD_SEL1         P4SEL1
    #define RXD                 2
    #define TXD                 3
    // SPI
    #define SPI_PORT            P1OUT
    #define SPI_DIR             P1DIR
    #define SPI_SEL0            P1SEL0
    #define SPI_SEL1            P1SEL1
    #define SPI_CS_PORT         SPI_PORT
    #define SPI_CS_DIR          SPI_DIR
    #define SPI_CS_SEL0         SPI_SEL0
    #define SPI_CS_SEL1         SPI_SEL1
    #define SPI_CS_PIN          0
    #define SPI_SCLK_PORT       SPI_PORT
    #define SPI_SCLK_DIR        SPI_DIR
    #define SPI_SCLK_SEL0       SPI_SEL0
    #define SPI_SCLK_SEL1       SPI_SEL1
    #define SPI_SCLK_PIN        1
    #define SPI_MOSI_PORT       SPI_PORT
    #define SPI_MOSI_DIR        SPI_DIR
    #define SPI_MOSI_SEL0       SPI_SEL0
    #define SPI_MOSI_SEL1       SPI_SEL1
    #define SPI_MOSI_PIN        2
    #define SPI_MISO_PORT       SPI_OUT
    #define SPI_MISO_DIR        SPI_DIR
    #define SPI_MISO_SEL0       SPI_SEL0
    #define SPI_MISO_SEL1       SPI_SEL1
    #define SPI_MISO_PIN        3
#endif // PL_HW_MAG_POS_V1

#if PL_HAS_LED_RED
    #define MASK_LED_RED        (1<<LED_RED_PIN)
    #define LED_RED_ON()        LED_RED_PORT |= MASK_LED_RED
    #define LED_RED_OFF()       LED_RED_PORT &= ~MASK_LED_RED
    #define LED_RED_TOGGLE()    LED_RED_PORT ^= MASK_LED_RED
#endif // PL_HAS_LED_RED

#if PL_HAS_LED_GREEN
    #define MASK_LED_GREEN      (1<<LED_GREEN_PIN)
    #define LED_GREEN_ON()      LED_GREEN_PORT |= MASK_LED_GREEN
    #define LED_GREEN_OFF()     LED_GREEN_PORT &= ~MASK_LED_GREEN
    #define LED_GREEN_TOGGLE()  LED_GREEN_PORT ^= MASK_LED_GREEN
#endif // PL_HAS_LED_GREEN

#if PL_HAS_LED_BLUE
    #define MASK_LED_BLUE       (1<<LED_BLUE_PIN)
    #define LED_BLUE_ON()       LED_BLUE_PORT |= MASK_LED_BLUE
    #define LED_BLUE_OFF()      LED_BLUE_PORT &= ~MASK_LED_BLUE
    #define LED_BLUE_TOGGLE()   LED_BLUE_PORT ^= MASK_LED_BLUE
#endif // PL_HAS_LED_BLUE

#if PL_HAS_LED_YELLOW
    #define MASK_LED_YELLOW     (1<<LED_YELLOW_PIN)
    #define LED_YELLOW_ON()     LED_YELLOW_PORT |= MASK_LED_YELLOW
    #define LED_YELLOW_OFF()    LED_YELLOW_PORT &= ~MASK_LED_YELLOW
    #define LED_YELLOW_TOGGLE() LED_YELLOW_PORT ^= MASK_LED_YELLOW
#endif // PL_HAS_LED_YELLOW

#if PL_HAS_LED_WHITE
    #define MASK_LED_WHITE      (1<<LED_WHITE_PIN)
    #define LED_WHITE_ON()      LED_WHITE_PORT |= MASK_LED_WHITE
    #define LED_WHITE_OFF()     LED_WHITE_PORT &= ~MASK_LED_WHITE
    #define LED_WHITE_TOGGLE()  LED_WHITE_PORT ^= MASK_LED_WHITE
#endif // PL_HAS_LED_WHITE

#if PL_HAS_SW0
    #define MASK_SW0            (1<<SW0_PIN)
    #define SW0_READ            ((SW0_PORT&(MASK_SW0)) == 0)
#endif // PL_HAS_SW0

#if PL_HAS_SW1
    #define MASK_SW1            (1<<SW1_PIN)
    #define SW1_READ            ((SW1_PORT&(MASK_SW1)) == 0)
#endif // PL_HAS_SW1

#if PL_HAS_MLX90393
    // MLX_INT
    #define MASK_MLX_INT            (1<<MLX_INT_PIN)
    #define MLX_INT_READ            (MLX_INT_PORT&(MASK_MLX_INT)) 
    // MLX_INT_TRIG
    #define MASK_MLX_INT_TRIG       (1<<MLX_INT_TRIG_PIN)
    #define MLX_INT_TRIG_ON()       MLX_INT_TRIG_PORT |= MASK_MLX_INT_TRIG
    #define MLX_INT_TRIG_OFF()      MLX_INT_TRIG_PORT &= ~MASK_MLX_INT_TRIG
    #define MLX_INT_TRIG_TOGGLE()   MLX_INT_TRIG_PORT ^= MASK_MLX_INT_TRIG
#endif // PL_HAS_MLX90393

#if PL_HAS_UART
    #define MASK_RXD            (1<<RXD)
    #define MASK_TXD            (1<<TXD)
#endif // PL_HAS_UART

#if PL_HAS_SPI
    #define MASK_SPI_CS         (1<<SPI_CS_PIN)
    #define MASK_SPI_SCLK       (1<<SPI_SCLK_PIN)
    #define MASK_SPI_MOSI       (1<<SPI_MOSI_PIN)
    #define MASK_SPI_MISO       (1<<SPI_MISO_PIN)
#endif // PL_HAS_SPI

void init_gpio(void);
void led_off(void);

#endif // GPIO_H_
