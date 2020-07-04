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
    BCSCTL1 = CALBC1_16MHZ; // Set range
    DCOCTL  = CALDCO_16MHZ; // Set DCO step + modulation
    /* Use VCO as main clock without Prescaler */
    BCSCTL2 = SELM_0 | DIVM_0;
    return;
}
