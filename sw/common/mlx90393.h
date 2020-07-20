/*
 * mlx90393.h
 *
 * Created on: 17.07.2020
 *     Author: daniw
 */

#ifndef MLX90393_H_
#define MLX90393_H_

#include <msp430.h>
#include "platform.h"

/******************************************************************************
 * Test compiler dependencies
 *****************************************************************************/
/*! \union test_bitfield_t
 *  \brief Type for testing the implementation of bitfields in the current compiler
 */
typedef union {
    struct {
        uint8_t low     : 4;    /*!< Low nibble */
        uint8_t high    : 4;    /*!< High nibble */
    } bitfield;                 /*!< Nibbles */
    uint8_t     byte;           /*!< Byte */
} test_bitfield_t

/******************************************************************************
 * Registers
 *****************************************************************************/
/*! /name conf_sensor
 * @{
 */
#define MLX90393_REG_CONF_SENSOR_ADDR       0x00
#define MLX90393_REG_CONF_SENSOR_LEN        2
/*! @} */
/*! \union mlx90393_reg_conf_sensor_t
 *  \brief Register CONF_SENSOR
 *  This register is used to configure the sensor funcionallity
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_CONF_SENSOR_LEN];    /*!< array access */
    struct {
        uint16_t hallconf           : 4;            /*!< Hall plate spinning rate adjustment */
        uint16_t gain_sel           : 3;            /*!< Analog chain gain setting */
        uint16_t z_series           : 1;            /*!< Enable all plates for Z-measurement */
        uint16_t bist               : 1;            /*!< Enabled the on-chip coil, apply a Z-field */
        uint16_t ana_res_low        : 7;            /*!< Reserved IO trimming bits */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_conf_sensor_t;

/*! /name conf_comm
 * @{
 */
#define MLX90393_REG_CONF_COMM_ADDR         0x01
#define MLX90393_REG_CONF_COMM_LEN          2
/*! @} */
/*! \union mlx90393_reg_conf_comm_t
 *  \brief Register CONF_COMM
 *  This register is used to configure the communication
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_CONF_COMM_LEN];      /*!< array access */
    struct {
        uint16_t burst_data_rate    : 6;            /*!< Defines TINTERVAL as BURST_DATA_RATE * 20ms */
        uint16_t burst_sel          : 4;            /*!< Defines the MDATA in burst mode if SB command argument = 0 */
        uint16_t tcmp_en            : 1;            /*!< Enables on-chip sensitivity drift compensation */
        uint16_t ext_trg            : 1;            /*!< Allows external trigger inputs when set, if TRIG_INT_SEL = 0 */
        uint16_t woc_diff           : 1;            /*!< Sets the Wake-up On Change based on Δ{sample(t),sample(t-1)} */
        uint16_t comm_mode          : 2;            /*!< Allow only SPI [10b], only I2C [11b] or both [0Xb] according to CS pin */
        uint16_t trig_int_sel       : 1;            /*!< Puts TRIG_INT pin in TRIG mode when cleared, INT mode otherwise */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_conf_sensor_t;

/*! /name  conf_adc
 * @{
 */
#define MLX90393_REG_CONF_ADC_ADDR          0x02
#define MLX90393_REG_CONF_ADC_LEN           2
/*! @} */
/*! \union mlx90393_reg_conf_adc_t
 *  \brief Register CONF_ADC
 *  This register is used to configure the ADC
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_CONF_ADC_LEN];       /*!< array access */
    struct {
        uint16_t osr                : 2;            /*!< Magnetic sensor ADC oversampling ratio */
        uint16_t dig_filt           : 3;            /*!< Digital filter applicable to ADC */
        uint16_t res_x              : 2;            /*!< Selects the desired 16-bit output value from the 19-bit ADC */
        uint16_t res_y              : 2;            /*!< Selects the desired 16-bit output value from the 19-bit ADC */
        uint16_t res_z              : 2;            /*!< Selects the desired 16-bit output value from the 19-bit ADC */
        uint16_t osr2               : 2;            /*!< Temperature sensor ADC oversampling ratio */
        uint16_t unused             : 3;            /*!< unused bits */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 13;                       /*!< raw data */
        uint16_t data   :  3;                       /*!< unused bits */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_conf_adc_t;

/*! /name sens_tc
 * @{
 */
#define MLX90393_REG_SENS_TC_ADDR           0x03
#define MLX90393_REG_SENS_TC_LEN            2
/*! @} */
/*! \union mlx90393_reg_sens_tc_t
 *  \brief Register SENS_TC
 *  This register is used to set the sensitivity drift compensation
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_SENS_TC_LEN];        /*!< array access */
    struct {
        uint16_t sens_tc_lt         : 8;            /*!< Sensitivity drift compensation factor for T > TREF */
        uint16_t sens_tc_ht         : 8;            /*!< Sensitivity drift compensation factor for T < TREF */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_sens_tc_t;

/*! /name offset_x
 * @{
 */
#define MLX90393_REG_OFFSET_X_ADDR          0x04
#define MLX90393_REG_OFFSET_X_LEN           2
/*! @} */
/*! \union mlx90393_reg_offset_x_t
 *  \brief Register OFFSET_X
 *  This register is used to set the constant offset for the x axis
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_OFFSET_X_LEN];       /*!< array access */
    struct {
        uint16_t offset_x           : 16;           /*!< Constant offset correction for the x-axis */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_offset_x_t;

/*! /name offset_y
 * @{
 */
#define MLX90393_REG_OFFSET_Y_ADDR          0x05
#define MLX90393_REG_OFFSET_Y_LEN           2
/*! @} */
/*! \union mlx90393_reg_offset_y_t
 *  \brief Register OFFSET_Y
 *  This register is used to set the constant offset for the y axis
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_OFFSET_Y_LEN];       /*!< array access */
    struct {
        uint16_t offset_y           : 16;           /*!< Constant offset correction for the y-axis */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_offset_y_t;

/*! /name offset_z
 * @{
 */
#define MLX90393_REG_OFFSET_Z_ADDR          0x06
#define MLX90393_REG_OFFSET_Z_LEN           2
/*! @} */
/*! \union mlx90393_reg_offset_z_t
 *  \brief Register OFFSET_Z
 *  This register is used to set the constant offset for the z axis
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_OFFSET_Z_LEN];       /*!< array access */
    struct {
        uint16_t offset_z           : 16;           /*!< Constant offset correction for the z-axis */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_offset_z_t;

/*! /name woxy_threshold
 * @{
 */
#define MLX90393_REG_WOXY_THRESHOLD_ADDR    0x07
#define MLX90393_REG_WOXY_THRESHOLD_LEN     2
/*! @} */
/*! \union mlx90393_reg_woxy_threshold_t
 *  \brief Register WOXY_THRESHOLD
 *  This register is used to set the wake-up on threshold for the x- and y-axis
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_WOXY_THRESHOLD_LEN]; /*!< array access */
    struct {
        uint16_t woxy_threshold     : 16;           /*!< Wake-up On Change threshold for x- and y-axis */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_woxy_threshold_t;

/*! /name woz_threshold
 * @{
 */
#define MLX90393_REG_WOZ_THRESHOLD_ADDR    0x08
#define MLX90393_REG_WOZ_THRESHOLD_LEN     2
/*! @} */
/*! \union mlx90393_reg_woz_threshold_t
 *  \brief Register WOZ_THRESHOLD
 *  This register is used to set the wake-up on threshold for the x- and y-axis
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_WOZ_THRESHOLD_LEN]; /*!< array access */
    struct {
        uint16_t woz_threshold     : 16;           /*!< Wake-up On Change threshold for z-axis */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_woz_threshold_t;

/*! /name wot_threshold
 * @{
 */
#define MLX90393_REG_WOT_THRESHOLD_ADDR    0x09
#define MLX90393_REG_WOT_THRESHOLD_LEN     2
/*! @} */
/*! \union mlx90393_reg_wot_threshold_t
 *  \brief Register WOT_THRESHOLD
 *  This register is used to set the wake-up on threshold for the x- and y-axis
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_WOT_THRESHOLD_LEN]; /*!< array access */
    struct {
        uint16_t wot_threshold     : 16;           /*!< Wake-up On Change threshold for temperature */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_wot_threshold_t;

/*! /name free_0
 * @{
 */
#define MLX90393_REG_FREE_0_ADDR        0x0A
#define MLX90393_REG_FREE_0_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_0
 *  \brief Register FREE_0
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_0_LEN];         /*!< array access */
    struct {
        uint16_t free_0             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_0;

/*! /name free_1
 * @{
 */
#define MLX90393_REG_FREE_1_ADDR        0x0B
#define MLX90393_REG_FREE_1_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_1
 *  \brief Register FREE_1
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_1_LEN];         /*!< array access */
    struct {
        uint16_t free_1             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_1;

/*! /name free_2
 * @{
 */
#define MLX90393_REG_FREE_2_ADDR        0x0C
#define MLX90393_REG_FREE_2_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_2
 *  \brief Register FREE_2
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_2_LEN];         /*!< array access */
    struct {
        uint16_t free_2             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_2;

/*! /name free_3
 * @{
 */
#define MLX90393_REG_FREE_3_ADDR        0x0D
#define MLX90393_REG_FREE_3_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_3
 *  \brief Register FREE_3
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_3_LEN];         /*!< array access */
    struct {
        uint16_t free_3             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_3;

/*! /name free_4
 * @{
 */
#define MLX90393_REG_FREE_4_ADDR        0x0E
#define MLX90393_REG_FREE_4_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_4
 *  \brief Register FREE_4
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_4_LEN];         /*!< array access */
    struct {
        uint16_t free_4             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_4;

/*! /name free_5
 * @{
 */
#define MLX90393_REG_FREE_5_ADDR        0x0F
#define MLX90393_REG_FREE_5_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_5
 *  \brief Register FREE_5
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_5_LEN];         /*!< array access */
    struct {
        uint16_t free_5             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_5;

/*! /name free_6
 * @{
 */
#define MLX90393_REG_FREE_6_ADDR        0x10
#define MLX90393_REG_FREE_6_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_6
 *  \brief Register FREE_6
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_6_LEN];         /*!< array access */
    struct {
        uint16_t free_6             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_6;

/*! /name free_7
 * @{
 */
#define MLX90393_REG_FREE_7_ADDR        0x11
#define MLX90393_REG_FREE_7_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_7
 *  \brief Register FREE_7
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_7_LEN];         /*!< array access */
    struct {
        uint16_t free_7             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_7;

/*! /name free_8
 * @{
 */
#define MLX90393_REG_FREE_8_ADDR        0x12
#define MLX90393_REG_FREE_8_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_8
 *  \brief Register FREE_8
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_8_LEN];         /*!< array access */
    struct {
        uint16_t free_8             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_8;

/*! /name free_9
 * @{
 */
#define MLX90393_REG_FREE_9_ADDR        0x13
#define MLX90393_REG_FREE_9_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_9
 *  \brief Register FREE_9
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_9_LEN];         /*!< array access */
    struct {
        uint16_t free_9             : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_9;

/*! /name free_10
 * @{
 */
#define MLX90393_REG_FREE_10_ADDR       0x14
#define MLX90393_REG_FREE_10_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_10
 *  \brief Register FREE_10
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_10_LEN];        /*!< array access */
    struct {
        uint16_t free_10            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_10;

/*! /name free_11
 * @{
 */
#define MLX90393_REG_FREE_11_ADDR       0x15
#define MLX90393_REG_FREE_11_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_11
 *  \brief Register FREE_11
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_11_LEN];        /*!< array access */
    struct {
        uint16_t free_11            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_11;

/*! /name free_12
 * @{
 */
#define MLX90393_REG_FREE_12_ADDR       0x16
#define MLX90393_REG_FREE_12_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_12
 *  \brief Register FREE_12
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_12_LEN];        /*!< array access */
    struct {
        uint16_t free_12            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_12;

/*! /name free_13
 * @{
 */
#define MLX90393_REG_FREE_13_ADDR       0x17
#define MLX90393_REG_FREE_13_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_13
 *  \brief Register FREE_13
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_13_LEN];        /*!< array access */
    struct {
        uint16_t free_13            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_13;

/*! /name free_14
 * @{
 */
#define MLX90393_REG_FREE_14_ADDR       0x18
#define MLX90393_REG_FREE_14_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_14
 *  \brief Register FREE_14
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_14_LEN];        /*!< array access */
    struct {
        uint16_t free_14            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_14;

/*! /name free_15
 * @{
 */
#define MLX90393_REG_FREE_15_ADDR       0x19
#define MLX90393_REG_FREE_15_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_15
 *  \brief Register FREE_15
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_15_LEN];        /*!< array access */
    struct {
        uint16_t free_15            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_15;

/*! /name free_16
 * @{
 */
#define MLX90393_REG_FREE_16_ADDR       0x1a
#define MLX90393_REG_FREE_16_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_16
 *  \brief Register FREE_16
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_16_LEN];        /*!< array access */
    struct {
        uint16_t free_16            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_16;

/*! /name free_17
 * @{
 */
#define MLX90393_REG_FREE_17_ADDR       0x1b
#define MLX90393_REG_FREE_17_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_17
 *  \brief Register FREE_17
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_17_LEN];        /*!< array access */
    struct {
        uint16_t free_17            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_17;

/*! /name free_18
 * @{
 */
#define MLX90393_REG_FREE_18_ADDR       0x1c
#define MLX90393_REG_FREE_18_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_18
 *  \brief Register FREE_18
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_18_LEN];        /*!< array access */
    struct {
        uint16_t free_18            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_18;

/*! /name free_19
 * @{
 */
#define MLX90393_REG_FREE_19_ADDR       0x1d
#define MLX90393_REG_FREE_19_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_19
 *  \brief Register FREE_19
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_19_LEN];        /*!< array access */
    struct {
        uint16_t free_19            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_19;

/*! /name free_20
 * @{
 */
#define MLX90393_REG_FREE_20_ADDR       0x1e
#define MLX90393_REG_FREE_20_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_20
 *  \brief Register FREE_20
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_20_LEN];        /*!< array access */
    struct {
        uint16_t free_20            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_20;

/*! /name free_21
 * @{
 */
#define MLX90393_REG_FREE_21_ADDR       0x1f
#define MLX90393_REG_FREE_21_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_21
 *  \brief Register FREE_21
 *  This register can be filled with customer content freely
 */
typedef union {
    uint16_t reg;                                   /*!< direct register access */
    uint8_t array[MLX90393_REG_FREE_21_LEN];        /*!< array access */
    struct {
        uint16_t free_21            : 16;           /*!< Can be filled with customer content freely */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data   : 16;                       /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_21;

/******************************************************************************
 * Commands
 *****************************************************************************/

#endif /* MLX90393_H_ */
