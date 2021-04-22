/*
 * platform.h
 *
 * Created on: 15.07.2020
 *     Author: daniw
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#if PL_IS_HELLO
    #define PL_HW_G2_LAUNCHPAD  (1)

    #define PL_HAS_UART         (0)
    #define PL_HAS_I2C          (0)
    #define PL_HAS_SPI          (0)
#endif /* PL_IS_HELLO */

#if PL_IS_DEMO
    #define PL_HW_G2_LAUNCHPAD  (1)

    #define PL_HAS_UART         (1)
    #define PL_HAS_I2C          (1)
    #define PL_HAS_SPI          (0)
#endif /* PL_IS_DEMO */

#if PL_IS_DEMO_FR
    #define PL_HW_FR2_LAUNCHPAD (1)

    #define PL_HAS_UART         (0)
    #define PL_HAS_I2C          (0)
    #define PL_HAS_SPI          (0)
#endif /* PL_IS_DEMO_FR */

#if PL_IS_MAG_POS_FR
    #define PL_HW_MAG_POS_V1    (1)

    #define PL_HAS_UART         (1)
    #define PL_HAS_I2C          (0)
    #define PL_HAS_SAC          (1)
    #define PL_HAS_SPI          (1)
#endif /* PL_IS_DEMO_FR */

#if PL_HW_G2_LAUNCHPAD
    #define PL_HAS_LED_RED      (1)
    #define PL_HAS_LED_GREEN    (1)
    #define PL_HAS_LED_BLUE     (1)
    #define PL_HAS_LED_YELLOW   (1)
    #define PL_HAS_LED_WHITE    (1)

    #define PL_HAS_SW0          (1)
#endif /* PL_HW_G2_LAUNCHPAD */

#if PL_HW_FR2_LAUNCHPAD
    #define PL_HAS_LED_RED      (1)
    #define PL_HAS_LED_GREEN    (1)
    #define PL_HAS_LED_BLUE     (1)
    #define PL_HAS_LED_YELLOW   (1)
    #define PL_HAS_LED_WHITE    (1)

    #define PL_HAS_SW0          (1)
    #define PL_HAS_SW1          (1)

    #define SPI_MODULE          B1
#endif /* PL_HW_FR2_LAUNCHPAD */

#if PL_HW_MAG_POS_V1
    #define PL_HAS_LED_RED      (1)
    #define PL_HAS_LED_GREEN    (1)
    #define PL_HAS_LED_BLUE     (1)
#endif /* PL_HW_MAG_POS_V1 */

#ifdef __MSP430G2553__
    #define PL_HAS_BASIC_CLOCK_MODULE_PLUS 1
#elif __MSP430FR2355__
    #define PL_HAS_CLOCK_SYSTEM 1
#else
    #error "No microcontroller selected of selected microcontroller not implemented yet"
#endif /* Microcontroller selection */

#endif /* PLATFORM_H_ */
