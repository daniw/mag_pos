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
        LED_RED_DIR     |= MASK_LED_RED;
    #endif /* PL_HAS_LED_RED */
    #if PL_HAS_LED_GREEN
        LED_GREEN_DIR   |= MASK_LED_GREEN;
    #endif /* PL_HAS_LED_GREEN */
    #if PL_HAS_LED_BLUE
        LED_BLUE_DIR    |= MASK_LED_BLUE;
    #endif /* PL_HAS_LED_BLUE */
    #if PL_HAS_LED_YELLOW
        LED_YELLOW_DIR  |= MASK_LED_YELLOW;
    #endif /* PL_HAS_LED_YELLOW */
    #if PL_HAS_LED_WHITE
        LED_WHITE_DIR   |= MASK_LED_WHITE;
    #endif /* PL_HAS_LED_WHITE */

    #if PL_IS_DEMO
        #if PL_HW_G2_LAUNCHPAD
            P2SEL &= ~((1<<6) | (1<<7));           // Disable crystal oscillator
        #endif /* PL_HW_G2_LAUNCHPAD */
    #endif /* PL_IS_DEMO */

    #if PL_HAS_UART
        #if PL_HW_G2_LAUNCHPAD
            RXD_SEL  |= MASK_RXD + MASK_TXD; // P1.1 = RXD, P1.2=TXD
            RXD_SEL2 |= MASK_RXD + MASK_TXD; // P1.1 = RXD, P1.2=TXD
        #elif PL_HW_MAG_POS_V1
            P4DIR = 0xFF;
            P4OUT &= 0x00;
            //PXD_SEL0 |= MASK_RXD + MASK_TXD; // P4.2 = RXD, P4.3=TXD
            PXD_SEL1 |= MASK_RXD + MASK_TXD; // P4.2 = RXD, P4.3=TXD
        #endif
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
