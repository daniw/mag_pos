/*
 * dac.c
 *
 *  Created on: 11.04.2021
 *      Author: alexh
 */

#include "dac.h"

#if PL_HAS_SAC

void init_dac(void) {
#ifdef __MSP430FR2355__
    PORT_SEL0(SAC_MODULE_A_PORT) |= SAC_MODULE_A_PIN;   // Select P3.1 as OA2O function
    PORT_SEL1(SAC_MODULE_A_PORT) |= SAC_MODULE_A_PIN;
    PORT_SEL0(SAC_MODULE_A_PORT) |= SAC_MODULE_A_PIN;   // Select P3.5 as OA3O function
    PORT_SEL1(SAC_MODULE_A_PORT) |= SAC_MODULE_A_PIN;

    SAC_DAC(SAC_MODULE_A)  = SAC_DAC_INIT;
    SAC_DAT(SAC_MODULE_A)  = 2048;
    SAC_DAC(SAC_MODULE_A) |= SAC_DAC_ENABLE;
    SAC_OA(SAC_MODULE_A)   = SAC_OA_INIT;
    SAC_PGA(SAC_MODULE_A)  = SAC_PGA_INIT;
    SAC_OA(SAC_MODULE_A)  |= SAC_OA_ENABLE;

    SAC_DAC(SAC_MODULE_B)  = SAC_DAC_INIT;
    SAC_DAT(SAC_MODULE_B)  = 2048;
    SAC_DAC(SAC_MODULE_B) |= SAC_DAC_ENABLE;
    SAC_OA(SAC_MODULE_B)   = SAC_OA_INIT;
    SAC_PGA(SAC_MODULE_B)  = SAC_PGA_INIT;
    SAC_OA(SAC_MODULE_B)  |= SAC_OA_ENABLE;

#endif /* Microcontroller */
}

void dac_set_value(uint8_t module, uint16_t value) {
#ifdef __MSP430FR2355__
    if (module == SAC_MODULE_A)
        SAC_DAT(SAC_MODULE_A) = value;
    else if (module == SAC_MODULE_B)
        SAC_DAT(SAC_MODULE_B) = value;
#endif /* Microcontroller */
}

#endif /* PL_HAS_SAC */
