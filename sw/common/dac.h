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

/* SAC configuration */
// OA
#ifndef SAC_ENABLED
    #define SAC_ENABLED                 1   // Should the SAC be enabled?
#endif /* SAC_ENABLED */
#ifndef OA_LOW_POWER
    #define OA_LOW_POWER                1   // OA in low power mode?
#endif /* OA_LOW_POWER */
#ifndef OA_ENABLED
    #define OA_ENABLED                  1   // Should the OA be enabled?
#endif /* OA_ENABLED */
#ifndef SAC_NEGATIVE_MUX_CONNECTED
    #define SAC_NEGATIVE_MUX_CONNECTED  1   // All negative input sources are disconnected (0) / connected (1) to OA negative port
#endif /* SAC_NEGATIVE_MUX_CONNECTED */
#ifndef SAC_OA_NEGATIVE_SOURCE
    #define SAC_OA_NEGATIVE_SOURCE      1   // 0: External source, 1: PGA source, 2: Device Specific
#endif /* SAC_OA_NEGATIVE_SOURCE */
#ifndef SAC_POSITIVE_MUX_CONNECTED
    #define SAC_POSITIVE_MUX_CONNECTED  1   // All positive input sources are disconnected (0) / connected (1) to OA positive port
#endif /* SAC_POSITIVE_MUX_CONNECTED */
#ifndef SAC_OA_POSITIVE_SOURCE
    #define SAC_OA_POSITIVE_SOURCE      1   // 0: External source, 1: 12-bit reference DAC source, 2: Paired OA source
#endif /* SAC_OA_POSITIVE_SOURCE */
// PGA
#ifndef PGA_GAIN
    #define PGA_GAIN                    0   // Gain of the PGA
#endif /* PGA_GAIN */
#ifndef PGA_MODE
    #define PGA_MODE                    1   // 0: Inverting PGA, 1: Buffer, 2: Noninverting, 3: Cascade OA inverting
#endif /* PGA_MODE */
// DAC
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
    #define SAC_MODULE_A        2
    #define SAC_MODULE_A_PORT   3
    #define SAC_MODULE_A_PIN    1
    #define SAC_MODULE_B        3
    #define SAC_MODULE_B_PORT   3
    #define SAC_MODULE_B_PIN    5
#endif /* PL_IS_DEMO */

/* SAC register redefinition */
/* OA */
#define SAC_OA(module)          SAC_OA__(module)
#define SAC_OA__(module)        SAC##module##OA
/* PGA */
#define SAC_PGA(module)         SAC_PGA__(module)
#define SAC_PGA__(module)       SAC##module##PGA
/* DAC */
#define SAC_DAC(module)         SAC_DAC__(module)
#define SAC_DAC__(module)       SAC##module##DAC
/* DAT */
#define SAC_DAT(module)        SAC_DAT__(module)
#define SAC_DAT__(module)       SAC##module##DAT
/* DACSTS */
#define SAC_DACSTS(module)      SAC_DACSTS__(module)
#define SAC_DACSTS__(module)    SAC##module##DACSTS
/* IV */
#define SAC_IV(module)          SAC_IV__(module)
#define SAC_IV__(module)        SAC##module##IV

/* Port Selection 0 */
#define PORT_SEL0(port)         PORT_SEL0__(port)
#define PORT_SEL0__(port)       P##port##SEL0

/* Port Selection 1 */
#define PORT_SEL1(port)         PORT_SEL1__(port)
#define PORT_SEL1__(port)       P##port##SEL1


/* OA -> Basic SAC-OA setup */
#define SAC_OA_INIT             ((OA_LOW_POWER?OAPM:0x00) | \
                                 (SAC_NEGATIVE_MUX_CONNECTED?NMUXEN:0x00) | \
                                 (SAC_OA_NEGATIVE_SOURCE==1?NSEL_1:0x00) | \
                                 (SAC_OA_NEGATIVE_SOURCE==2?NSEL_2:0x00) | \
                                 (SAC_POSITIVE_MUX_CONNECTED?PMUXEN:0x00) | \
                                 (SAC_OA_POSITIVE_SOURCE==1?PSEL_1:0x00) | \
                                 (SAC_OA_POSITIVE_SOURCE==2?PSEL_2:0x00))
/* OA -> Enable SAC and OA */
#define SAC_OA_ENABLE           ((SAC_ENABLED?SACEN:0x00) | \
                                 (OA_ENABLED?OAEN:0x00))
/* PGA -> Basic SAC-PGA setup */
#define SAC_PGA_INIT            ((PGA_GAIN << 4) | \
                                 (PGA_MODE==1?MSEL_1:0x00) | \
                                 (PGA_MODE==2?MSEL_2:0x00) | \
                                 (PGA_MODE==3?MSEL_3:0x00))
/* DAC -> Basic SAC-DAC setup */
#define SAC_DAC_INIT            ((DAC_SECONDARY_REFERENCE?DACSREF:0x00) | \
                                 (DAC_TRIGGER_SELECT==2?DACLSEL_2:0x00) | \
                                 (DAC_TRIGGER_SELECT==3?DACLSEL_3:0x00) | \
                                 (DAC_DMA_REQUEST_ENABLED?DACDMAE:0x00) | \
                                 (DAC_INTERRUPT_ENABLED?DACIE:0x00))
/* DAC -> Enable DAC */
#define SAC_DAC_ENABLE          (DAC_ENABLED?DACEN:0x00)

#endif /* Microcontroller */

void init_dac(void);
void dac_set_value(uint8_t module, uint16_t value);

#endif /* UART_H_ */
