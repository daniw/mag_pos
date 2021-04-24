/*
 * conversions.c
 *
 *  Created on: 10.04.2021
 *      Author: alexh
 */

#include "conversions.h"

// Calibration values linear axis
#pragma PERSISTENT(input_lin_lower)
uint16_t input_lin_lower = 500;
#pragma PERSISTENT(input_lin_upper)
uint16_t input_lin_upper = 2000;
#pragma PERSISTENT(output_lin_lower)
uint16_t output_lin_lower = 866;
#pragma PERSISTENT(output_lin_upper)
uint16_t output_lin_upper = 3305;

// Calibration values angular axis
#pragma PERSISTENT(input_rot_lower)
uint32_t input_rot_lower = 0;
#pragma PERSISTENT(input_rot_upper)
uint32_t input_rot_upper = 65500;
#pragma PERSISTENT(input_rot_middle)
uint32_t input_rot_middle = 32000;
#pragma PERSISTENT(output_rot_lower)
uint32_t output_rot_lower = 659;
#pragma PERSISTENT(output_rot_upper)
uint32_t output_rot_upper = 3471;
#pragma PERSISTENT(output_rot_middle)
uint32_t output_rot_middle = 2065;

uint16_t get_lower_lin(){
    return input_lin_lower;
}

uint16_t arctan_0_to_1_as_0_to_1024(uint16_t d) {
    // Returns: 0x2000 = 2^13 = 45°
    static const uint16_t arctan_lookup[65] = { 0x0000U, 0x00A3U, 0x0146U, 0x01E9U, 0x028BU,
                                                0x032DU, 0x03CFU, 0x0470U, 0x0511U, 0x05B1U,
                                                0x0651U, 0x06EFU, 0x078DU, 0x082AU, 0x08C6U,
                                                0x0961U, 0x09FBU, 0x0A94U, 0x0B2CU, 0x0BC2U,
                                                0x0C57U, 0x0CEBU, 0x0D7DU, 0x0E0FU, 0x0E9EU,
                                                0x0F2CU, 0x0FB9U, 0x1044U, 0x10CEU, 0x1156U,
                                                0x11DCU, 0x1261U, 0x12E4U, 0x1366U, 0x13E6U,
                                                0x1464U, 0x14E0U, 0x155BU, 0x15D5U, 0x164CU,
                                                0x16C2U, 0x1737U, 0x17AAU, 0x181BU, 0x188AU,
                                                0x18F8U, 0x1964U, 0x19CFU, 0x1A38U, 0x1A9FU,
                                                0x1B05U, 0x1B6AU, 0x1BCDU, 0x1C2EU, 0x1C8EU,
                                                0x1CEDU, 0x1D4AU, 0x1DA5U, 0x1DFFU, 0x1E58U,
                                                0x1EB0U, 0x1F06U, 0x1F5AU, 0x1FAEU, 0x2000U };
    uint8_t index = d >> 4;
    uint16_t lookup_value = arctan_lookup[index];
    if (index == 64)
        return lookup_value;
    uint16_t diff = arctan_lookup[index+1] - lookup_value;
    return lookup_value + ((diff * (d & 0b1111)) >> 4);
}

uint16_t arctan2(int16_t x, int16_t y) {
    // Returns: 0xFFFF = 2^16 = 360° --> 0x0000 - 0xFFFF
    uint32_t abs_x = abs(x);
    uint32_t abs_y = abs(y);
    if (abs_x == 0)
        abs_x = 1;
    if (abs_y == 0)
        abs_y = 1;

    if (x >= 0) {
        if (y >= 0) {
            if (x >= y) {
                return arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 16384 - arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        } else {
            if (x >= -y) {
                return 0 - arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 49152 + arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        }
    } else {
        if (y >= 0) {
            if (-x >= y) {
                return 32768 - arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 16384 + arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        } else {
            if (x <= y) {
                return 32768 + arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 49152 - arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        }
    }
}

uint16_t flux_squared_to_distance(uint32_t flux_squared) {
    static const uint16_t flux_lookup[128] = { 0xFFFFU, 0xDAD4U, 0xBB0EU, 0x9FE5U, 0x88AEU, 0x74D5U, 0x63DFU, 0x555EU, // 15 bits RH-Shift (Index 0-30)
                                               0x48F9U, 0x3E61U, 0x3552U, 0x2D94U, 0x26F6U, 0x214EU, 0x1C78U, 0x1855U,
                                               0x14CDU, 0x11C8U, 0x0F33U, 0x0CFEU, 0x0B1BU, 0x097EU, 0x081DU, 0x06EFU,
                                               0x05EEU, 0x0511U, 0x0455U, 0x03B4U, 0x032AU, 0x02B4U, 0x0250U,
                                               0xFD1DU, 0xD85CU, 0xB8F2U, 0x9E18U, 0x8723U, 0x7384U, 0x62BEU, 0x5468U, //  8 bits RH-Shift (Index 31-66)
                                               0x4826U, 0x3DADU, 0x34B8U, 0x2D10U, 0x2685U, 0x20EDU, 0x1C25U, 0x180FU,
                                               0x1491U, 0x1194U, 0x0F07U, 0x0CD8U, 0x0AFBU, 0x0963U, 0x0806U, 0x06DBU,
                                               0x05DCU, 0x0502U, 0x0448U, 0x03A9U, 0x0321U, 0x02ACU, 0x0249U, 0x01F4U,
                                               0x01ABU, 0x016DU, 0x0138U, 0x010BU,
                                               0xE46EU, 0xC344U, 0xA6EAU, 0x8EADU, 0x79F6U, 0x6841U, 0x591EU, 0x4C2DU, //         No Shift (Index 67-127)
                                               0x411EU, 0x37A9U, 0x2F94U, 0x28ACU, 0x22C4U, 0x1DB8U, 0x1967U, 0x15B7U,
                                               0x1290U, 0x0FDEU, 0x0D90U, 0x0B98U, 0x09E9U, 0x0879U, 0x073EU, 0x0631U,
                                               0x054BU, 0x0486U, 0x03DEU, 0x034EU, 0x02D3U, 0x026AU, 0x0210U, 0x01C4U,
                                               0x0182U, 0x014AU, 0x011AU, 0x00F1U, 0x00CEU, 0x00B0U, 0x0097U, 0x0081U,
                                               0x006EU, 0x005EU, 0x0050U, 0x0045U, 0x003BU, 0x0032U, 0x002BU, 0x0025U,
                                               0x001FU, 0x001BU, 0x0017U, 0x0014U, 0x0011U, 0x000EU, 0x000CU, 0x000AU,
                                               0x0009U, 0x0008U, 0x0007U, 0x0006U, 0x0005U };
    static const uint16_t dist_lookup[128] = { 0x00C8U, 0x00D0U, 0x00D8U, 0x00E1U, 0x00EAU, 0x00F3U, 0x00FDU, 0x0107U,
                                               0x0112U, 0x011DU, 0x0128U, 0x0134U, 0x0140U, 0x014DU, 0x015AU, 0x0168U,
                                               0x0177U, 0x0186U, 0x0195U, 0x01A5U, 0x01B6U, 0x01C8U, 0x01DAU, 0x01EDU,
                                               0x0201U, 0x0215U, 0x022AU, 0x0241U, 0x0258U, 0x0270U, 0x0289U, 0x02A3U,
                                               0x02BEU, 0x02DAU, 0x02F7U, 0x0315U, 0x0335U, 0x0356U, 0x0378U, 0x039BU,
                                               0x03C0U, 0x03E7U, 0x040FU, 0x0438U, 0x0463U, 0x0490U, 0x04BFU, 0x04F0U,
                                               0x0522U, 0x0557U, 0x058DU, 0x05C6U, 0x0601U, 0x063FU, 0x067FU, 0x06C1U,
                                               0x0706U, 0x074EU, 0x0799U, 0x07E7U, 0x0838U, 0x088CU, 0x08E4U, 0x093FU,
                                               0x099DU, 0x0A00U, 0x0A66U, 0x0AD1U, 0x0B3FU, 0x0BB3U, 0x0C2AU, 0x0CA7U,
                                               0x0D28U, 0x0DAFU, 0x0E3BU, 0x0ECDU, 0x0F65U, 0x1002U, 0x10A6U, 0x1151U,
                                               0x1202U, 0x12BAU, 0x137AU, 0x1442U, 0x1511U, 0x15E9U, 0x16C9U, 0x17B2U,
                                               0x18A5U, 0x19A1U, 0x1AA8U, 0x1BB9U, 0x1CD5U, 0x1DFCU, 0x1F2FU, 0x206EU,
                                               0x21BAU, 0x2314U, 0x247BU, 0x25F0U, 0x2775U, 0x2909U, 0x2AADU, 0x2C62U,
                                               0x2E29U, 0x3001U, 0x31EDU, 0x33ECU, 0x3600U, 0x3829U, 0x3A68U, 0x3CBEU,
                                               0x3F2CU, 0x41B3U, 0x4454U, 0x470FU, 0x49E7U, 0x4CDCU, 0x4FEFU, 0x5321U,
                                               0x5675U, 0x59EAU, 0x5D83U, 0x6140U, 0x6524U, 0x6930U, 0x6D65U, 0x71C5U };
    uint8_t upper, lower;
    uint8_t i;
    uint16_t flux_adjusted;
    if (flux_squared > (uint32_t)flux_lookup[31] << 8) {
        if (flux_squared > (uint32_t)flux_lookup[0] << 15)
            flux_squared = (uint32_t)flux_lookup[0] << 15;
        flux_adjusted = flux_squared >> 15;
        lower = 0;
        upper = 31;
    } else if (flux_squared > flux_lookup[67]) {
        flux_adjusted = flux_squared >> 8;
        lower = 31;
        upper = 67;
    } else {
        if (flux_squared < flux_lookup[127])
            flux_squared = flux_lookup[127];
        flux_adjusted = flux_squared;
        lower = 67;
        upper = 127;
    }

    do {
        i = lower + ((upper - lower) >> 1);
        if (flux_adjusted > flux_lookup[i]) {
            upper = i;
        } else if (flux_adjusted <= flux_lookup[i]) {
            lower = i;
        }
    } while (upper - lower > 1);

    uint16_t flux_high = flux_lookup[lower]; // The higher flux is the lower value.
    uint16_t flux_low = flux_lookup[upper];
    if (upper == 31) flux_low >>= 7;
    else if (upper == 67) flux_low >>= 8;
    uint16_t dist_low = dist_lookup[lower];
    uint16_t dist_high = dist_lookup[upper];
    uint16_t res = dist_low + ((uint32_t)(flux_high - flux_adjusted) * (dist_high - dist_low)) / (flux_high - flux_low);
    return res;
}

uint16_t get_lin_output(uint16_t distance) {
    if (distance < input_lin_lower)
        distance = input_lin_lower;
    else if (distance > input_lin_upper)
        distance = input_lin_upper;
    uint32_t dist_to_lower_input_times_width_output = (uint32_t)(distance - input_lin_lower) * (output_lin_upper - output_lin_lower);
    return output_lin_lower + (dist_to_lower_input_times_width_output / (input_lin_upper - input_lin_lower));
}

uint16_t get_rot_output(uint16_t angle) {
    if ((input_rot_middle >= 0x7FFF && angle < input_rot_middle && angle > input_rot_middle - 0x7FFF) ||
            input_rot_middle < 0x7FFF && (angle < input_rot_middle || angle > input_rot_middle + 0x7FFF)) {
        uint32_t rot_to_lower_input_times_lower_to_middle = (uint32_t)(angle - input_rot_lower) * (output_rot_middle - output_rot_lower);
        return output_rot_lower + (rot_to_lower_input_times_lower_to_middle / (input_rot_middle - input_rot_lower));
    } else {
        uint32_t rot_to_middle_input_times_middle_to_upper = (uint32_t)(angle - input_rot_middle) * (output_rot_upper - output_rot_middle);
        return output_rot_middle + (rot_to_middle_input_times_middle_to_upper / (input_rot_upper - input_rot_middle));
    }
}
