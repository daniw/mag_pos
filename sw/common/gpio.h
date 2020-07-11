/*
 * gpio.h
 *
 *  Created on: 01.07.2020
 *      Author: daniw
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <msp430.h>

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

#define MASK_SW         (1<<SW_PIN)

#define PORT1_OFF       (0x00)
#define PORT2_OFF       (0x00)

#define MASK_RED        (1<<LED_RED_PIN)
#define MASK_GREEN      (1<<LED_GREEN_PIN)
#define MASK_BLUE       (1<<LED_BLUE_PIN)
#define MASK_YELLOW     (1<<LED_YELLOW_PIN)
#define MASK_WHITE      (1<<LED_WHITE_PIN)

#define SW_READ	        ((SW_PORT&(MASK_SW)) == 0)

#define RXD             1
#define TXD             2

#define MASK_RXD        (1<<RXD)
#define MASK_TXD        (1<<TXD)

void init_gpio(void);
void led_off(void);

void led_red(void);
void led_red_on(void);
void led_red_off(void);
void led_red_toggle(void);

void led_green(void);
void led_green_on(void);
void led_green_off(void);
void led_green_toggle(void);

void led_blue(void);
void led_blue_on(void);
void led_blue_off(void);
void led_blue_toggle(void);

void led_yellow(void);
void led_yellow_on(void);
void led_yellow_off(void);
void led_yellow_toggle(void);

void led_white(void);
void led_white_on(void);
void led_white_off(void);
void led_white_toggle(void);

#endif /* GPIO_H_ */
