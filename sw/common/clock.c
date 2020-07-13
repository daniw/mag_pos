/*
 * clock.c
 *
 * Created on: 03.07.2020
 *     Author: daniw
 */
#include "clock.h"

void init_clock(void){
    /* Load calibration data for 16MHz DCO frequency */
    DCOCTL  = 0x00; // Select lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_INIT; // Set range
    DCOCTL  = CALDCO_INIT; // Set DCO step + modulation
    #if BCSCTL2_INIT != 0
        BCSCTL2 = BCSCTL2_INIT;
    #endif
    return;
}
