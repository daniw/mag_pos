#include <msp430.h>
#include <stdint.h>

#include "platform.h"
#include "clock.h"
#include "gpio.h"
#include "uart.h"
#include "mlx90393.h"

#define SLEEPCNT_SLOW 65535
#define SLEEPCNT_FAST SLEEPCNT_SLOW/8

#define STATE_OFF       0
#define STATE_RED       1
#define STATE_GREEN     2
#define STATE_BLUE      3
#define STATE_YELLOW    4
#define STATE_WHITE     5

void sleep(uint16_t sleepcnt);
void led_ctrl();

/**
 * demo.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer

    init_clock();
    init_gpio();
    led_off(); // TODO: Set all ports output registers 0 in init_gpio
    init_uart();
    mlx90393_init();

    __bis_SR_register(GIE); // Enable global interrupts

     while(1)
    {
        //led_ctrl();
        /*if (SW_READ) {
            sleep(SLEEPCNT_FAST);
        } else {
            sleep(SLEEPCNT_SLOW);
        }*/
    }
}

void led_ctrl(){
    static uint8_t state = 0;
    state++;
    switch (state)
    {
    case STATE_OFF:
        led_off();
        break;
    case STATE_RED:
        LED_RED_ON();
        break;
    case STATE_GREEN:
        LED_GREEN_ON();
        break;
    case STATE_BLUE:
        LED_BLUE_ON();
        break;
    case STATE_YELLOW:
        LED_YELLOW_ON();
        break;
    case STATE_WHITE:
        LED_WHITE_ON();
        break;
    default:
        led_off();
        state = 0;
    }
    if (state > 5)
    {
        state = STATE_OFF;
    }
}

void sleep(uint16_t sleepcnt){
    volatile uint16_t i;        // volatile to prevent optimization
    for(i=sleepcnt; i>0; i--);      // delay
    return;
}
