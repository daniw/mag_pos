#include <msp430.h>
#include <stdint.h>

#include "platform.h"
#include "clock.h"
#include "gpio.h"
#include "uart.h"
#include "spi.h"
#include "mlx90393.h"
#include "conversions.h"
#include "dac.h"

#define SLEEPCNT_SLOW 65535
#define SLEEPCNT_FAST SLEEPCNT_SLOW/8

#define STATE_OFF       0
#define STATE_RED       1
#define STATE_GREEN     2
#define STATE_BLUE      3
#define STATE_YELLOW    4
#define STATE_WHITE     5

void sleep(uint16_t sleepcnt);
void led_ctrl();

/**
 * mag_pos.c
 */
uint16_t lin_output = 0;
uint16_t ang_output = 0;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer

    init_clock();
    init_gpio();
    PM5CTL0 &= ~LOCKLPM5;           // Disable the GPIO power-on default high-impedance mode
    #if PL_HAS_UART
    init_uart();
    #endif // PL_HAS_UART
    #if PL_HAS_SAC
    init_dac();
    #endif // PL_HAS_SAC
    #if PL_HAS_SPI
    init_spi();
    #endif // PL_HAS_SPI
    __bis_SR_register(GIE);         // Enable global interrupts
    led_off();
    uint16_t counter = 0;
    /*
    uint8_t cmd[10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t data[sizeof(cmd)];
    uint8_t spi_retval;
    // EX
    cmd[0] = 0x80; //EX
    spi_write(cmd, 2);
    do {
        spi_retval = spi_read(data, 2);
    } while (spi_retval);
    // RT
    cmd[0] = 0xf0; //EX
    spi_write(cmd, 1);
    do {
        spi_retval = spi_read(data, 1);
    } while (spi_retval);
    // SB
    cmd[0] = 0x1f;
    spi_write(cmd, 1);
    do {
        spi_retval = spi_read(data, 1);
    } while (spi_retval);
*/
    while(1)
    {/*
        #if PL_HAS_SPI
        cmd[0] = 0x4F;
        spi_write(cmd, 10);
        do {
            spi_retval = spi_read(data, 10);
        } while (spi_retval);
        #endif // PL_HAS_SPI
      */
        int16_t flux_x = -32500+counter; //TODO
        int16_t flux_y = counter; //TODO
        int16_t flux_z = 0; //TODO

        uint16_t angular_input = arctan2(flux_x, flux_y);
        uint32_t flux_squared = (uint32_t)abs(flux_x) * (uint32_t)abs(flux_x) + (uint32_t)abs(flux_y) * (uint32_t)abs(flux_y);
        uint16_t linear_input = flux_squared_to_distance(flux_squared);

        ang_output = get_rot_output(angular_input);
        lin_output = get_lin_output(linear_input);
        dac_set_value(SAC_MODULE_A, ang_output);
        dac_set_value(SAC_MODULE_B, lin_output);

        counter++;
        if (counter > 65000)
            counter = 0;
            //LED_GREEN_TOGGLE();
    }
}


/*
uint8_t* txt = (uint8_t *){ "Saali hoi! " };


#pragma PERSISTENT(c)
uint8_t c[1] = {97};

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer

    init_clock();
    init_gpio();
    PM5CTL0 &= ~LOCKLPM5;           // Disable the GPIO power-on default high-impedance mode

    #if PL_HAS_UART
    init_uart();
    #endif // PL_HAS_UART
    init_dac();
    #if PL_HAS_SPI
    init_spi();
    #endif // PL_HAS_SPI

    *c += 1;
    __bis_SR_register(GIE);         // Enable global interrupts
    led_off();
    uint8_t cmd[10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t data[sizeof(cmd)];
    uint8_t spi_retval;
    // EX
    cmd[0] = 0x80; //EX
    spi_write(cmd, 2);
    do {
        spi_retval = spi_read(data, 2);
    } while (spi_retval);
    // RT
    cmd[0] = 0xf0; //EX
    spi_write(cmd, 1);
    do {
        spi_retval = spi_read(data, 1);
    } while (spi_retval);
    // SB
    cmd[0] = 0x1f;
    spi_write(cmd, 1);
    do {
        spi_retval = spi_read(data, 1);
    } while (spi_retval);

    while(1)
    {
        #if PL_HAS_SPI
        spi_write(cmd, 10);
        do {
            spi_retval = spi_read(data, 10);
        } while (spi_retval);
        #endif // PL_HAS_SPI
        #if PL_HAS_UART
        uart_transmit(c, 1);
        #endif // PL_HAS_UART
        led_ctrl();

        // Sleep even longer...
        uint8_t j;
        for (j = 50; j > 0; j--) {
            sleep(SLEEPCNT_SLOW);
        }
    }
}

void led_ctrl(){
    static uint8_t state = 0;
    switch (state)
    {
    case STATE_OFF:
        led_off();
        dac_set_value(SAC_MODULE_A, 3460);
        dac_set_value(SAC_MODULE_B, 870);
        state++;
        break;
    #if // PL_HAS_LED_RED
    case STATE_RED:
        led_off();
        LED_RED_ON();
        dac_set_value(SAC_MODULE_A, 3000);
        dac_set_value(SAC_MODULE_B, 1444);
        state++;
        break;
    #endif // PL_HAS_LED_RED
    #if PL_HAS_LED_GREEN
    case STATE_GREEN:
        led_off();
        LED_GREEN_ON();
        dac_set_value(SAC_MODULE_A, 2065);
        dac_set_value(SAC_MODULE_B, 2500);
        state++;
        break;
    #endif // PL_HAS_LED_GREEN
    #if PL_HAS_LED_BLUE
    case STATE_BLUE:
        led_off();
        LED_BLUE_ON();
        dac_set_value(SAC_MODULE_A, 700);
        dac_set_value(SAC_MODULE_B, 3300);
        state++;
        break;
    #endif // PL_HAS_LED_BLUE
    #if PL_HAS_LED_YELLOW
    case STATE_YELLOW:
        led_off();
        LED_YELLOW_ON();
        state++;
        break;
    #endif // PL_HAS_LED_YELLOW
    #if PL_HAS_LED_WHITE
    case STATE_WHITE:
        led_off();
        LED_WHITE_ON();
        state++;
        break;
    #endif // PL_HAS_LED_WHITE
    default:
        led_off();
        state = STATE_OFF;
    }
}

void sleep(uint16_t sleepcnt){
    volatile uint16_t i;            // volatile to prevent optimization
    for(i=sleepcnt; i>0; i--);      // delay
    return;
}*/
