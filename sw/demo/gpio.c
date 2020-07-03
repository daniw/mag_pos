/*
 * gpio.c
 *
 *  Created on: 01.07.2020
 *      Author: setup
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

    P1REN |= 1<<3;                  // Enable Pull up resistor for button
}

void led_off(void)
{
    P1OUT = PORT1_OFF|PORT1_SW;
    P2OUT = PORT2_OFF;
}

void led_red(void)
{
    led_off();
    LED_RED_PORT |= 1<<LED_RED_PIN;
}

void led_green(void)
{
    led_off();
    LED_GREEN_PORT |= 1<<LED_GREEN_PIN;
}

void led_blue(void)
{
    led_off();
    LED_BLUE_PORT |= 1<<LED_BLUE_PIN;
}

void led_yellow(void)
{
    led_off();
    LED_YELLOW_PORT |= 1<<LED_YELLOW_PIN;
}

void led_white(void)
{
    led_off();
    LED_WHITE_PORT |= 1<<LED_WHITE_PIN;
}
