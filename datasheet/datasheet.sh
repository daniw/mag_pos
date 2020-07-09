#!/bin/bash

## Microcontroller
mkdir -p uC
# MSP430x2xx Family User's Guide
wget -nc -O uC/family_guide_slau144j.pdf https://www.ti.com/lit/ug/slau144j/slau144j.pdf
# MSP430G2553 Datasheet
wget -nc -P uC https://www.ti.com/lit/ds/symlink/msp430g2553.pdf
# MSP-EXP430G2 LaunchPad
wget -nc -O uC/msp-exp430g2_launchpad_slau318g.pdf https://www.ti.com/lit/ug/slau318g/slau318g.pdf

## Sensor
mkdir -p sensor
wget -nc -P sensor https://www.melexis.com/-/media/files/documents/datasheets/mlx90393-datasheet-melexis.pdf
