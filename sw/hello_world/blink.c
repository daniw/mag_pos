#include <msp430.h>				

#define SLEEPCNT 30000

#define STATE_OFF       0
#define STATE_RED       1
#define STATE_GREEN     2
#define STATE_BLUE      3
#define STATE_YELLOW    4
#define STATE_WHITE     5

#define PORT1_OFF       0x00
#define PORT1_RED       1<<0
#define PORT1_GREEN     1<<6
#define PORT1_BLUE      0x00
#define PORT1_YELLOW    0x00
#define PORT1_WHITE     0x00

#define PORT2_OFF       0x00
#define PORT2_RED       0x00
#define PORT2_GREEN     0x00
#define PORT2_BLUE      1<<6
#define PORT2_YELLOW    1<<7
#define PORT2_WHITE     1<<5

void sleep();
void led_ctrl();

/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
    P1DIR |= PORT1_RED;             // configure LED as output (red)
    P1DIR |= PORT1_GREEN;           // configure LED as output (green)
    P1DIR |= PORT1_BLUE;            // configure LED as output (blue)
    P1DIR |= PORT1_YELLOW;          // configure LED as output (yellow)
    P1DIR |= PORT1_WHITE;           // configure LED as output (white)

    P2DIR |= PORT2_RED;             // configure LED as output (red)
    P2DIR |= PORT2_GREEN;           // configure LED as output (green)
    P2DIR |= PORT2_BLUE;            // configure LED as output (blue)
    P2DIR |= PORT2_YELLOW;          // configure LED as output (yellow)
    P2DIR |= PORT2_WHITE;           // configure LED as output (white)

    P2SEL = 0x00;

	while(1)
	{
	    led_ctrl();
	    sleep();
	}
}

void led_ctrl(){
    static unsigned int state = 0;
    state++;
    switch (state)
    {
    case STATE_OFF:
        P1OUT = PORT1_OFF;
        P2OUT = PORT2_OFF;
        break;
    case STATE_RED:
        P1OUT = PORT1_RED;
        P2OUT = PORT2_RED;
        break;
    case STATE_GREEN:
        P1OUT = PORT1_GREEN;
        P2OUT = PORT2_GREEN;
        break;
    case STATE_BLUE:
        P1OUT = PORT1_BLUE;
        P2OUT = PORT2_BLUE;
        break;
    case STATE_YELLOW:
        P1OUT = PORT1_YELLOW;
        P2OUT = PORT2_YELLOW;
        break;
    case STATE_WHITE:
        P1OUT = PORT1_WHITE;
        P2OUT = PORT2_WHITE;
        break;
    default:
        P1OUT = PORT1_OFF;
        P2OUT = PORT2_OFF;
        state = 0;
    }
    if (state > 5)
    {
        state = STATE_OFF;
    }
}

void sleep(){
    volatile unsigned int i;        // volatile to prevent optimization
    for(i=SLEEPCNT; i>0; i--);      // delay
    return;
}
