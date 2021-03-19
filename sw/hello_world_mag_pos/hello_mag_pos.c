//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430.h>

#define RED   0x20
#define GREEN 0x10
#define BLUE  0x40

void sleep(void);

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P2DIR |= RED | GREEN | BLUE;           // Set P1.0 to output direction

    for(;;) {
        P2OUT = RED;                      // Toggle P1.0 using exclusive-OR
        sleep();
        P2OUT = GREEN;                      // Toggle P1.0 using exclusive-OR
        sleep();
        P2OUT = BLUE;                      // Toggle P1.0 using exclusive-OR
        sleep();
    }
}

void sleep(void){
    volatile unsigned int i;            // volatile to prevent optimization
    i = 10000;                          // SW Delay
    do i--;
    while(i != 0);
}
