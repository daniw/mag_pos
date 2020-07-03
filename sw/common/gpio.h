/*
 * gpio.h
 *
 *  Created on: 01.07.2020
 *      Author: daniw
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <msp430.h>

#define PORT1_SW        1<<3

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
#define SW_DIR          P1DIR
#define SW_PIN          3

#define PORT1_OFF       (0x00)
#define PORT1_RED       (1<<LED_RED_PIN)
#define PORT1_GREEN     (1<<LED_GREEN_PIN)
#define PORT1_BLUE      (0x00)
#define PORT1_YELLOW    (0x00)
#define PORT1_WHITE     (0x00)

#define PORT2_OFF       (0x00)
#define PORT2_RED       (0x00)
#define PORT2_GREEN     (0x00)
#define PORT2_BLUE      (1<<LED_BLUE_PIN)
#define PORT2_YELLOW    (1<<LED_YELLOW_PIN)
#define PORT2_WHITE     (1<<LED_WHITE_PIN)

#define LED_PORT(color) PORT_LED_##color
#define LED_DIR(color)  LED_PORT(!color)##DIR
#define LED_INIT(color) LED_PORT(!color)##DIR |= 1<<LED_##color##_PIN

void init_gpio(void);
void led_off(void);
void led_red(void);
void led_green(void);
void led_blue(void);
void led_yellow(void);
void led_white(void);

#endif /* GPIO_H_ */
