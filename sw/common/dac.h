/*
 * uart.h
 *
 *  Created on: 11.04.2021
 *      Author: alexh
 */

#ifndef DAC_H_
#define DAC_H_

#include <msp430.h>
#include <stdint.h>
#include "platform.h"
#include "conversions.h"

/* SAC/DAC configuration */
#ifndef SAC_ENABLED
    #define SAC_ENABLED                 1   // Should the SAC be enabled?
#endif /* SAC_ENABLED */
#ifndef DAC_SECONDARY_REFERENCE
    #define DAC_SECONDARY_REFERENCE     0   // Primary (0) or secondary (1) reference voltage?
#endif /* DAC_SECONDARY_REFERENCE */
#ifndef DAC_TRIGGER_SELECT
    #define DAC_TRIGGER_SELECT          0   // 0: Directly write, 1: Reserved, 2: TB2.1, 3: TB2.2
#endif /* DAC_TRIGGER_SELECT */
#ifndef DAC_DMA_REQUEST_ENABLED
    #define DAC_DMA_REQUEST_ENABLED     0   // DMA request enabled?
#endif /* DAC_DMA_REQUEST_ENABLED */
#ifndef DAC_INTERRUPT_ENABLED
    #define DAC_INTERRUPT_ENABLED       0   // DAC-interrupt enabled?
#endif /* DAC_INTERRUPT_ENABLED */
#ifndef DAC_ENABLED
    #define DAC_ENABLED                 1   // DAC enabled?
#endif /* DAC_ENABLED */

// ###### __MSP430FR2355__ ######
#ifdef __MSP430FR2355__

/* SAC module selection */
#if PL_IS_MAG_POS_FR
    #define SAC_MODULE 0
#endif /* PL_IS_DEMO */

/* SAC register redefinition */
/* OA */
#define SAC_OA_(module)         SAC_OA__(module)
#define SAC_OA__(module)        SAC##module##OA
#define SAC_OA                  SAC_OA_(SAC_MODULE)
/* PGA */
#define SAC_PGA_(module)        SAC_PGA__(module)
#define SAC_PGA__(module)       SAC##module##PGA
#define SAC_PGA                 SAC_PGA_(SAC_MODULE)
/* DAC */
#define SAC_DAC_(module)        SAC_DAC__(module)
#define SAC_DAC__(module)       SAC##module##DAC
#define SAC_DAC                 SAC_DAC_(SAC_MODULE)
/* DAT */
#define SAC_DAT_(module)        SAC_DAT__(module)
#define SAC_DAT__(module)       SAC##module##DAT
#define SAC_DAT                 SAC_DAT_(SAC_MODULE)
/* DACSTS */
#define SAC_DACSTS_(module)     SAC_DACSTS__(module)
#define SAC_DACSTS__(module)    SAC##module##DACSTS
#define SAC_DACSTS              SAC_DACSTS_(SAC_MODULE)
/* IV */
#define SAC_IV_(module)         SAC_IV__(module)
#define SAC_IV__(module)        SAC##module##IV
#define SAC_IV                  SAC_IV_(SAC_MODULE)

/* OA -> Basic SAC-OA setup */
#define SAC_OA_INIT             (SAC_ENABLED?SACEN:0x00)
/* PGA -> Basic SAC-PGA setup */
#define SAC_PGA_INIT            (0)
/* DAC -> Basic SAC-DAC setup */
#define SAC_DAC_INIT         ((DAC_SECONDARY_REFERENCE?DACSREF:0x00) | \
                             (DAC_TRIGGER_SELECT==2?DACLSEL_2:0x00) | \
                             (DAC_TRIGGER_SELECT==3?DACLSEL_3:0x00) | \
                             (DAC_DMA_REQUEST_ENABLED?DACDMAE:0x00) | \
                             (DAC_INTERRUPT_ENABLED?DACIE:0x00))


#endif /* Microcontroller */

void init_dac(void);
void dac_set_value(uint16_t value);

#endif /* UART_H_ */
