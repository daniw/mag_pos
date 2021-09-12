/*
 * mlx90393.c
 *
 * Created on: 17.07.2020
 *     Author: daniw
 */

#include "mlx90393.h"

// RX and TX buffers
uint8_t mlx_rx_buffer_[9];
uint8_t mlx_tx_buffer_[4];
uint8_t *mlx90393_rx_buffer_pointer_;
uint8_t *mlx90393_tx_buffer_pointer_;
uint8_t mlx90393_rx_counter_;
uint8_t mlx90393_tx_counter_;
uint8_t mlx_rx_count_;
uint8_t mlx_tx_count_;

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
void mlx90393_read(uint8_t *data) {
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

void mlx90393_communicate(uint8_t *txData, uint8_t txCount, uint8_t *rxData, uint8_t rxCount) {
    #if PL_HAS_I2C
        mlx_rx_count_ = rxCount;
        mlx_tx_count_ = txCount;
        while (I2C_CTL1 & UCTXSTP);                         // Ensure stop condition got sent
        mlx90393_tx_buffer_pointer_ = (uint8_t *) txData;
        mlx90393_rx_buffer_pointer_ = (uint8_t *) rxData;
        mlx90393_tx_counter_ = txCount;
        mlx90393_rx_counter_ = rxCount;
        I2C_CTL1 |= UCTR + UCTXSTT;                         // I2C TX, start condition
    #endif /* PL_HAS_I2C */
    #if PL_HAS_SPI
        // \todo Add SPI write function here!!
        *rxData = 0x00;
    #endif /* PL_HAS_SPI */
}

#if PL_HAS_I2C
void mlx90393_i2c_tx_interrupt() {
    if (mlx90393_tx_counter_--) {                       // Check TX byte counter and decrease after
        I2C_TXBUF = *mlx90393_tx_buffer_pointer_++;     // Write next Byte into TX-buffer
    } else {                                            // If finished ...
        I2C_CTL1 &= ~UCTR;                              // Disable transmit flag --> Enables receive mode
        I2C_CTL1 |= UCTXSTT;                            // I2C repeated start condition
        if(mlx90393_rx_counter_ == 1) {                 // If only one byte should be received, the stop condition has to be sent immediately after start condition
            while (I2C_CTL1 & UCTXSTT);                 // Start condition sent?
            I2C_CTL1 |= UCTXSTP;                        // I2C stop condition
        }
    }
}

void mlx90393_i2c_rx_interrupt() {
    if (mlx90393_rx_counter_ == 1) {                    // Last byte to receive
        *mlx90393_rx_buffer_pointer_ = I2C_RXBUF;       // Move final byte into rx-buffer
        uart_transmit(mlx_rx_buffer_, mlx_rx_count_);
    } else {
        *mlx90393_rx_buffer_pointer_++ = I2C_RXBUF;     // Move byte into rx-buffer
        if (mlx90393_rx_counter_ == 2)                  // Check whether byte is second to last to be read to send stop condition
            I2C_CTL1 |= UCTXSTP;                        // Send I2C stop condition
    }
    mlx90393_rx_counter_--;                             // Decrement RX byte counter
}
#endif // PL_HAS_I2C

void init_mlx90393(void) {
    #if PL_HAS_I2C
        I2C_CS_DIR |= I2C_CS_PIN;                   // Define CS-pin as output
        I2C_CS_OUT |= I2C_CS_PIN;                   // Set CS high to activate I2C mode on MLX90393
        P1SEL |= I2C_SCL + I2C_SDA;                 // Assign I2C pins to USCI_B0
        P1SEL2 |= I2C_SCL + I2C_SDA;                // Assign I2C pins to USCI_B0
        I2C_CTL1 |= UCSWRST + UCSSEL_2;             // Enable SW reset, use SMCLK
        I2C_CTL0 = UCMST + UCMODE_3 + UCSYNC;       // I2C Master, synchronous mode
        I2C_BR0 = I2C_BR0_INIT;                     // Frequency register 0
        I2C_BR1 = I2C_BR1_INIT;                     // Frequency register 1
        I2C_I2CSA = SLAVE_ADDR;                     // Slave Address
        UCB0CTL1 &= ~UCSWRST;                       // Clear SW reset, resume operation
        IE2 |= UCB0TXIE  + UCB0RXIE;                // Enable TX + RX interrupts
    #endif /* PL_HAS_I2C */
    #if PL_HAS_SPI
        init_spi();
    #endif /* PL_HAS_SPI */
    #if PL_PC
        /* test orientation of bitfields */
        test_bitfield_t test_bitfield;      /* testvariable */
        test_bitfield.byte = 0x00;
        test_bitfield.bitfield.low = 0x01;  /* write testvalue to lower nibble */
        if (test_bitfield.byte != 0x01) {   /* test if lower nibble has been written */
            while (1) {
                /* Hey Programmer,
                 * It seems that your compiler uses a
                 * different order for bitfields than mine.
                 * If you still want to use this library,
                 * change, if possible, the order of bitfields in
                 * your compiler or in this library!
                 */
            }
        }
        return;
    #endif /* PL_PC */
    //MLX_INT_PORT &= ~MASK_MLX_INT;
    //MLX_INT_TRIG_DIR |= MASK_MLX_INT_TRIG;
}
