/*
 * clock.h
 *
 * Created on: 03.07.2020
 *     Author: daniw
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <msp430.h>
#include <stdint.h>
#include "platform.h"

/* Clock frequency selection */
#ifndef DCO_FREQ
    /* DCO clock frequency after FLLD divider */
    #define DCO_FREQ 7372800 /* Multiple by 2^n of baud rate (115200) */
#endif
#ifndef MCLK_FREQ
    #define MCLK_FREQ 7372800 /* Multiple by 2^n of baud rate (115200) */
#endif
#ifndef SMCLK_FREQ
    #define SMCLK_FREQ 7372800 /* Multiple by 2^n of baud rate (115200) */
#endif

#if PL_HAS_BASIC_CLOCK_MODULE_PLUS
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
#endif /* PL_HAS_BASIC_CLOCK_MODULE_PLUS */

#if PL_HAS_CLOCK_CLOCK_SYSTEM
    /* DCO Setup */
    #ifndef REFO_FREQ 
        #define REFO_FREQ 32768
    #endif /* REFO_FREQ  */
    #ifndef XT1_FREQ 
        #define XT1_FREQ 32768
    #endif /* XT1_FREQ  */
    #ifndef FLLSOURCE_XT1
        #define FLLSOURCE_XT1 0
    #endif /* FLLSOURCE_XT1 */
    #if FLLSOURCE_XT1
        #define SELREF_INIT 0
        #define FLL_REF_FREQ XT1_FREQ
    #elif
        #define SELREF_INIT 1
        #define FLL_REF_FREQ REFO_FREQ
    #endif /* FLLSOURCE_XT1 */
    #ifndef FLLREFDIV_VALUE 
        #define FLLREFDIV_VALUE 1 // Do not divide reference clock for FLL; Might need adjustment when using an external clock source
    #endif /* FLLREFDIV_VALUE  */
    #if FLLREFDIV_VALUE == 1
        #define FLLREFDIV_INIT FLLREFDIV__1
    #elif FLLREFDIV_VALUE == 32
        #define FLLREFDIV_INIT FLLREFDIV__32
    #elif FLLREFDIV_VALUE == 64
        #define FLLREFDIV_INIT FLLREFDIV__64
    #elif FLLREFDIV_VALUE == 128
        #define FLLREFDIV_INIT FLLREFDIV__128
    #elif FLLREFDIV_VALUE == 256
        #define FLLREFDIV_INIT FLLREFDIV__256
    #elif FLLREFDIV_VALUE == 512
        #define FLLREFDIV_INIT FLLREFDIV__512
    #elif FLLREFDIV_VALUE == 640
        #define FLLREFDIV_INIT FLLREFDIV__640
    #elif FLLREFDIV_VALUE == 768
        #define FLLREFDIV_INIT FLLREFDIV__768
    #else
        #error "Invalid FLL reference divider value. Check FLLREFDIV_VALUE"
    #endif /* FLLREFDIV_VALUE */
    #define FLLN_INIT ((DCO_FREQ + (FLL_REF_FREQ / FLLREFDIV_VALUE / 2)) / (FLL_REF_FREQ / FLLREFDIV_VALUE) - 1)
    #if ((FLLN_INIT < 0) || (FLLN_INIT > 1023))
        #error "FLLN value out of range"
    #endif /* FLL_INIT Range */
    /* DCO range selection */
    #define DCORSEL__1  DCORSEL_0
    #define DCORSEL__2  DCORSEL_1
    #define DCORSEL__4  DCORSEL_2
    #define DCORSEL__8  DCORSEL_3
    #define DCORSEL__12 DCORSEL_4
    #define DCORSEL__16 DCORSEL_5
    #define DCORSEL__20 DCORSEL_6
    #define DCORSEL__24 DCORSEL_7
    #if DCO_FREQ > 48200000
        #error "Internal DCO frequency too high!"
    #elif DCO_FREQ > 36100000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__24
        #warning "FLL might not be able to lock due to DCO frequency limit. (Too high)"
    #elif DCO_FREQ > 26500000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__24
    #elif DCO_FREQ > 21350000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__20
    #elif DCO_FREQ > 16300000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__16
    #elif DCO_FREQ > 11300000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__12
    #elif DCO_FREQ > 6200000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__8
    #elif DCO_FREQ > 3100000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__4
    #elif DCO_FREQ > 1550000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__2
    #elif DCO_FREQ > 750000
        #define FLLD_INIT FLLD__1
        #define DCORSEL_INIT DCORSEL__1
    #elif DCO_FREQ > 375000
        #define FLL_D_INIT FLLD__2
        #define DCORSEL_INIT DCORSEL__1
    #elif DCO_FREQ > 187500
        #define FLL_D_INIT FLLD__4
        #define DCORSEL_INIT DCORSEL__1
    #elif DCO_FREQ > 93750
        #define FLL_D_INIT FLLD__8
        #define DCORSEL_INIT DCORSEL__1
    #elif DCO_FREQ > 46875
        #define FLL_D_INIT FLLD__16
        #define DCORSEL_INIT DCORSEL__1
    #elif DCO_FREQ > 23438
        #define FLL_D_INIT FLLD__32
        #define DCORSEL_INIT DCORSEL__1
    #elif DCO_FREQ > 15625
        #define FLL_D_INIT FLLD__32
        #define DCORSEL_INIT DCORSEL__1
        #warning "FLL might not be able to lock due to DCO frequency limit. (Too low)"
    #else
        #error "Internal DCO frequency too low!"
    #endif /* DCO_FREQ */
    #define DCO_FREQ_ACTUAL (FLL_REF_FREQ * (FLLN_INIT + 1) / FLLREFDIV_VALUE)
    #if DCO_FREQ != DCO_FREQ_ACTUAL
        #warning "Actual DCO frequency does not match desired DCO frequency"
    #endif /* DCO_FREQ check */
    #define SELMS_INIT SELMS__DCOCLKDIV /* Only DCO as clock source for MCLK and SMCLK implemented yet */
    /* MCLK divider */
    #if DCO_FREQ == (MCLK_FREQ * 1)
        #define DIVM_INIT DIVM__1
    #elif DCO_FREQ == (MCLK_FREQ * 2)
        #define DIVM_INIT DIVM__2
    #elif DCO_FREQ == (MCLK_FREQ * 4)
        #define DIVM_INIT DIVM__4
    #elif DCO_FREQ == (MCLK_FREQ * 8)
        #define DIVM_INIT DIVM__8
    #elif DCO_FREQ == (MCLK_FREQ * 16)
        #define DIVM_INIT DIVM__16
    #elif DCO_FREQ == (MCLK_FREQ * 32)
        #define DIVM_INIT DIVM__32
    #elif DCO_FREQ == (MCLK_FREQ * 64)
        #define DIVM_INIT DIVM__64
    #elif DCO_FREQ == (MCLK_FREQ * 128)
        #define DIVM_INIT DIVM__128
    #else
        #error "MCLK can not be generated from DCO clock by division"
    #endif /* MCLK_FREQ */
    /* SMCLK divider */
    #if MCLK_FREQ == (SMCLK_FREQ * 1)
        #define DIVS_INIT DIVS__1
    #elif MCLK_FREQ == (SMCLK_FREQ * 2)
        #define DIVS_INIT DIVS__2
    #elif MCLK_FREQ == (SMCLK_FREQ * 4)
        #define DIVS_INIT DIVS__4
    #elif MCLK_FREQ == (SMCLK_FREQ * 8)
        #define DIVS_INIT DIVS__8
    #else
        #error "SMCLK can not be generated from MCLK by division"
    #endif /* SMCLK_FREQ */
    #define DCO_INIT 256 /* Set DCO tap to central value for software calibration */
    #define MOD_INIT 0 /* Set MOD to 0 for software calibration */
    #define DISMOD_INIT DISMOD_1 /* DISMOD=1 -> Modulation disabled for FLL operation */
    #define DCOFTRIM_INIT (DCOFTRIM0 | DCOFTRIM1) /* Set DCO FTRIM to a central value for the start of the software calibration */
    #define DCOFTRIMEN_INIT DCOFTRIMEN_1 /* Enable FTRIM */
    #define REFOLP_INIT REFOLP_0 /* REFO Low power mode disabled (High Power mode) */
    #define SELA_INIT SELA__REFOCLK /* REFO as reference for ACLK */
    #define SMCLKOFF_INIT SMCLKOFF_0
    #define VLOAUTOOFF_INIT VLOAUTOOFF_1
    #define XT1AUTOOFF_INIT XT1AUTOOFF_1 /* XT1 turned off when not used */
    #define XT1AGCOFF_INIT XT1AGCOFF_0 /* Automatic gain control enabled */
    #define XT1HFFREQ_INIT XT1HFFREQ_0 /* 1 to 4 MHz */
    #define XT1BYPASS_INIT XT1BYPASS_0 /* XT1 source internally */
    #define XTS_INIT XTS_0 /* Low frequency mode */
    #define XT1DRIVE_INIT XT1DRIVE_3 /* Highest drive strength */
    #define DIVA_INIT DIVA__768 /* Divider set to / 768 for ACLK */
    #define XT1FAULTOFF_INIT XT1AUTOOFF_0 /* Switch to REFLO when XT1 failure */
    /* CSCTL Register initial values */
    #define CSCTL0_INIT (DCO_INIT | MOD_INIT)
    #define CSCTL1_INIT (DISMOD_INIT | DCORSEL_INIT | DCOFTRIM_INIT | DCOFTRIMEN_INIT)
    #define CSCTL2_INIT (FLLN_INIT | FLLD_INIT)
    #define CSCTL3_INIT (FLLREFDIV_INIT | SELREF_INIT | REFOLP_INIT)
    #define CSCTL4_INIT (SELM_INIT | SELA_INIT)
    #define CSCTL5_INIT (DIVM_INIT | DIVS_INIT | SMCLKOFF_INIT | VLOAUTOOFF_INIT)
    #define CSCTL6_INIT (XT1AUTOOFF_INIT | XT1AGCOFF_INIT | XT1HFFREQ_INIT | XT1BYPASS_INIT | XTS_INIT | XT1DRIVE_INIT | DIVA_INIT | XT1FAULTOFF_INIT)
#endif /* PL_HAS_CLOCK_CLOCK_SYSTEM */

void init_clock(void);

void clock_software_trim(void);

#endif /* CLOCK_H_ */
