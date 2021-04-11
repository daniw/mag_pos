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

// Calibration values linear axis
#pragma PERSISTENT(output_lin_lower)
uint16_t output_lin_lower = 200;
#pragma PERSISTENT(output_lin_upper)
uint16_t output_lin_upper = 3500;
#pragma PERSISTENT(input_lin_lower)
uint16_t input_lin_lower = 500;
#pragma PERSISTENT(input_lin_upper)
uint16_t input_lin_upper = 2500;

// Calibration values angular axis
#pragma PERSISTENT(output_rot_lower)
uint32_t output_rot_lower = 400;
#pragma PERSISTENT(output_rot_upper)
uint32_t output_rot_upper = 3000;
#pragma PERSISTENT(output_rot_middle)
uint32_t output_rot_middle = 1600;
#pragma PERSISTENT(input_rot_lower)
uint32_t input_rot_lower = 700;
#pragma PERSISTENT(input_rot_upper)
uint32_t input_rot_upper = 2700;
#pragma PERSISTENT(input_rot_middle)
uint32_t input_rot_middle = 1750;

uint16_t arctan_0_to_1_as_0_to_1024(uint16_t d);
uint16_t arctan2(int16_t x, int16_t y);

uint16_t flux_squared_to_distance(uint32_t flux_squared);

uint16_t get_dac_lin_output(uint16_t distance);

#endif /* CONVERSIONS_H_ */
