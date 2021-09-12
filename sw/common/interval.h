/*
 * interval.h
 *
 *  Created on: 24.08.2021
 *      Author: daniw
 */

#ifndef COMMON_INTERVAL_H_
#define COMMON_INTERVAL_H_

#include <msp430.h>
#include <stdint.h>
#include "platform.h"
#include "gpio.h"
#include "clock.h"

/* Timer module selection */
#if PL_HW_MAG_POS_V1
    #define INTERVAL_MODULE             B0
#endif /* PL_HW_MAG_POS_V1 */

/* Interval time selection */
#ifndef INTERVAL_USE_TIME
    #define INTERVAL_USE_TIME           1
#endif /* INTERVAL_USE_TIME */
#ifndef INTERVAL_USE_FREQ
    #define INTERVAL_USE_FREQ           0
#endif /* INTERVAL_USE_FREQ */
#ifndef INTERVAL_TIME_US /*            ,  ,  */
    #define INTERVAL_TIME_US            1000000
#endif /* INTERVAL_TIME_US */
#ifndef INTERVAL_FREQ
    #define INTERVAL_FREQ               100
#endif /* INTERVAL_FREQ */

/* Interval Timer configuration */
#ifndef INTERVAL_CLK_SRC_SMCLK
    #define INTERVAL_CLK_SRC_SMCLK      1
#endif /* INTERVAL_CLK_SRC_SMCLK */
#ifndef INTERVAL_CLK_SRC_ACLK
    #define INTERVAL_CLK_SRC_ACLK       0
#endif /* INTERVAL_CLK_SRC_ACLK */
#ifndef INTERVAL_CLK_SRC_TCLK
    #define INTERVAL_CLK_SRC_TCLK       0
#endif /* INTERVAL_CLK_SRC_TCLK */
#ifndef INTERVAL_CLK_SRC_INCLK
    #define INTERVAL_CLK_SRC_INCLK      0
#endif /* INTERVAL_CLK_SRC_INCLK */
#ifndef INTERVAL_TMR_LEN
    #define INTERVAL_TMR_LEN            16
#endif /* INTERVAL_TMR_LEN */
#define INTERVAL_PRESCALER1_MAX         8
#define INTERVAL_PRESCALER2_MAX         8

/* Interval timer mode of operation */
/* If no mode is selected, the driver will 
 * select the mode of operation automatically. */
#ifndef INTERVAL_TMR_MODE_STOP
    #define INTERVAL_TMR_MODE_STOP      0
#endif /* INTERVAL_TMR_MODE_STOP */
#ifndef INTERVAL_TMR_MODE_UP
    #define INTERVAL_TMR_MODE_UP        0
#endif /* INTERVAL_TMR_MODE_UP */
#ifndef INTERVAL_TMR_MODE_CONT
    #define INTERVAL_TMR_MODE_CONT      0
#endif /* INTERVAL_TMR_MODE_CONT */
#ifndef INTERVAL_TMR_MODE_UPDOWN
    #define INTERVAL_TMR_MODE_UPDOWN    0
#endif /* INTERVAL_TMR_MODE_UPDOWN */

/* Configuration validity check */
#if ((INTERVAL_USE_TIME + INTERVAL_USE_FREQ) > 1)
    #error "Multiple interval time definitions selected"
#endif /* Multiple interval time definitions */
#if ((INTERVAL_USE_TIME + INTERVAL_USE_FREQ) < 1)
    #error "No interval time definition selected"
#endif /* No interval time definition */
#if ((INTERVAL_CLK_SRC_SMCLK + INTERVAL_CLK_SRC_ACLK + INTERVAL_CLK_SRC_TCLK + INTERVAL_CLK_SRC_INCLK) > 1)
    #error "Multiple clock sources selected for Interval Timer module"
#endif /* Multiple clock sources */
#if ((INTERVAL_CLK_SRC_SMCLK + INTERVAL_CLK_SRC_ACLK + INTERVAL_CLK_SRC_TCLK + INTERVAL_CLK_SRC_INCLK) < 1)
    #error "No clock source selected for Interval Timer module"
#endif /* No clock sources */
#if ((INTERVAL_TMR_MODE_STOP + INTERVAL_TMR_MODE_UP + INTERVAL_TMR_MODE_CONT + INTERVAL_TMR_MODE_UPDOWN) > 1)
    #error "Multiple modes of operation selected for Interval Timer module"
#endif /* Multiple modes of operation */
//#if ((INTERVAL_TMR_MODE_STOP + INTERVAL_TMR_MODE_UP + INTERVAL_TMR_MODE_CONT + INTERVAL_TMR_MODE_UPDOWN) < 1)
//    #error " No mode of operation selected for Interval Timer module)
//#endif /* No mode of operation */

/* Timer register redefinition */
/* CTL */
#define INTERVAL_CTL_(module)       INTERVAL_CTL__(module)
#define INTERVAL_CTL__(module)      T##module##CTL
#define INTERVAL_CTL                INTERVAL_CTL_(INTERVAL_MODULE)
/* INTERVAL_CCTL0 */
#define INTERVAL_CCTL0_(module)     INTERVAL_CCTL0__(module)
#define INTERVAL_CCTL0__(module)    T##module##CCTL0
#define INTERVAL_CCTL0              INTERVAL_CCTL0_(INTERVAL_MODULE)
/* INTERVAL_CCTL1 */
#define INTERVAL_CCTL1_(module)     INTERVAL_CCTL1__(module)
#define INTERVAL_CCTL1__(module)    T##module##CCTL1
#define INTERVAL_CCTL1              INTERVAL_CCTL1_(INTERVAL_MODULE)
/* INTERVAL_CCTL2 */
#define INTERVAL_CCTL2_(module)     INTERVAL_CCTL2__(module)
#define INTERVAL_CCTL2__(module)    T##module##CCTL2
#define INTERVAL_CCTL2              INTERVAL_CCTL2_(INTERVAL_MODULE)
/* INTERVAL_CCTL3 */
#define INTERVAL_CCTL3_(module)     INTERVAL_CCTL3__(module)
#define INTERVAL_CCTL3__(module)    T##module##CCTL3
#define INTERVAL_CCTL3              INTERVAL_CCTL3_(INTERVAL_MODULE)
/* INTERVAL_CCTL4 */
#define INTERVAL_CCTL4_(module)     INTERVAL_CCTL4__(module)
#define INTERVAL_CCTL4__(module)    T##module##CCTL4
#define INTERVAL_CCTL4              INTERVAL_CCTL4_(INTERVAL_MODULE)
/* INTERVAL_CCTL5 */
#define INTERVAL_CCTL5_(module)     INTERVAL_CCTL5__(module)
#define INTERVAL_CCTL5__(module)    T##module##CCTL5
#define INTERVAL_CCTL5              INTERVAL_CCTL5_(INTERVAL_MODULE)
/* INTERVAL_CCTL6 */
#define INTERVAL_CCTL6_(module)     INTERVAL_CCTL6__(module)
#define INTERVAL_CCTL6__(module)    T##module##CCTL6
#define INTERVAL_CCTL6              INTERVAL_CCTL6_(INTERVAL_MODULE)
/* INTERVAL_R */
#define INTERVAL_R_(module)         INTERVAL_R__(module)
#define INTERVAL_R__(module)        T##module##R
#define INTERVAL_R                  INTERVAL_R_(INTERVAL_MODULE)
/* INTERVAL_CCR0 */
#define INTERVAL_CCR0_(module)      INTERVAL_CCR0__(module)
#define INTERVAL_CCR0__(module)     T##module##CCR0
#define INTERVAL_CCR0               INTERVAL_CCR0_(INTERVAL_MODULE)
/* INTERVAL_CCR1 */
#define INTERVAL_CCR1_(module)      INTERVAL_CCR1__(module)
#define INTERVAL_CCR1__(module)     T##module##CCR1
#define INTERVAL_CCR1               INTERVAL_CCR1_(INTERVAL_MODULE)
/* INTERVAL_CCR2 */
#define INTERVAL_CCR2_(module)      INTERVAL_CCR2__(module)
#define INTERVAL_CCR2__(module)     T##module##CCR2
#define INTERVAL_CCR2               INTERVAL_CCR2_(INTERVAL_MODULE)
/* INTERVAL_CCR3 */
#define INTERVAL_CCR3_(module)      INTERVAL_CCR3__(module)
#define INTERVAL_CCR3__(module)     T##module##CCR3
#define INTERVAL_CCR3               INTERVAL_CCR3_(INTERVAL_MODULE)
/* INTERVAL_CCR4 */
#define INTERVAL_CCR4_(module)      INTERVAL_CCR4__(module)
#define INTERVAL_CCR4__(module)     T##module##CCR4
#define INTERVAL_CCR4               INTERVAL_CCR4_(INTERVAL_MODULE)
/* INTERVAL_CCR5 */
#define INTERVAL_CCR5_(module)      INTERVAL_CCR5__(module)
#define INTERVAL_CCR5__(module)     T##module##CCR5
#define INTERVAL_CCR5               INTERVAL_CCR5_(INTERVAL_MODULE)
/* INTERVAL_CCR6 */
#define INTERVAL_CCR6_(module)      INTERVAL_CCR6__(module)
#define INTERVAL_CCR6__(module)     T##module##CCR6
#define INTERVAL_CCR6               INTERVAL_CCR6_(INTERVAL_MODULE)
/* INTERVAL_IV */
#define INTERVAL_IV_(module)        INTERVAL_IV__(module)
#define INTERVAL_IV__(module)       T##module##IV
#define INTERVAL_IV                 INTERVAL_IV_(INTERVAL_MODULE)
/* INTERVAL_EX0 */
#define INTERVAL_EX0_(module)       INTERVAL_EX0__(module)
#define INTERVAL_EX0__(module)      T##module##EX0
#define INTERVAL_EX0                INTERVAL_EX0_(INTERVAL_MODULE)
/* INTERVAL_VECTOR */
#define INTERVAL_VECTOR_(module)    INTERVAL_VECTOR__(module)
#define INTERVAL_VECTOR__(module)   T_##module##_VECTOR
#define INTERVAL_VECTOR             INTERVAL_VECTOR_(INTERVAL_MODULE)

/* Interval time calculation */
#define INTERVAL_US_PER_SECOND      1000000LL // Number of nanoseconds in a second
#if INTERVAL_CLK_SRC_SMCLK
    #define INTERVAL_CLK_FREQ       SMCLK_FREQ
#elif INTERVAL_CLK_SRC_ACLK
    #define INTERVAL_CLK_FREQ       ACLK_FREQ
#elif INTERVAL_CLK_SRC_TCLK
    #define INTERVAL_CLK_FREQ       TCLK_FREQ
#elif INTERVAL_CLK_SRC_INCLK
    #define INTERVAL_CLK_FREQ       INCLK_FREQ
#else
    #error "No Interval timer clock source selected"
#endif /* INTERVAL_CLK_SRC */

#if INTERVAL_USE_TIME
    #define INTERVAL_DIVIDER        ((INTERVAL_CLK_FREQ * INTERVAL_TIME_US + (INTERVAL_US_PER_SECOND/2)) / INTERVAL_US_PER_SECOND)
    #if ((INTERVAL_DIVIDER * INTERVAL_US_PER_SECOND) != (INTERVAL_CLK_FREQ * INTERVAL_TIME_US))
        #warning "Division ratio is not an integer, will be rounded to nearest integer value"
    #endif
#else /* INTERVAL_USE_TIME */
    #define INTERVAL_DIVIDER        ((INTERVAL_CLK_FREQ + (INTERVAL_FREQ/2)) / INTERVAL_FREQ)
    #if ((INTERVAL_DIVIDER * INTERVAL_FREQ) != INTERVAL_CLK_FREQ)
        #warning "Division ratio is not an integer, will be rounded to nearest integer value"
    #endif
#endif /* INTERVAL_USE_FREQ */

#if ((INTERVAL_TMR_MODE_STOP + INTERVAL_TMR_MODE_UP + INTERVAL_TMR_MODE_CONT + INTERVAL_TMR_MODE_UPDOWN) < 1)
    #if INTERVAL_DIVIDER > ((1<<(INTERVAL_TMR_LEN)) * INTERVAL_PRESCALER1_MAX * INTERVAL_PRESCALER2_MAX)
        #undef INTERVAL_TMR_MODE_UPDOWN
        #define INTERVAL_TMR_MODE_UPDOWN    1
        //#warning "Using up-down mode of operation"
    #else
        #undef INTERVAL_TMR_MODE_UP
        #define INTERVAL_TMR_MODE_UP        1
        //#warning "Using up mode of operation"
    #endif /* Up-down mode of operation required */
#endif /* No mode of operation */

#if INTERVAL_TMR_MODE_UPDOWN
    #define INTERVAL_TMR_MAX        ((1<<(INTERVAL_TMR_LEN))*2)
#else
    #define INTERVAL_TMR_MAX        (1<<(INTERVAL_TMR_LEN))
#endif /* INTERVAL_TMR_MODE_UPDOWN */
#if INTERVAL_DIVIDER > (INTERVAL_TMR_MAX * INTERVAL_PRESCALER1_MAX * INTERVAL_PRESCALER2_MAX)
    #error "Division ratio not achievable with interval timer"
#endif /* Timer length check */
/* Prescaler selection */
#define INTERVAL_PRESCALER_ITERATOR      2
#if INTERVAL_DIVIDER > INTERVAL_TMR_MAX
    /* Prescaler = 2 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  2
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 3 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  3
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 4 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  4
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 5 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  5
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 6 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  6
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 7 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  7
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 8 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  8
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 10 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  10
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 12 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  12
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 14 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  14
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 16 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  16
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 20 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  20
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 24 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  24
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 28 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  28
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 32 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  32
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 40 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  40
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 48 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  48
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 56 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  56
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
    /* Prescaler = 64 */
    #undef  INTERVAL_PRESCALER_ITERATOR
    #define INTERVAL_PRESCALER_ITERATOR  64
    #ifndef INTERVAL_PRESCALER_SELECTED
        #if INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) // Check if prescaler is already big enough
            #if ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) // Check if prescaler matches exactly to reach an integer CCR
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #undef INTERVAL_PRESCALER_TOTAL
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
                #define INTERVAL_PRESCALER_SELECTED         1
                #define INTERVAL_PRESCALER_TOTAL            INTERVAL_PRESCALER_ITERATOR
            #else
                #ifndef INTERVAL_PRESCALER_PRESELECTED // Check if prescaler has already been selected
                    #define INTERVAL_PRESCALER_PRESELECTED  1
                    #define INTERVAL_PRESCALER_TOTAL        INTERVAL_PRESCALER_ITERATOR
                #endif /* INTERVAL_PRESCALER_PRESELECTED */
            #endif /* ((INTERVAL_DIVIDER % INTERVAL_PRESCALER_ITERATOR) == 0) */
        #endif /* INTERVAL_DIVIDER <= (INTERVAL_TMR_MAX * INTERVAL_PRESCALER_ITERATOR) */
    #endif /* INTERVAL_PRESCALER_SELECTED */
#else
    #define INTERVAL_PRESCALER_SELECTED     1
    #define INTERVAL_PRESCALER_TOTAL        1
#endif /* INTERVAL_DIVIDER > INTERVAL_TMR_MAX */

#ifndef INTERVAL_PRESCALER_SELECTED
    #warning "No exactly matching prescaler could be found, interval time will not match requirement exactly"
#endif

#if INTERVAL_TMR_MODE_UPDOWN
    #define INTERVAL_TMR_VALUE  (INTERVAL_DIVIDER / INTERVAL_PRESCALER_TOTAL / 2)
    #if ((INTERVAL_TMR_VALUE * 2 * INTERVAL_PRESCALER_TOTAL) != INTERVAL_DIVIDER)
        #warning "Timer value cannot be chosen to match interval time exactly"
    #endif /* Timer value integer division check */
#else
    #define INTERVAL_TMR_VALUE  (INTERVAL_DIVIDER / INTERVAL_PRESCALER_TOTAL)
    #if ((INTERVAL_TMR_VALUE * INTERVAL_PRESCALER_TOTAL) != INTERVAL_DIVIDER)
        #warning "Timer value cannot be chosen to match interval time exactly"
    #endif /* Timer value integer division check */
#endif /* INTERVAL_TMR_MODE_UPDOWN */

#define INTERVAL_R_INIT         0

#define INTERVAL_TBCLGRP_INIT   TBCLGRP_0   // Each TBxCLn loads independently
#if INTERVAL_TMR_LEN == 8
    #define INTERVAL_CNTL_INIT  CNTL__8
#elif INTERVAL_TMR_LEN == 10
    #define INTERVAL_CNTL_INIT  CNTL__10
#elif INTERVAL_TMR_LEN == 12
    #define INTERVAL_CNTL_INIT  CNTL__12
#elif INTERVAL_TMR_LEN == 16
    #define INTERVAL_CNTL_INIT  CNTL__16
#else
    #error "Invalid interval timer length"
#endif
#if INTERVAL_CLK_SRC_SMCLK
    #define INTERVAL_TBSSEL_INIT    TBSSEL__SMCLK
#elif INTERVAL_CLK_SRC_ACLK
    #define INTERVAL_TBSSEL_INIT    TBSSEL__ACLK
#elif INTERVAL_CLK_SRC_TCLK
    #define INTERVAL_TBSSEL_INIT    TBSSEL__TBCLK
#elif INTERVAL_CLK_SRC_INCLK
    #define INTERVAL_TBSSEL_INIT    TBSSEL__INCLK
#else
    #error "No Interval timer clock source selected"
#endif /* INTERVAL_CLK_SRC */
#if   INTERVAL_PRESCALER_TOTAL == 1
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__1   // 1
#elif INTERVAL_PRESCALER_TOTAL == 2
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__2   // 2
#elif INTERVAL_PRESCALER_TOTAL == 3
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__3   // 3
#elif INTERVAL_PRESCALER_TOTAL == 4
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__4   // 4
#elif INTERVAL_PRESCALER_TOTAL == 5
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__5   // 5
#elif INTERVAL_PRESCALER_TOTAL == 6
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__6   // 6
#elif INTERVAL_PRESCALER_TOTAL == 7
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__7   // 7
#elif INTERVAL_PRESCALER_TOTAL == 8
    #define INTERVAL_ID_INIT    ID__1       // 1
    #define INTERVAL_IDEX_INIT  TBIDEX__8   // 8
#elif INTERVAL_PRESCALER_TOTAL == 10
    #define INTERVAL_ID_INIT    ID__2       // 2
    #define INTERVAL_IDEX_INIT  TBIDEX__5   // 5
#elif INTERVAL_PRESCALER_TOTAL == 12
    #define INTERVAL_ID_INIT    ID__2       // 2
    #define INTERVAL_IDEX_INIT  TBIDEX__6   // 6
#elif INTERVAL_PRESCALER_TOTAL == 14
    #define INTERVAL_ID_INIT    ID__2       // 2
    #define INTERVAL_IDEX_INIT  TBIDEX__7   // 7
#elif INTERVAL_PRESCALER_TOTAL == 16
    #define INTERVAL_ID_INIT    ID__2       // 2
    #define INTERVAL_IDEX_INIT  TBIDEX__8   // 8
#elif INTERVAL_PRESCALER_TOTAL == 20
    #define INTERVAL_ID_INIT    ID__4       // 4
    #define INTERVAL_IDEX_INIT  TBIDEX__5   // 5
#elif INTERVAL_PRESCALER_TOTAL == 24
    #define INTERVAL_ID_INIT    ID__4       // 4
    #define INTERVAL_IDEX_INIT  TBIDEX__6   // 6
#elif INTERVAL_PRESCALER_TOTAL == 28
    #define INTERVAL_ID_INIT    ID__4       // 4
    #define INTERVAL_IDEX_INIT  TBIDEX__7   // 7
#elif INTERVAL_PRESCALER_TOTAL == 32
    #define INTERVAL_ID_INIT    ID__4       // 4
    #define INTERVAL_IDEX_INIT  TBIDEX__8   // 8
#elif INTERVAL_PRESCALER_TOTAL == 40
    #define INTERVAL_ID_INIT    ID__8       // 8
    #define INTERVAL_IDEX_INIT  TBIDEX__5   // 5
#elif INTERVAL_PRESCALER_TOTAL == 48
    #define INTERVAL_ID_INIT    ID__8       // 8
    #define INTERVAL_IDEX_INIT  TBIDEX__6   // 6
#elif INTERVAL_PRESCALER_TOTAL == 56
    #define INTERVAL_ID_INIT    ID__8       // 8
    #define INTERVAL_IDEX_INIT  TBIDEX__7   // 7
#elif INTERVAL_PRESCALER_TOTAL == 64
    #define INTERVAL_ID_INIT    ID__8       // 8
    #define INTERVAL_IDEX_INIT  TBIDEX__8   // 8
#else
    #error "Invalid Prescaler value"
#endif
#if INTERVAL_TMR_MODE_STOP
    #define INTERVAL_MC_INIT    MC__STOP
#elif INTERVAL_TMR_MODE_UP
    #define INTERVAL_MC_INIT    MC__UP
#elif INTERVAL_TMR_MODE_CONT
    #define INTERVAL_MC_INIT    MC__CONTINUOUS
#elif INTERVAL_TMR_MODE_UPDOWN
    #define INTERVAL_MC_INIT    MC__UPDOWN
#else
    #error "No timer mode of operation selected"
#endif /* INTERVAL_TMR_MODE */
#define INTERVAL_TBCLR_INIT     0
#define INTERVAL_TBIE_INIT      TBIE_1
#define INTERVAL_TBIFG_INIT     TBIFG_0
#define INTERVAL_CTL_INIT       (INTERVAL_TBCLGRP_INIT | \\
                                 INTERVAL_CNTL_INIT | \\
                                 INTERVAL_TBSSEL_INIT | \\
                                 INTERVAL_ID_INIT | \\
                                 INTERVAL_MC_INIT | \\
                                 INTERVAL_TBCLR_INIT | \\
                                 INTERVAL_TBIE_INIT | \\
                                 INTERVAL_TBIFG_INIT)

#define INTERVAL_TBEX0_INIT     INTERVAL_IDEX_INIT

#if ((INTERVAL_TMR_VALUE < (1<<16)) & (INTERVAL_TMR_VALUE > 0))
    #define INTERVAL_CCR0_INIT  INTERVAL_TMR_VALUE
#else
    #error "Invalid interval timer CCR0 value"
#endif /* INTERVAL_TMR_VALUE < (2^16) */
#define INTERVAL_CCR1_INIT      0
#define INTERVAL_CCR2_INIT      0
#define INTERVAL_CCR3_INIT      0
#define INTERVAL_CCR4_INIT      0
#define INTERVAL_CCR5_INIT      0
#define INTERVAL_CCR6_INIT      0

#define INTERVAL_CCTL0_INIT     0
#define INTERVAL_CCTL1_INIT     0
#define INTERVAL_CCTL2_INIT     0
#define INTERVAL_CCTL3_INIT     0
#define INTERVAL_CCTL4_INIT     0
#define INTERVAL_CCTL5_INIT     0
#define INTERVAL_CCTL6_INIT     0

//#define PREPROCESSOR_OUTPUT     INTERVAL_PRESCALER_TOTAL
//#include "preprocessor_output.h"
//
//#if defined(__GNUC__)
//#pragma message(VAR_NAME_VALUE(INTERVAL_PRESCALER_TOTAL))
//#endif

/* IE */
#define INTERVAL_IE_INIT     ((SPI_RX_INTERRUPT?UCRXIE:0) | \
                         (SPI_TX_INTERRUPT?UCTXIE:0))

void init_interval(void);
void interval_isr(void);

#endif /* COMMON_INTERVAL_H_ */
