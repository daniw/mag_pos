#include <msp430.h>

#include "gpio.h"

#define SLEEPCNT_SLOW 16384
#define SLEEPCNT_FAST SLEEPCNT_SLOW/8

#define STATE_OFF       0
#define STATE_RED       1
#define STATE_GREEN     2
#define STATE_BLUE      3
#define STATE_YELLOW    4
#define STATE_WHITE     5

void sleep(unsigned int sleepcnt);
void led_ctrl();

/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer

	init_gpio();

	while(1)
	{
        led_ctrl();
	    if (SW_READ) {
	        sleep(SLEEPCNT_FAST);
	    } else {
	        sleep(SLEEPCNT_SLOW);
	    }
	}
}

void led_ctrl(){
    static unsigned int state = 0;
    state++;
    switch (state)
    {
    case STATE_OFF:
        led_off();
        break;
    case STATE_RED:
        led_red();
        break;
    case STATE_GREEN:
        led_green();
        break;
    case STATE_BLUE:
        led_blue();
        break;
    case STATE_YELLOW:
        led_yellow();
        break;
    case STATE_WHITE:
        led_white();
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

void sleep(unsigned int sleepcnt){
    volatile unsigned int i;        // volatile to prevent optimization
    for(i=sleepcnt; i>0; i--);      // delay
    return;
}
