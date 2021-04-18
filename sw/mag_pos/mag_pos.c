#include <msp430.h>
#include <stdint.h>

#include "platform.h"
#include "clock.h"
#include "gpio.h"
#include "uart.h"
#include "mlx90393.h"
#include "conversions.h"
#include "dac.h"

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
 * mag_pos.c
 */

uint8_t* txt = (uint8_t *){ "Saali hoi! " };


#pragma PERSISTENT(c)
uint8_t c[1] = {97};

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer

    init_clock();
    init_gpio();
    PM5CTL0 &= ~LOCKLPM5;           // Disable the GPIO power-on default high-impedance mode

    #if PL_HAS_UART
    init_uart();
    #endif /* PL_HAS_UART */

    init_dac();

    *c += 1;
    __bis_SR_register(GIE);         // Enable global interrupts
    led_off();
    while(1)
    {
        #if PL_HAS_UART
        uart_transmit(c, 1);
        #endif /* PL_HAS_UART */
        led_ctrl();

        // Sleep even longer...
        uint8_t j;
        for (j = 50; j > 0; j--) {
            sleep(SLEEPCNT_SLOW);
        }
    }
}

void led_ctrl(){
    static uint8_t state = 0;
    switch (state)
    {
    case STATE_OFF:
        led_off();
        dac_set_value(SAC_MODULE_A, 3460);
        dac_set_value(SAC_MODULE_B, 870);
        state++;
        break;
    #if PL_HAS_LED_RED
    case STATE_RED:
        led_off();
        LED_RED_ON();
        dac_set_value(SAC_MODULE_A, 3000);
        dac_set_value(SAC_MODULE_B, 1444);
        state++;
        break;
    #endif /* PL_HAS_LED_RED */
    #if PL_HAS_LED_GREEN
    case STATE_GREEN:
        led_off();
        LED_GREEN_ON();
        dac_set_value(SAC_MODULE_A, 2065);
        dac_set_value(SAC_MODULE_B, 2500);
        state++;
        break;
    #endif /* PL_HAS_LED_GREEN */
    #if PL_HAS_LED_BLUE
    case STATE_BLUE:
        led_off();
        LED_BLUE_ON();
        dac_set_value(SAC_MODULE_A, 700);
        dac_set_value(SAC_MODULE_B, 3300);
        state++;
        break;
    #endif /* PL_HAS_LED_BLUE */
    #if PL_HAS_LED_YELLOW
    case STATE_YELLOW:
        led_off();
        LED_YELLOW_ON();
        state++;
        break;
    #endif /* PL_HAS_LED_YELLOW */
    #if PL_HAS_LED_WHITE
    case STATE_WHITE:
        led_off();
        LED_WHITE_ON();
        state++;
        break;
    #endif /* PL_HAS_LED_WHITE */
    default:
        led_off();
        state = STATE_OFF;
    }
}

void sleep(uint16_t sleepcnt){
    volatile uint16_t i;            // volatile to prevent optimization
    for(i=sleepcnt; i>0; i--);      // delay
    return;
}
