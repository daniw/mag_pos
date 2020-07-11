/*
 * clock.h
 *
 * Created on: 03.07.2020
 *     Author: daniw
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <msp430.h>

#ifndef CLOCK_FREQ
    #define CLOCK_FREQ 1000000
#endif

#if CLOCK_FREQ == 1000000
    #define CALBC1_INIT CALBC1_1MHZ
    #define CALDCO_INIT CALDCO_1MHZ
#elif CLOCK_FREQ == 8000000
    #define CALBC1_INIT CALBC1_8MHZ
    #define CALDCO_INIT CALDCO_8MHZ
#elif CLOCK_FREQ == 12000000
    #define CALBC1_INIT CALBC1_12MHZ
    #define CALDCO_INIT CALDCO_12MHZ
#elif CLOCK_FREQ == 16000000
    #define CALBC1_INIT CALBC1_16MHZ
    #define CALDCO_INIT CALDCO_16MHZ
#else
    #error "Invalid DCO frequency selected. Check CLOCK_FREQ value. "
#endif

void init_clock(void);

#endif /* CLOCK_H_ */
