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

#define PARSER          0

#define SLEEPCNT_SLOW 65535
#define SLEEPCNT_FAST (SLEEPCNT_SLOW/8)

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
uint8_t c[1] = {0};
uint16_t checksum = 0;
uint8_t str[128];

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
    //init_spi(); // SPI initialized inside init_mlx90393
    #endif // PL_HAS_SPI
    init_mlx90393();
    __bis_SR_register(GIE);         // Enable global interrupts
    led_off();
    uint16_t counter = 0;

    uint8_t cmd[10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t data[sizeof(cmd)];
    uint8_t spi_retval;
    // RT
    cmd[0] = MLX90393_CMD_RT;
    spi_write(cmd, 1);
    do {
        spi_retval = spi_read(data, 1);
    } while (spi_retval);
    // HR
    cmd[0] = MLX90393_CMD_HR;
    spi_write(cmd, 2);
    do {
        spi_retval = spi_read(data, 2);
    } while (spi_retval);
    // Read memory
    uint8_t addr = 0;
    for (addr = 0; addr < 0x0A; addr++) {
        cmd[0] = MLX90393_CMD_RR(0);
        cmd[1] = addr << 2;
        spi_write(cmd, 5);
        do {
            spi_retval = spi_read(data, 5);
        } while (spi_retval);
    }
    cmd[1] = 0x00;
    // EX
    cmd[0] = MLX90393_CMD_EX;
    spi_write(cmd, 2);
    do {
        spi_retval = spi_read(data, 2);
    } while (spi_retval);
    /*// RT
    cmd[0] = MLX90393_CMD_RT;
    spi_write(cmd, 1);
    do {
        spi_retval = spi_read(data, 1);
    } while (spi_retval);*/

    LED_GREEN_ON();
    while(1)
    {
        #if PL_HAS_SPI
        // Single mode
        cmd[0] = MLX90393_CMD_SINGLE(1, 1, 1, 1);
        spi_write(cmd, 2);
        do {
            spi_retval = spi_read(data, 2);
        } while (spi_retval);

        cmd[0] = MLX90393_CMD_READ_MEAS(1, 1, 1, 1);
        LED_GREEN_TOGGLE();
        LED_RED_TOGGLE();
        sleep(SLEEPCNT_FAST*2);
        spi_write(cmd, 10);
        do {
            spi_retval = spi_read(data, 10);
        } while (spi_retval);
        #endif // PL_HAS_SPI

        #if PL_HAS_UART
            //uart_transmit(c, 1);
            c[0] += 1;
        #endif // PL_HAS_UART

        uint16_t temp = (data[2] << 8) + data[3];
        //int16_t flux_x = -32500+counter; //TODO
        int16_t flux_x = (data[4] << 8) + data[5];
        //int16_t flux_y = counter; //TODO
        int16_t flux_y = (data[6] << 8) + data[7];
        //int16_t flux_z = 0; //TODO
        int16_t flux_z = (data[8] << 8) + data[9];

        #if PL_HAS_UART
        #if PARSER
            uint8_t parsing = 1;
            uint8_t parse_state = 0;
            uint8_t parse_cnt = 0;
            uint8_t parse_chr = 0;
            int8_t parse_digit = 0;
            // Parse copy of variables
            uint16_t var_parse   = temp;
            while (parsing) {
                switch (parse_state) {
                    case 0: // T
                        parse_chr = 'T';
                        var_parse = temp;
                        parse_digit = 0;
                        parse_state++;
                        break;
                    case 1: // T parse
                    case 3: // X parse
                    case 5: // Y parse
                    case 7: // Z parse
                        if (parse_digit <= 0) {
                            if (var_parse < 0) {
                                parse_digit = -1;
                            } else if (var_parse >= 10000) {
                                parse_digit = 5;
                            } else if (var_parse >= 1000) {
                                parse_digit = 4;
                            } else if (var_parse >= 100) {
                                parse_digit = 3;
                            } else if (var_parse >= 10) {
                                parse_digit = 2;
                            } else if (var_parse >= 0) {
                                parse_digit = 1;
                            } else {
                            }
                        }
                        switch (parse_digit) {
                            case -1:
                                parse_chr = '-';
                                var_parse = -var_parse;
                                break;
                            case 5:
                                parse_chr = '0' + ((var_parse / 10000) % 100000);
                                var_parse = var_parse % 10000;
                                break;
                            case 4:
                                parse_chr = '0' + ((var_parse / 1000) % 10000);
                                var_parse = var_parse % 1000;
                                break;
                            case 3:
                                parse_chr = '0' + ((var_parse / 100) % 1000);
                                var_parse = var_parse % 100;
                                break;
                            case 2:
                                parse_chr = '0' + ((var_parse / 10) % 100);
                                var_parse = var_parse % 10;
                                break;
                            case 1:
                                parse_chr = '0' + ((var_parse / 1) % 10);
                                var_parse = 0;
                                parse_state++;
                                break;
                            default:
                                parse_chr = 'E';
                                parse_state++;
                        }
                        parse_digit--;
                        break;
                    case 2: // X
                        parse_chr = 'X';
                        var_parse = flux_x;
                        parse_digit = 0;
                        parse_state++;
                        break;
                    case 4: // Y
                        parse_chr = 'Y';
                        var_parse = flux_y;
                        parse_digit = 0;
                        parse_state++;
                        break;
                    case 6: // Z
                        parse_chr = 'Z';
                        var_parse = flux_z;
                        parse_digit = 0;
                        parse_state++;
                        break;
                    case 8: // EOL
                        parse_chr = '\n';
                        parsing = 0;
                        break;
                    default: //
                        parsing = 0;
                        break;
                }
                str[parse_cnt++] = parse_chr;
            }
            uart_transmit(str, parse_cnt);
        #endif // PARSER
        #endif // PL_HAS_UART
        // checksum to keep flux_z and temp from removed during optimization
        checksum = temp + flux_x + flux_y + flux_z;

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
}*/

void sleep(uint16_t sleepcnt){
    volatile uint16_t i;            // volatile to prevent optimization
    for(i=sleepcnt; i>0; i--);      // delay
    return;
}
