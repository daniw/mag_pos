/*
 * conversions.c
 *
 *  Created on: 10.04.2021
 *      Author: alexh
 */

#include "conversions.h"

uint16_t arctan_0_to_1_as_0_to_1024(uint16_t d) {
    // Returns: Degrees * 100
    static const uint16_t arctan_lookup[65] = { 0x0000U, 0x005AU, 0x00B3U, 0x010CU, 0x0166U,
                                                0x01BFU, 0x0218U, 0x0270U, 0x02C9U, 0x0320U,
                                                0x0378U, 0x03CFU, 0x0426U, 0x047CU, 0x04D2U,
                                                0x0527U, 0x057CU, 0x05D0U, 0x0623U, 0x0675U,
                                                0x06C7U, 0x0719U, 0x0769U, 0x07B9U, 0x0808U,
                                                0x0856U, 0x08A3U, 0x08EFU, 0x093BU, 0x0986U,
                                                0x09CFU, 0x0A18U, 0x0A61U, 0x0AA8U, 0x0AEEU,
                                                0x0B33U, 0x0B78U, 0x0BBBU, 0x0BFEU, 0x0C40U,
                                                0x0C81U, 0x0CC0U, 0x0CFFU, 0x0D3EU, 0x0D7BU,
                                                0x0DB7U, 0x0DF3U, 0x0E2DU, 0x0E67U, 0x0EA0U,
                                                0x0ED8U, 0x0F0FU, 0x0F45U, 0x0F7BU, 0x0FB0U,
                                                0x0FE3U, 0x1017U, 0x1049U, 0x107AU, 0x10ABU,
                                                0x10DBU, 0x110BU, 0x1139U, 0x1167U, 0x1194U };
    uint8_t index = d >> 4;
    uint16_t lookup_value = arctan_lookup[index];
    if (index == 64)
        return lookup_value;
    uint16_t diff = arctan_lookup[index+1] - lookup_value;
    return lookup_value + ((diff * (d & 0b1111)) >> 4);
}

uint16_t arctan2(int16_t x, int16_t y) {
    // Returns: Degrees * 100 from 0 to 36000
    uint32_t abs_x = abs(x);
    uint32_t abs_y = abs(y);

    if (x >= 0) {
        if (y >= 0) {
            if (x >= y) {
                return arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 9000 - arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        } else {
            if (x >= -y) {
                return 36000 - arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 27000 + arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        }
    } else {
        if (y >= 0) {
            if (-x >= y) {
                return 18000 - arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 9000 + arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        } else {
            if (x <= y) {
                return 18000 + arctan_0_to_1_as_0_to_1024((abs_y << 10) / abs_x);
            } else {
                return 27000 - arctan_0_to_1_as_0_to_1024((abs_x << 10) / abs_y);
            }
        }
    }
}
