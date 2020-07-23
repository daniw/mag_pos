/*
 * mlx90393.h
 *
 * Created on: 17.07.2020
 *     Author: daniw
 */

#ifndef MLX90393_H_
#define MLX90393_H_

#include <msp430.h>
#include <stdint.h>
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
} test_bitfield_t;

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
        uint16_t data               : 16;           /*!< raw data */
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_conf_comm_t;
/*! \enum mlx90393_conf_comm_mode_t
 *  \brief Selection of communication mode
 */
typedef enum {
    MLX90393_CONF_COMM_MODE_CSSEL   =0x00, /*!< Communication mode is selected by CS pin */
    MLX90393_CONF_COMM_MODE_CSSEL_2 =0x01, /*!< Communication mode is selected by CS pin */
    MLX90393_CONF_COMM_MODE_SPI     =0x02, /*!< Communication mode is limited to SPI */
    MLX90393_CONF_COMM_MODE_I2C     =0x03, /*!< Communication mode is limited to I2C */
} mlx90393_conf_comm_mode_t;

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
        uint16_t data               : 13;           /*!< raw data */
        uint16_t reserved           :  3;           /*!< unused bits */
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
        uint16_t data               : 16;           /*!< raw data */
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
        uint16_t data               : 16;           /*!< raw data */
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
        uint16_t data               : 16;           /*!< raw data */
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
        uint16_t data               : 16;           /*!< raw data */
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
        uint16_t data               : 16;           /*!< raw data */
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
    uint8_t array[MLX90393_REG_WOZ_THRESHOLD_LEN];  /*!< array access */
    struct {
        uint16_t woz_threshold     : 16;            /*!< Wake-up On Change threshold for z-axis */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data              : 16;            /*!< raw data */
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
    uint8_t array[MLX90393_REG_WOT_THRESHOLD_LEN];  /*!< array access */
    struct {
        uint16_t wot_threshold     : 16;            /*!< Wake-up On Change threshold for temperature */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data              : 16;            /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_wot_threshold_t;

/*! /name free_0
 * @{
 */
#define MLX90393_REG_FREE_0_ADDR        0x0A
#define MLX90393_REG_FREE_0_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_0_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_0_t;

/*! /name free_1
 * @{
 */
#define MLX90393_REG_FREE_1_ADDR        0x0B
#define MLX90393_REG_FREE_1_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_1_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_1_t;

/*! /name free_2
 * @{
 */
#define MLX90393_REG_FREE_2_ADDR        0x0C
#define MLX90393_REG_FREE_2_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_2_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_2_t;

/*! /name free_3
 * @{
 */
#define MLX90393_REG_FREE_3_ADDR        0x0D
#define MLX90393_REG_FREE_3_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_3_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_3_t;

/*! /name free_4
 * @{
 */
#define MLX90393_REG_FREE_4_ADDR        0x0E
#define MLX90393_REG_FREE_4_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_4_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_4_t;

/*! /name free_5
 * @{
 */
#define MLX90393_REG_FREE_5_ADDR        0x0F
#define MLX90393_REG_FREE_5_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_5_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_5_t;

/*! /name free_6
 * @{
 */
#define MLX90393_REG_FREE_6_ADDR        0x10
#define MLX90393_REG_FREE_6_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_6_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_6_t;

/*! /name free_7
 * @{
 */
#define MLX90393_REG_FREE_7_ADDR        0x11
#define MLX90393_REG_FREE_7_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_7_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_7_t;

/*! /name free_8
 * @{
 */
#define MLX90393_REG_FREE_8_ADDR        0x12
#define MLX90393_REG_FREE_8_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_8_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_8_t;

/*! /name free_9
 * @{
 */
#define MLX90393_REG_FREE_9_ADDR        0x13
#define MLX90393_REG_FREE_9_LEN         2
/*! @} */
/*! \union mlx90393_reg_free_9_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_9_t;

/*! /name free_10
 * @{
 */
#define MLX90393_REG_FREE_10_ADDR       0x14
#define MLX90393_REG_FREE_10_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_10_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_10_t;

/*! /name free_11
 * @{
 */
#define MLX90393_REG_FREE_11_ADDR       0x15
#define MLX90393_REG_FREE_11_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_11_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_11_t;

/*! /name free_12
 * @{
 */
#define MLX90393_REG_FREE_12_ADDR       0x16
#define MLX90393_REG_FREE_12_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_12_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_12_t;

/*! /name free_13
 * @{
 */
#define MLX90393_REG_FREE_13_ADDR       0x17
#define MLX90393_REG_FREE_13_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_13_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_13_t;

/*! /name free_14
 * @{
 */
#define MLX90393_REG_FREE_14_ADDR       0x18
#define MLX90393_REG_FREE_14_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_14_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_14_t;

/*! /name free_15
 * @{
 */
#define MLX90393_REG_FREE_15_ADDR       0x19
#define MLX90393_REG_FREE_15_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_15_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_15_t;

/*! /name free_16
 * @{
 */
#define MLX90393_REG_FREE_16_ADDR       0x1a
#define MLX90393_REG_FREE_16_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_16_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_16_t;

/*! /name free_17
 * @{
 */
#define MLX90393_REG_FREE_17_ADDR       0x1b
#define MLX90393_REG_FREE_17_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_17_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_17_t;

/*! /name free_18
 * @{
 */
#define MLX90393_REG_FREE_18_ADDR       0x1c
#define MLX90393_REG_FREE_18_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_18_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_18_t;

/*! /name free_19
 * @{
 */
#define MLX90393_REG_FREE_19_ADDR       0x1d
#define MLX90393_REG_FREE_19_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_19_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_19_t;

/*! /name free_20
 * @{
 */
#define MLX90393_REG_FREE_20_ADDR       0x1e
#define MLX90393_REG_FREE_20_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_20_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_20_t;

/*! /name free_21
 * @{
 */
#define MLX90393_REG_FREE_21_ADDR       0x1f
#define MLX90393_REG_FREE_21_LEN        2
/*! @} */
/*! \union mlx90393_reg_free_21_t
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
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_reg_free_21_t;

/******************************************************************************
 * Commands
 *****************************************************************************/
/*! \name Measure commands
 *  \brief Set of commands to start a measurement or read mesurement data
 */
#define MLX90393_CMD_MEAS(mode, t, x, y, z)     ((MLX90393_MODE_##mode##_CMD << 4) | \
                                                (t?0x01:0x00) | \
                                                (x?0x02:0x00) | \
                                                (y?0x04:0x00) | \
                                                (z?0x08:0x00))
#define MLX90393_CMD_MEAS_LEN       1
#define MLX90393_CMD_BURST(t, x, y, z)     MLX90393_CMD_MEAS(BURST, t, x, y, z)
#define MLX90393_CMD_WAKEUP(t, x, y, z)    MLX90393_CMD_MEAS(WAKEUP, t, x, y, z)
#define MLX90393_CMD_SINGLE(t, x, y, z)    MLX90393_CMD_MEAS(SINGLE, t, x, y, z)
#define MLX90393_CMD_READ_MEAS(t, x, y, z) MLX90393_CMD_MEAS(READ, t, x, y, z)
#define MLX90393_CMD_BURST_LEN      MLX90393_CMD_MEAS_LEN
#define MLX90393_CMD_WAKEUP_LEN     MLX90393_CMD_MEAS_LEN
#define MLX90393_CMD_SINGLE_LEN     MLX90393_CMD_MEAS_LEN
#define MLX90393_CMD_READ_MEAS_LEN  MLX90393_CMD_MEAS_LEN
/* @} */
/*! \enum mlx90393_mode_t
 *  \brief Type to define the measurement mode
 */
typedef enum {
    MLX90393_MODE_BURST_CMD     = 0x1,      /*!< Burst mode */
    MLX90393_MODE_WAKEUP_CMD    = 0x2,      /*!< Wakeup mode */
    MLX90393_MODE_SINGLE_CMD    = 0x3,      /*!< Single mode */
    MLX90393_MODE_READ_CMD      = 0x4,      /*!< Read measurement */
} mlx90393_mode_t;
/*! \union mlx90393_cmd_meas_t
 *  \brief Start Measurement or read measurement data
 */
typedef union {
    uint8_t reg;                                    /*!< direct register access */
    uint8_t array[MLX90393_CMD_MEAS_LEN];           /*!< array access */
    struct {
        uint8_t t                   : 1;            /*!< Temperature */
        uint8_t x                   : 1;            /*!< X-axis */
        uint8_t y                   : 1;            /*!< Y-axis */
        uint8_t z                   : 1;            /*!< Z-axis */
        uint8_t mode                : 4;            /*!< Mode */
    } param;                                        /*!< parameter access */
    struct {
        uint8_t data                : 8;            /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_cmd_meas_t;

/*! \name Command RR
 *  \brief Command to read register
 */
#define MLX90393_CMD_RR(abc)        ((0x5 << 4) | ((abc) & 0x07))
#define MLX90393_CMD_RR_LEN         2
/* @} */
/*! \union mlx90393_cmd_rr_t
 *  \brief Read register
 */
typedef union {
    uint16_t reg;                                   /*! direct register access */
    uint8_t array[MLX90393_CMD_MEAS_LEN];           /*!< array access */
    struct {
        uint16_t reserved           : 2;            /*!< unused -> zero */
        uint16_t address            : 6;            /*!< register address */
        uint16_t abc                : 4;            /*!< abc -> always 0x00 for nromal read-out and write of the memory */
        uint16_t cmd                : 4;            /*!< Command */
    } param;                                        /*!< parameter access */
    struct {
        uint16_t data               : 16;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_cmd_rr_t;

/*! \name Command WR
 *  \brief Command to write register
 */
#define MLX90393_CMD_WR(abc)        ((0x6 << 4) | ((abc) & 0x07))
#define MLX90393_CMD_WR_LEN         4
/*! @} */
/*! \union mlx90393_cmd_wr_t
 *  \brief Read register
 */
typedef union {
    uint32_t reg;                                   /*! direct register access */
    uint8_t array[MLX90393_CMD_MEAS_LEN];           /*!< array access */
    struct {
        uint32_t reserved           : 2;            /*!< unused -> zero */
        uint32_t address            : 6;            /*!< register address */
        uint32_t data               : 16;           /*!< data to write to register */
        uint32_t abc                : 4;            /*!< abc -> always 0x00 for nromal read-out and write of the memory */
        uint32_t cmd                : 4;            /*!< Command */
    } param;                                        /*!< parameter access */
    struct {
        uint32_t data               : 32;           /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_cmd_wr_t;

/*! \name Command EX
 *  \brief Exit current mode
 */
#define MLX90393_CMD_EX             (0x8 << 4)
#define MLX90393_CMD_EX_LEN         1
/*! @} */

/*! \name Command HR
 *  \brief Memory recall from non-volatile mempry to volatile memory
 */
#define MLX90393_CMD_HR             (0xD << 4)
#define MLX90393_CMD_HR_LEN         1
/*! @} */

/*! \name Command HS
 *  \brief Memory store from volatile mempry to non-volatile memory
 */
#define MLX90393_CMD_HS             (0xE << 4)
#define MLX90393_CMD_HS_LEN         1
/*! @} */

/*! \name Command RT
 *  \brief Reset sensor
 */
#define MLX90393_CMD_RT             (0xF << 4)
#define MLX90393_CMD_RT_LEN         1
/*! @} */

/*! \name Status
 *  \brief Status byte
 */
#define MLX90393_STATUS_LEN         1
/*! @} */
/*! \union mlx90393_status_t
 *  \brief Status byte
 */
typedef union {
    uint8_t reg;                                    /*! direct register access */
    uint8_t array[MLX90393_STATUS_LEN];             /*!< array access */
    struct {
        uint8_t data_length         : 2;            /*!< Expected data length for RR and RM commands */
        uint8_t rs                  : 1;            /*!< Reset situation */
        uint8_t sed                 : 1;            /*!< Single error detection */
        uint8_t error               : 1;            /*!< Error */
        uint8_t mode_sm             : 1;            /*!< Single mode */
        uint8_t mode_woc            : 1;            /*!< Wake-up on change mode */
        uint8_t mode_burst          : 1;            /*!< Burst mode */
    } param;                                        /*!< parameter access */
    struct {
        uint8_t data                : 8;            /*!< raw data */
    } raw;                                          /*!< raw data access */
} mlx90393_status_t;

/******************************************************************************
 * Functions
 *****************************************************************************/
/*! \fn void mlx90393_init(void)
 *  \brief Initialisation function for MLX90393
 *
 *  \return void
 */
void mlx90393_init(void);

#endif /* MLX90393_H_ */
