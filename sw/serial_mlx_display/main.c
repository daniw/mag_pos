#include <msp430.h> 
#include <stdint.h>

/**
 * main.c
 */

//UART
#define TXLED_PIN BIT0
#define TXLED_OUT P1OUT
#define TXLED_DIR P1DIR
#define RXLED_PIN BIT7
#define RXLED_OUT P2OUT
#define RXLED_DIR P2DIR
#define TXD BIT2
#define RXD BIT1

uint8_t buffer[3] = {97,98,99};
uint8_t j;

//I2C
#define CS_PIN BIT4
#define CS_OUT P1OUT
#define CS_DIR P1DIR
#define SLAVE_ADDR 0x0C
#define SCL BIT6
#define SDA BIT7
uint8_t data_;
uint8_t *PRxData;                     // Pointer to RX data
uint8_t RxByteCtr;
uint8_t TxByteCtr;

void initClock()
{
    DCOCTL = 0;
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
}

void initPorts()
{
    P2SEL &= ~((1<<6) | (1<<7));                   // Disable crystal oscillator
    P1DIR = 0xFF;
    P1OUT &= 0x00;
    P2DIR = 0xFF;
    P2OUT &= 0x00;
}

void initUART()
{
    P1SEL |= RXD + TXD;
    P1SEL2 |= RXD + TXD;
    TXLED_DIR |= TXLED_PIN;
    RXLED_DIR |= RXLED_PIN;
    UCA0CTL1 |= UCSSEL_2 + UCSWRST;
    UCA0CTL0 = 0x00;
    UCA0BR0 = 0x8A;
    UCA0BR1 = 0x00;
    UCA0MCTL = UCBRS_7;
    //UCA0STAT |=  UCLISTEN;                    // Loopback-Mode
    UCA0CTL1 &= ~UCSWRST;
    UC0IE |= UCA0RXIE;                          // Enable the Receive  interrupt
    __bis_SR_register(GIE);                     // Enable the global interrupt
}

void I2C_init()
{
    CS_DIR |= CS_PIN;
    CS_OUT |= CS_PIN;
    P1SEL |= SCL + SDA;                         // Assign I2C pins to USCI_B0
    P1SEL2|= SCL + SDA;                         // Assign I2C pins to USCI_B0
    UCB0CTL1 |= UCSWRST;                        // Enable SW reset
    UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;       // I2C Master, synchronous mode
    UCB0CTL1 = UCSSEL_2 + UCSWRST;              // Use SMCLK, keep SW reset
    UCB0BR0 = 160;                              // fSCL = SMCLK/160 = ~100kHz
    UCB0BR1 = 0;
    UCB0I2CSA = SLAVE_ADDR;                     // Slave Address
    UCB0CTL1 &= ~UCSWRST;                       // Clear SW reset, resume operation
    IE2 |= UCB0TXIE;                               // Enable TX interrupt
    IE2 |= UCB0RXIE;                               // Enable RX interrupt
}

void I2C_write(uint8_t data, uint8_t BytesRx) {
    //IE2 &= ~UCB0RXIE;                              // Disable RX interrupt
    while (UCB0CTL1 & UCTXSTP);                  // Ensure stop condition got sent
    //IE2 |= UCB0TXIE;                               // Enable TX interrupt
    data_ = data;
    TxByteCtr = 1;
    RxByteCtr = BytesRx;
    UCB0CTL1 |= UCTR + UCTXSTT;                    // I2C TX, start condition
    //__bis_SR_register(CPUOFF + GIE);               // Enter LPM0 w/ interrupts
    //while (UCB0CTL1 & UCTXSTT);
}

void I2C_read(uint8_t ByteCtr, volatile uint8_t *RxData) {
    //__disable_interrupt();

    //Interrupt management
    //IE2 &= ~UCB0TXIE;                              // Disable TX interrupt
    //IE2 |= UCB0RXIE;                               // Enable RX interrupt

    //Pointer to where data will be stored
    PRxData = (uint8_t *) RxData;                  // Start of RX buffer
    RxByteCtr = ByteCtr;                           // Load RX byte counter

    while (UCB0CTL1 & UCTXSTP);                  // Ensure stop condition got sent
    UCB0CTL1 &= ~UCTR;
    //If only 1 byte will be read send stop signal as soon as it starts transmission
    if(RxByteCtr == 1){
        UCB0CTL1 |= UCTXSTT;                       // I2C start condition
        while (UCB0CTL1 & UCTXSTT);                // Start condition sent?

        UCB0CTL1 |= UCTXSTP;                       // I2C stop condition
        //__enable_interrupt();
    } else {
        UCB0CTL1 |= UCTXSTT;                       // I2C start condition
    }

    //__bis_SR_register(CPUOFF + GIE);               // Enter LPM0 w/ interrupts
    while (UCB0CTL1 & UCTXSTP);                    // Ensure stop condition got sent
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	initClock();
	initPorts();
	initUART();
	I2C_init();

	__bis_SR_register(LPM0_bits + GIE);         // Going to LPM0
    while (1)
    { }
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
    RXLED_OUT |= RXLED_PIN;
    uint8_t value = UCA0RXBUF;
    if (value == 'a')
    {
        UC0IE |= UCA0TXIE;                             // Enable USCI_A0 TX interrupt
        j = 0;
        UCA0TXBUF = buffer[j++];
    }
    else if (value == 's')
    {
        I2C_write(0b00110001, 1);
        //I2C_write(0b00000000);
        //volatile unsigned int i;
        //for (i = 0; i < 6500; i++);
        //I2C_read(1, buffer);
    }
    else if (value == 'r')
    {
        I2C_write(0b01000001, 3);
        //I2C_write(0b01000010);
        //volatile unsigned int i;
        //        for (i = 0; i < 6500; i++);
        //I2C_read(1, buffer);
    }
    RXLED_OUT &= ~RXLED_PIN;
}

#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR(void)
{
    if ((UC0IE & UCA0TXIE) && (IFG2 & UCA0TXIFG))
    {
        TXLED_OUT |= TXLED_PIN;
        UCA0TXBUF = buffer[j++];          // TX next character
        if (j == sizeof buffer)     // TX over?
        {
            UC0IE &= ~UCA0TXIE;         // Disable USCI_A0 TX interrupt
        }
        TXLED_OUT &= ~TXLED_PIN;
        //IFG2 &= ~UCA0TXIFG;
    }
    if (IFG2 & UCB0RXIFG)
    {                              // Receive In
      if (RxByteCtr == 1)
      {
         //buffer[0] = UCB0RXBUF + 50;
         *PRxData = UCB0RXBUF + 45;                           // Move final RX data to PRxData

         UC0IE |= UCA0TXIE;                             // Enable USCI_A0 TX interrupt
         j = 0;
         UCA0TXBUF = buffer[j++];

         //__bic_SR_register_on_exit(CPUOFF);              // Exit LPM0
      }
      else
      {
          *PRxData++ = UCB0RXBUF + 45;                        // Move RX data to address PRxData
          if (RxByteCtr == 2)                            // Check whether byte is second to last to be read to send stop condition
              UCB0CTL1 |= UCTXSTP;
          //__no_operation();
      }
      RxByteCtr--;                                       // Decrement RX byte counter
      //IFG2 &= ~UCB0RXIFG;
  }

  if (IFG2 & UCB0TXIFG)
  {                                              // Master Transmit
      if (TxByteCtr)                                 // Check TX byte counter
      {
            UCB0TXBUF = data_;

            TxByteCtr--;                                     // Decrement TX byte counter
      }
      else
      {
          PRxData = buffer;                  // Start of RX buffer
          UCB0CTL1 &= ~UCTR;
          UCB0CTL1 |= UCTXSTT;                       // I2C repeated start condition
          if(RxByteCtr == 1)
          {
              while (UCB0CTL1 & UCTXSTT);                // Start condition sent?
              UCB0CTL1 |= UCTXSTP;                       // I2C stop condition
          }
          //UCB0CTL1 |= UCTXSTP;                             // I2C stop condition
          IFG2 &= ~UCB0TXIFG;                              // Clear USCI_B0 TX int flag
          //__bic_SR_register_on_exit(CPUOFF);               // Exit LPM0
      }
      //IFG2 &= ~UCB0TXIFG;
  }
}

