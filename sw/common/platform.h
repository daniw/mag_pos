/*
 * platform.h
 *
 * Created on: 15.07.2020
 *     Author: daniw
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#define PL_IS_DEMO (1)

#if PL_IS_DEMO
    #define PL_HAS_LED_RED      (1)
    #define PL_HAS_LED_GREEN    (1)
    #define PL_HAS_LED_BLUE     (1)
    #define PL_HAS_LED_YELLOW   (1)
    #define PL_HAS_LED_WHITE    (1)

    #define PL_HAS_SW           (1)

    #define PL_HAS_UART         (1)

    #define PL_HAS_I2C          (1)
#endif

#endif /* PLATFORM_H_ */
