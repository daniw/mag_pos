/*
 * conversions.h
 *
 *  Created on: 10.04.2021
 *      Author: alexh
 */

#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>

uint16_t arctan_0_to_1_as_0_to_1024(uint16_t d);
uint16_t arctan2(int16_t x, int16_t y);

#endif /* CONVERSIONS_H_ */
