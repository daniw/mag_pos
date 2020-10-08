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
#endif /* PL_HW_G2_LAUNCHPAD */

#if PL_HW_FR2_LAUNCHPAD
    #define LED_RED_PORT    P3OUT
    #define LED_RED_DIR     P3DIR
    #define LED_RED_PIN     4
    #define LED_GREEN_PORT  P1OUT
    #define LED_GREEN_DIR   P1DIR
    #define LED_GREEN_PIN   5
    #define LED_BLUE_PORT   P2OUT
    #define LED_BLUE_DIR    P2DIR
    #define LED_BLUE_PIN    0
    #define LED_YELLOW_PORT P2OUT
    #define LED_YELLOW_DIR  P2DIR
    #define LED_YELLOW_PIN  2
    #define LED_WHITE_PORT  P4OUT
    #define LED_WHITE_DIR   P4DIR
    #define LED_WHITE_PIN   4
    #define SW0_PORT        P4IN
    #define SW0_PU          P4REN
    #define SW0_DIR         P4DIR
    #define SW0_PIN         1
    #define SW1_PORT        P2IN
    #define SW1_PU          P2REN
    #define SW1_DIR         P2DIR
    #define SW1_PIN         3
    // Todo: Port and SEL for RXD and TXD missing
    #define RXD_PORT        P4OUT
    #define RXD             2
    #define TXD             3
#endif /* PL_HW_FR2_LAUNCHPAD */

#if PL_HAS_LED_RED
    #define MASK_LED_RED        (1<<LED_RED_PIN)
    #define LED_RED_ON()        LED_RED_PORT |= MASK_LED_RED
    #define LED_RED_OFF()       LED_RED_PORT &= ~MASK_LED_RED
    #define LED_RED_TOGGLE()    LED_RED_PORT ^= MASK_LED_RED
#endif /* PL_HAS_LED_RED */

#if PL_HAS_LED_RED
    #define MASK_LED_GREEN      (1<<LED_GREEN_PIN)
    #define LED_GREEN_ON()      LED_GREEN_PORT |= MASK_LED_GREEN
    #define LED_GREEN_OFF()     LED_GREEN_PORT &= ~MASK_LED_GREEN
    #define LED_GREEN_TOGGLE()  LED_GREEN_PORT ^= MASK_LED_GREEN
#endif /* PL_HAS_LED_GREEN */

#if PL_HAS_LED_RED
    #define MASK_LED_BLUE       (1<<LED_BLUE_PIN)
    #define LED_BLUE_ON()       LED_BLUE_PORT |= MASK_LED_BLUE
    #define LED_BLUE_OFF()      LED_BLUE_PORT &= ~MASK_LED_BLUE
    #define LED_BLUE_TOGGLE()   LED_BLUE_PORT ^= MASK_LED_BLUE
#endif /* PL_HAS_LED_BLUE */

#if PL_HAS_LED_RED
    #define MASK_LED_YELLOW     (1<<LED_YELLOW_PIN)
    #define LED_YELLOW_ON()     LED_YELLOW_PORT |= MASK_LED_YELLOW
    #define LED_YELLOW_OFF()    LED_YELLOW_PORT &= ~MASK_LED_YELLOW
    #define LED_YELLOW_TOGGLE() LED_YELLOW_PORT ^= MASK_LED_YELLOW
#endif /* PL_HAS_LED_YELLOW */

#if PL_HAS_LED_RED
    #define MASK_LED_WHITE      (1<<LED_WHITE_PIN)
    #define LED_WHITE_ON()      LED_WHITE_PORT |= MASK_LED_WHITE
    #define LED_WHITE_OFF()     LED_WHITE_PORT &= ~MASK_LED_WHITE
    #define LED_WHITE_TOGGLE()  LED_WHITE_PORT ^= MASK_LED_WHITE
#endif /* PL_HAS_LED_WHITE */

#if PL_HAS_SW0
    #define MASK_SW0            (1<<SW0_PIN)
    #define SW0_READ            ((SW0_PORT&(MASK_SW0)) == 0)
#endif /* PL_HAS_SW0 */

#if PL_HAS_SW1
    #define MASK_SW1            (1<<SW1_PIN)
    #define SW1_READ            ((SW1_PORT&(MASK_SW1)) == 0)
#endif /* PL_HAS_SW1 */

#if PL_HAS_UART
    #define MASK_RXD        (1<<RXD)
    #define MASK_TXD        (1<<TXD)
#endif /* PL_HAS_UART */

void init_gpio(void);
void led_off(void);

#endif /* GPIO_H_ */
