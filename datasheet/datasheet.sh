#!/bin/bash

## Microcontroller
mkdir -p uC
# MSP430x2xx Family User's Guide
wget -nc -O uC/family_guide_x2_slau144j.pdf https://www.ti.com/lit/ug/slau144j/slau144j.pdf
# MSP430G2553 Datasheet
wget -nc -P uC https://www.ti.com/lit/ds/symlink/msp430g2553.pdf
# MSP-EXP430G2 LaunchPad
wget -nc -O uC/msp-exp430g2_launchpad_slau318g.pdf https://www.ti.com/lit/ug/slau318g/slau318g.pdf
# MSP430FR4xx and MSP430FR2xx Family User's Guide
wget -nc -O uC/family_guide_fr_slau445i.pdf https://www.ti.com/lit/ug/slau445i/slau445i.pdf
# MSP430FR2355 Datasheet
wget -nc -P uC https://www.ti.com/lit/ds/symlink/msp430fr2355.pdf
# MSP430FR2355 Launchpad
wget -nc -O uC/msp-exp430fr2355_launchpad_slau680.pdf https://www.ti.com/lit/ug/slau680/slau680.pdf

## Sensor
mkdir -p sensor
wget -nc -P sensor https://www.melexis.com/-/media/files/documents/datasheets/mlx90393-datasheet-melexis.pdf
