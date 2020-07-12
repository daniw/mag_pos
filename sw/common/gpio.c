/*
 * gpio.c
 *
 *  Created on: 01.07.2020
 *      Author: daniw
 */

#include "gpio.h"

void init_gpio(void)
{
    // Set LEDs as outputs
    LED_RED_DIR     |= 1<<LED_RED_PIN;
    LED_GREEN_DIR   |= 1<<LED_GREEN_PIN;
    LED_BLUE_DIR    |= 1<<LED_BLUE_PIN;
    LED_YELLOW_DIR  |= 1<<LED_YELLOW_PIN;
    LED_WHITE_DIR   |= 1<<LED_WHITE_PIN;

    P2SEL = 0x00;                   // Disable crystal oscillator
//#ifdef PL_HAS_UART
    P1SEL  |= MASK_RXD + MASK_TXD; // P1.1 = RXD, P1.2=TXD
    P1SEL2 |= MASK_RXD + MASK_TXD; // P1.1 = RXD, P1.2=TXD
//#endif

    SW_PU |= MASK_SW;               // Enable Pull up resistor for button
}

void led_off(void)
{
    P1OUT = PORT1_OFF|MASK_SW;
    P2OUT = PORT2_OFF;
    return;
}

void led_red(void)
{
    led_off();
    LED_RED_PORT |= MASK_RED;
    return;
}

void led_green(void)
{
    led_off();
    LED_GREEN_PORT |= MASK_GREEN;
    return;
}

void led_blue(void)
{
    led_off();
    LED_BLUE_PORT |= MASK_BLUE;
    return;
}

void led_yellow(void)
{
    led_off();
    LED_YELLOW_PORT |= MASK_YELLOW;
    return;
}

void led_white(void)
{
    led_off();
    LED_WHITE_PORT |= MASK_WHITE;
    return;
}
