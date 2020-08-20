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
#endif /* PL_IS_HELLO */

#if PL_IS_DEMO
    #define PL_HW_G2_LAUNCHPAD  (1)

    #define PL_HAS_UART         (1)
#endif /* PL_IS_DEMO */

#if PL_HW_G2_LAUNCHPAD
    #define PL_HAS_LED_RED      (1)
    #define PL_HAS_LED_GREEN    (1)
    #define PL_HAS_LED_BLUE     (1)
    #define PL_HAS_LED_YELLOW   (1)
    #define PL_HAS_LED_WHITE    (1)

    #define PL_HAS_SW           (1)
    #define PL_HAS_UART         (1)
    #define PL_HAS_I2C          (1)
#endif /* PL_HW_G2_LAUNCHPAD */

#endif /* PLATFORM_H_ */
