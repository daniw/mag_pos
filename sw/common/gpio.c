/*
 * gpio.c
 *
 *  Created on: 01.07.2020
 *      Author: daniw
 */

#include "platform.h"
#include "gpio.h"

void init_gpio(void)
{
    // Set LEDs as outputs
    #if PL_HAS_LED_RED
        LED_RED_DIR     |= 1<<LED_RED_PIN;
    #endif /* PL_HAS_LED_RED */
    #if PL_HAS_LED_GREEN
        LED_GREEN_DIR   |= 1<<LED_GREEN_PIN;
    #endif /* PL_HAS_LED_GREEN */
    #if PL_HAS_LED_BLUE
        LED_BLUE_DIR    |= 1<<LED_BLUE_PIN;
    #endif /* PL_HAS_LED_BLUE */
    #if PL_HAS_LED_YELLOW
        LED_YELLOW_DIR  |= 1<<LED_YELLOW_PIN;
    #endif /* PL_HAS_LED_YELLOW */
    #if PL_HAS_LED_WHITE
        LED_WHITE_DIR   |= 1<<LED_WHITE_PIN;
    #endif /* PL_HAS_LED_WHITE */

    #if PL_IS_DEMO
    P2SEL &= ~((1<<6) | (1<<7));                   // Disable crystal oscillator
    #endif /* PL_IS_DEMO */

    #if PL_HAS_UART
        P1SEL  |= MASK_RXD + MASK_TXD; // P1.1 = RXD, P1.2=TXD
        P1SEL2 |= MASK_RXD + MASK_TXD; // P1.1 = RXD, P1.2=TXD
    #endif

    #if PL_HAS_SW0
        SW0_PU |= MASK_SW0;               // Enable Pull up resistor for button
    #endif /* PL_HAS_SW0 */
    #if PL_HAS_SW1
        SW1_PU |= MASK_SW1;               // Enable Pull up resistor for button
    #endif /* PL_HAS_SW1 */
}

void led_off(void)
{
    #if PL_HAS_LED_RED
        LED_RED_OFF();
    #endif /* PL_HAS_LED_RED */
    #if PL_HAS_LED_GREEN
        LED_GREEN_OFF();
    #endif /* PL_HAS_LED_GREEN */
    #if PL_HAS_LED_BLUE
        LED_BLUE_OFF();
    #endif /* PL_HAS_LED_BLUE */
    #if PL_HAS_LED_YELLOW
        LED_YELLOW_OFF();
    #endif /* PL_HAS_LED_YELLOW */
    #if PL_HAS_LED_WHITE
        LED_WHITE_OFF();
    #endif /* PL_HAS_LED_WHITE */
    return;
}
