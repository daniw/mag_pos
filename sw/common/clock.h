/*
 * clock.h
 *
 * Created on: 03.07.2020
 *     Author: daniw
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <msp430.h>

/* Clock frequency selection */
#ifndef DCO_FREQ
    #define DCO_FREQ 8000000
#endif
#ifndef MCLK_FREQ
    #define MCLK_FREQ 8000000
#endif
#ifndef SMCLK_FREQ
    #define SMCLK_FREQ 1000000
#endif

/* DCO Setup */
#if DCO_FREQ == 1000000
    #define CALBC1_INIT CALBC1_1MHZ
    #define CALDCO_INIT CALDCO_1MHZ
#elif DCO_FREQ == 8000000
    #define CALBC1_INIT CALBC1_8MHZ
    #define CALDCO_INIT CALDCO_8MHZ
#elif DCO_FREQ == 12000000
    #define CALBC1_INIT CALBC1_12MHZ
    #define CALDCO_INIT CALDCO_12MHZ
#elif DCO_FREQ == 16000000
    #define CALBC1_INIT CALBC1_16MHZ
    #define CALDCO_INIT CALDCO_16MHZ
#else
    #error "Invalid DCO frequency selected. Check DCO_FREQ value. "
#endif

/* MCLK selection */
#define SELM_INIT SELM_0 // Use DCO as MCLK source
#if MCLK_FREQ == DCO_FREQ / 1
    #define DIVM_INIT DIVM_0 // Divider 1
#elif MCLK_FREQ == DCO_FREQ / 2
    #define DIVM_INIT DIVM_1 // Divider 2
#elif MCLK_FREQ == DCO_FREQ / 4
    #define DIVM_INIT DIVM_2 // Divider 4
#elif MCLK_FREQ == DCO_FREQ / 8
    #define DIVM_INIT DIVM_3 // Divider 8
#else
    #error "Invalid MCLK frequency selected. Check MCLK_FREQ and DCO_FREQ"
#endif

/* SMCLK selection */
#define SELS_INIT 0 // Use DCO as SMCLK source
#if SMCLK_FREQ == DCO_FREQ / 1
    #define DIVS_INIT DIVS_0 // Divider 1
#elif SMCLK_FREQ == DCO_FREQ / 2
    #define DIVS_INIT DIVS_1 // Divider 2
#elif SMCLK_FREQ == DCO_FREQ / 4
    #define DIVS_INIT DIVS_2 // Divider 4
#elif SMCLK_FREQ == DCO_FREQ / 8
    #define DIVS_INIT DIVS_3 // Divider 8
#else
    #error "Invalid SMCLK frequency selected. Check SMCLK_FREQ and DCO_FREQ"
#endif

#define BCSCTL2_INIT (SELM_INIT | DIVM_INIT | SELS_INIT | DIVS_INIT)

void init_clock(void);

#endif /* CLOCK_H_ */
