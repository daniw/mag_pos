/*
 * isr.h
 *
 *  Created on: 25.07.2020
 *      Author: daniw
 */

#ifndef ISR_H_
#define ISR_H_

#include <msp430.h>
#include <stdint.h>
#include "platform.h"
#include "gpio.h"
#if PL_HAS_UART
#include "uart.h"
#endif /* PL_HAS_UART */
#if PL_HAS_SPI
#include "spi.h"
#endif /* PL_HAS_SPI */
#if PL_HAS_INTERVAL
#include "interval.h"
#endif /* PL_HAS_INTERVAL */

#endif /* ISR_H_ */
