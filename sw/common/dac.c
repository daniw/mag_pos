/*
 * dac.c
 *
 *  Created on: 11.04.2021
 *      Author: alexh
 */

#include "dac.h"

void init_dac(void) {
#ifdef __MSP430FR2355__
    P3SEL0 |= BIT1;                           // Select P3.1 as OA2O function
    P3SEL1 |= BIT1;
    P3SEL0 |= BIT5;                           // Select P3.5 as OA3O function
    P3SEL1 |= BIT5;
    SAC_DAC &= ~(DACEN); // Registers can only be written when DAC is not enabled.
    SAC_PGA = SAC_PGA_INIT;
    SAC_DAC = SAC_DAC_INIT;
    SAC_DAT = 1500;
    SAC_DAC |= DACEN;
    SAC_OA = SAC_OA_INIT;
#endif /* Microcontroller */
}

void dac_set_value(uint16_t value) {
#ifdef __MSP430FR2355__
    SAC_DAT = value;
#endif /* Microcontroller */
}
