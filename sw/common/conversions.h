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

uint16_t flux_squared_to_distance(uint32_t flux_squared);

uint16_t get_lin_output(uint16_t distance);
uint16_t get_rot_output(uint16_t angle);

#endif /* CONVERSIONS_H_ */
