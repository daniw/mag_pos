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
        __bis_SR_register(SCG0);        // Disable FLL
        CSCTL3 = CSCTL3_INIT;           // Set FLL reference source
        CSCTL1 = CSCTL1_INIT;           // Set DCO range and enable DCO frequency trim
        CSCTL2 = CSCTL2_INIT;           // Set FLLN and FLLD for target frequency
        CSCTL5 = CSCTL5_INIT;           // Set MCLK and SMCLK divider
        __delay_cycles(3);              // Wait three clock cycles to allow settings to be applied
        __bic_SR_register(SCG0);        // Enable FLL
        clock_software_trim();          // Run software trim routine
        CSCTL4 = CSCTL4_INIT;           // Select MCLK and SMCLK source
        CSCTL6 = CSCTL6_INIT;           // ACLK divider and XT1 setup
    #endif /* Platform clock module */
    return;
}

/*! \fn clock_software_trim(void)
 *  \brief Software trim routine for FLL
 *
 *  This Routine performs a software trim as per MSP430FR2xxx / MSP430FR4xxx 
 *  Family User's Guide (SLAU445I). The algorithm used here is also documented 
 *  in the code example msp430fr235x_CS_07.c from Texas Instruments. 
 *
 *  In order to be able to precisely wait for 24 divided FLL reference clock 
 *  cycles, the MCLK source is switched to the FLL reference. The clock source 
 *  is restored after finishing software calibration. As the default DIVM 
 *  value is used to calculate the delay, the MCLK divider should not be lower 
 *  than initially defined before running this routine. 
 */
/*! \fn mlx90393_read(uint8_t *data)
 */
void clock_software_trim(void){
    uint16_t oldDcoTap = 0xffff;
    uint16_t newDcoTap = 0xffff;
    uint16_t newDcoDelta = 0xffff;
    uint16_t bestDcoDelta = 0xffff;
    uint16_t csctl0Best = 0;
    uint16_t csctl1Best = 0;
    uint16_t csctl4Copy = 0;
    uint16_t csctl0Read = 0;
    uint16_t csctl1Read = 0;
    uint16_t dcoFreqTrim = DCOFTRIM_INIT;
    uint8_t  endLoop = 0;

    csctl4Copy = CSCTL4;            // Store CSCTL4 value for later restoration
    if (CSCTL3 & SELREF) {          // Set MCLK source to FLLREF to enable precise delay when waiting for FLL to lock
        CSCTL4 = (CSCTL4 & (~SELMS)) | SELMS__REFOCLK;
    }
    else {
        CSCTL4 = (CSCTL4 & (~SELMS)) | SELMS__XT1CLK;
    };
    do {
        CSCTL0 = CSCTL0_INIT;       // Set DCO Tap to 256
        do {
            CSCTL7 &= ~DCOFFG;      // Clear DCO fault flag
        } while(CSCTL7 & DCOFFG);
        __delay_cycles((24*FLLREFDIV_VALUE+((1<<DIVM_INIT)-1))/(DIVM_INIT)); // Wait for FLL lock status to be stable. Minimum recommended waiting time: 24 cycles of divided FLLREFDIV
        while ((CSCTL7 & (FLLUNLOCK)) && ((CSCTL7 & DCOFFG) == 0)); // Wait for FLL to lock or for DCO fault
        csctl0Read = CSCTL0;
        csctl1Read = CSCTL1;
        oldDcoTap = newDcoTap;      // Store previous DCO tap
        newDcoTap = csctl0Read & DCOTAP;    // Get DCO Tap value
        dcoFreqTrim = csctl1Read & DCOFTRIM;    // Get FTRIM value
        if (newDcoTap < DCO_INIT){  // DCO running fast
            newDcoDelta = DCO_INIT - newDcoTap;  // Calculate current DCO tap deviation from optimal value
            if((oldDcoTap != 0xffff) && (oldDcoTap >= DCO_INIT)) {   // DCO tap crossed optimal value
                endLoop = 1;                    // Stop FTRIM iteration
            }
            else {
                dcoFreqTrim -= DCOFTRIM0;
                CSCTL = (csctl1Read & (~DCOFTRIM)) | dcoFreqTrim;
            }
        }
        else {                      // DCO running slow
            newDcoDelta = newDcoTap - 256;  // Calculate current DCO tap deviation from optimum value
            if (oldDcoTap < DCO_INIT) {   // DCO tap crossed optimal value
                endLoop = 1;                    // Stop FTRIM iteration
            }
            else {
                dcoFreqTrim += DCOFTRIM0;
                CSCTL = (csctl1Read & (~DCOFTRIM)) | dcoFreqTrim;
            }
        }
        if (newDcoDelta < bestDcoDelta) {   // Check if DCO tap is better than previously best DCO top value
            csctl0Best = csctl0Read;
            csctl1Best = csctl1Read;
            bestDcoDelta = newDcoDelta;
        }
    } while(endLoop == 0);          // Repeat until optimal DCOFTRIM value is found
    CSCTL4 &= csctl4Copy;           // Restore CSCTL4 to set MCLK source
    CSCTL0 = csctl0Best;            // Reload locked DCOTAP
    CSCTL1 = csctl1Best;            // Reload locked DCOFTRIM
    while(CSCTL7 & FLLUNLOCK);      // Wait until FLL is locked
    CSCTL7 &= ~FLLUNLOCKHIS;        // Clear FLL unlock history
    return;
}
