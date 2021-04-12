/*
 * spi.c
 *
 *  Created on: 31.03.2021
 *      Author: daniw
 */

#include "spi.h"

#if PL_HAS_SPI
void init_spi(void){
    /*
     * The recommended eUSCI initialization or reconfiguration process is:
     * 1. Set UCSWRST.
     *    BIS.B #UCSWRST,&UCxCTL1
     * 2. Initialize all eUSCI registers while UCSWRST = 1 (including UCxCTL1).
     * 3. Configure ports.
     * 4. Clear UCSWRST in software.
     *    BIC.B #UCSWRST,&UCxCTL1
     * 5. Enable interrupts (optional) by setting UCRXIE or UCTXIE.
     */
    /* Reset SPI module */
    SPI_CTLW0 |= UCSWRST;
    /* Initialize registers */
    #if SPI_CTLW0_INIT != 0
        SPI_CTLW0 = SPI_CTLW0_INIT;
    #endif
    #if SPI_BRW_INIT != 0
        SPI_BRW = SPI_BRW_INIT;
    #endif
    #if SPI_STATW_INIT != 0
        SPI_STATW = SPI_STATW_INIT
    #endif
    /* Configure ports */
    /* Release SPI module for normal operation */
    SPI_CTLW0 &= ~UCSWRST;
    /* Enable interrupts */
    return;
}
#endif /* PL_HAS_SPI */
