/*
 * interval.c
 *
 *  Created on: 24.08.2021
 *      Author: daniw
 */

#include "interval.h"

#if PL_HAS_INTERVAL

/* Variables */
static uint8_t interval_variable;

/* Functions */
void init_interval(void){
    /* Initialize registers */
    #if INTERVAL_R_INIT != 0
        INTERVAL_R = INTERVAL_R_INIT;
    #endif
    #if INTERVAL_TBEX0_INIT != 0
        INTERVAL_EX0 = INTERVAL_TBEX0_INIT
    #endif
    #if INTERVAL_CCR0_INIT != 0
        INTERVAL_CCR0 = INTERVAL_CCR0_INIT;
    #endif
    #if INTERVAL_CCR1_INIT != 0
        INTERVAL_CCR1 = INTERVAL_CCR1_INIT;
    #endif
    #if INTERVAL_CCR2_INIT != 0
        INTERVAL_CCR2 = INTERVAL_CCR2_INIT;
    #endif
    #if INTERVAL_CCR3_INIT != 0
        INTERVAL_CCR3 = INTERVAL_CCR3_INIT;
    #endif
    #if INTERVAL_CCR4_INIT != 0
        INTERVAL_CCR4 = INTERVAL_CCR4_INIT;
    #endif
    #if INTERVAL_CCR5_INIT != 0
        INTERVAL_CCR5 = INTERVAL_CCR5_INIT;
    #endif
    #if INTERVAL_CCR6_INIT != 0
        INTERVAL_CCR6 = INTERVAL_CCR6_INIT;
    #endif
    #if INTERVAL_CCTL0_INIT != 0
        INTERVAL_CCTL0 = INTERVAL_CCTL0_INIT;
    #endif
    #if INTERVAL_CCTL1_INIT != 0
        INTERVAL_CCTL1 = INTERVAL_CCTL1_INIT;
    #endif
    #if INTERVAL_CCTL2_INIT != 0
        INTERVAL_CCTL2 = INTERVAL_CCTL2_INIT;
    #endif
    #if INTERVAL_CCTL3_INIT != 0
        INTERVAL_CCTL3 = INTERVAL_CCTL3_INIT;
    #endif
    #if INTERVAL_CCTL4_INIT != 0
        INTERVAL_CCTL4 = INTERVAL_CCTL4_INIT;
    #endif
    #if INTERVAL_CCTL5_INIT != 0
        INTERVAL_CCTL5 = INTERVAL_CCTL5_INIT;
    #endif
    #if INTERVAL_CCTL6_INIT != 0
        INTERVAL_CCTL6 = INTERVAL_CCTL6_INIT;
    #endif
    #if INTERVAL_CTL_INIT != 0
        INTERVAL_CTL = INTERVAL_CTL_INIT;
    #endif
    /* Release SPI module for normal operation */
    SPI_CTLW0 &= ~UCSWRST;
    /* Enable interrupts */
    SPI_IE = SPI_IE_INIT;
    return;
}

void interval_isr(void){
}

#endif /* PL_HAS_INTERVAL */
