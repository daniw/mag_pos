/*
 * clock.c
 *
 * Created on: 03.07.2020
 *     Author: daniw
 */
#include "clock.h"

void init_clock(void){
    #if PL_HAS_BASIC_CLOCK_MODULE_PLUS
        /* Load calibration data for DCO frequency */
        DCOCTL  = 0x00; // Select lowest DCOx and MODx settings
        BCSCTL1 = CALBC1_INIT; // Set range
        DCOCTL  = CALDCO_INIT; // Set DCO step + modulation
        #if BCSCTL2_INIT != 0
            BCSCTL2 = BCSCTL2_INIT;
        #endif /* BCSCTL2_INIT */
    #elif PL_HAS_BASIC_CLOCK_MODULE_PLUS
        /* \todo Implement MSP430FR clock initialisation */
    #endif /* Platform clock module */
    return;
}
