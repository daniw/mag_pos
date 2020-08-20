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
    #define SW_PORT         P1IN
    #define SW_PU           P1REN
    #define SW_DIR          P1DIR
    #define SW_PIN          3
    // Todo: Port and SEL for RXD and TXD missing
    #define RXD             1
    #define TXD             2
#endif

#if PL_HAS_LED_RED
    #define MASK_RED            (1<<LED_RED_PIN)
    #define LED_RED_ON()        LED_RED_PORT |= MASK_RED
    #define LED_RED_OFF()       LED_RED_PORT &= ~MASK_RED
    #define LED_RED_TOGGLE()    LED_RED_PORT ^= MASK_RED
#endif /* PL_HAS_LED_RED */

#if PL_HAS_LED_RED
    #define MASK_GREEN          (1<<LED_GREEN_PIN)
    #define LED_GREEN_ON()      LED_GREEN_PORT |= MASK_GREEN
    #define LED_GREEN_OFF()     LED_GREEN_PORT &= ~MASK_GREEN
    #define LED_GREEN_TOGGLE()  LED_GREEN_PORT ^= MASK_GREEN
#endif /* PL_HAS_LED_GREEN */

#if PL_HAS_LED_RED
    #define MASK_BLUE           (1<<LED_BLUE_PIN)
    #define LED_BLUE_ON()       LED_BLUE_PORT |= MASK_BLUE
    #define LED_BLUE_OFF()      LED_BLUE_PORT &= ~MASK_BLUE
    #define LED_BLUE_TOGGLE()   LED_BLUE_PORT ^= MASK_BLUE
#endif /* PL_HAS_LED_BLUE */

#if PL_HAS_LED_RED
    #define MASK_YELLOW         (1<<LED_YELLOW_PIN)
    #define LED_YELLOW_ON()     LED_YELLOW_PORT |= MASK_YELLOW
    #define LED_YELLOW_OFF()    LED_YELLOW_PORT &= ~MASK_YELLOW
    #define LED_YELLOW_TOGGLE() LED_YELLOW_PORT ^= MASK_YELLOW
#endif /* PL_HAS_LED_YELLOW */

#if PL_HAS_LED_RED
    #define MASK_WHITE          (1<<LED_WHITE_PIN)
    #define LED_WHITE_ON()      LED_WHITE_PORT |= MASK_WHITE
    #define LED_WHITE_OFF()     LED_WHITE_PORT &= ~MASK_WHITE
    #define LED_WHITE_TOGGLE()  LED_WHITE_PORT ^= MASK_WHITE
#endif /* PL_HAS_LED_WHITE */

#if PL_HAS_SW
    #define MASK_SW             (1<<SW_PIN)
    #define SW_READ	            ((SW_PORT&(MASK_SW)) == 0)
#endif /* PL_HAS_SW */

#if PL_HAS_UART
    #define MASK_RXD        (1<<RXD)
    #define MASK_TXD        (1<<TXD)
#endif /* PL_HAS_UART */

void init_gpio(void);
void led_off(void);

#endif /* GPIO_H_ */
