/*
 * mlx90393.c
 *
 * Created on: 17.07.2020
 *     Author: daniw
 */

#include "mlx90393.h"

/*
 * Definition of I/O functions
 */
/*! \fn mlx90393_write(uint8_t *data)
 */
void mlx90393_write(uint8_t *data) {
    #if PL_HAS_I2C
        // \todo Add I2C write function here!!
    #endif /* PL_HAS_I2C */
    #if PL_HAS_SPI
        // \todo Add SPI write function here!!
    #endif /* PL_HAS_SPI */
    #if PL_PC
        printf("write: 0x%X\n", *data);
    #endif /* PL_PC */
    return;
}

/*! \fn mlx90393_read(uint8_t *data)
 */
void spi_read(uint8_t *data) {
    #if PL_HAS_I2C
        // \todo Add I2C write function here!!
        *data = 0x00;
    #endif /* PL_HAS_I2C */
    #if PL_HAS_SPI
        // \todo Add SPI write function here!!
        *data = 0x00;
    #endif /* PL_HAS_SPI */
    #if PL_PC
        // unsigned int readdata;
        printf("read: \n");
        \\scanf("%X", &readdata);
        //*data = (uint8_t) *readdata;
        *data = 0x00;
    #endif /* PL_PC */
}

void mlx90393_init(void) {
    /* test orientation of bitfields */
    test_bitfield_t test_bitfield;      /* testvariable */
    test_bitfield.byte = 0x00;
    test_bitfield.bitfield.low = 0x01;  /* write testvalue to lower nibble */
    if (test_bitfield.byte != 0x01) {   /* test if lower nibble has been written */
        while (1) {
            /* Hey Programmer
             * It seems that your compiler uses a 
             * different order for bitfields than mine. 
             * If you still want to use this library, 
             * change, if possible, the order of bitfields in 
             * your compiler or in this library!
             */
        }
    }
    return;
}
