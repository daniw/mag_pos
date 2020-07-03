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

    SW_PU |= MASK_SW;               // Enable Pull up resistor for button
}

void led_off(void)
{
    P1OUT = PORT1_OFF|MASK_SW;
    P2OUT = PORT2_OFF;
}

void led_red(void)
{
    led_off();
    LED_RED_PORT |= MASK_RED;
}

void led_green(void)
{
    led_off();
    LED_GREEN_PORT |= MASK_GREEN;
}

void led_blue(void)
{
    led_off();
    LED_BLUE_PORT |= MASK_BLUE;
}

void led_yellow(void)
{
    led_off();
    LED_YELLOW_PORT |= MASK_YELLOW;
}

void led_white(void)
{
    led_off();
    LED_WHITE_PORT |= MASK_WHITE;
}
