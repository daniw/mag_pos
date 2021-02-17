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
# MSP430FR2355 Step models
wget -nc -P uC https://webench.ti.com/cad/dlbxl.cgi/newstep/RSM0032B.stp
wget -nc -P uC https://webench.ti.com/cad/dlbxl.cgi/newstep/RHA0040E.stp
wget -nc -P uC https://webench.ti.com/cad/dlbxl.cgi/newstep/PT0048A.stp
wget -nc -P uC https://webench.ti.com/cad/dlbxl.cgi/newstep/DBT0038A.stp

## Sensor
mkdir -p sensor
wget -nc -P sensor https://www.melexis.com/-/media/files/documents/datasheets/mlx90393-datasheet-melexis.pdf

## Amplifiers
mkdir -p amp
# LMV611
wget -nc -P amp https://www.ti.com/lit/ds/symlink/lmv611.pdf
wget -nc -P amp https://webench.ti.com/cad/dlbxl.cgi/newstep/DBV0005A.stp
# TLV522
wget -nc -P amp https://www.ti.com/lit/ds/symlink/tlv522.pdf
wget -nc -P amp https://webench.ti.com/cad/dlbxl.cgi/newstep/DGK0008A.stp

## Connectors
mkdir -p connector
# Molex Picoblade SMT
wget -nc -P connector https://www.molex.com/pdm_docs/sd/532617004_sd.pdf
wget -nc -P connector https://www.molex.com/pdm_docs/stp/53261-7004_stp.zip
# Molex Picoblade THT
wget -nc -P connector https://www.molex.com/pdm_docs/sd/530480450_sd.pdf
wget -nc -P connector https://www.molex.com/pdm_docs/stp/53048-0450_stp.zip
## Potentiometer connection
# red
wget -nc -O connector/keystone-PN5270.STEP "https://www.keyelco.com/stepdown.cfm?p=14618&k=6F26580D-2F86-47BF-9BB6-E04535A5AD25"
#wget -nc -O connector/keystone-PN5005.STEP ""
# black
wget -nc -O connector/keystone-PN5271.STEP "https://www.keyelco.com/stepdown.cfm?p=14586&k=F98EA024-2373-402F-BF82-0138CF619460"
#wget -nc -O connector/keystone-PN5006.STEP ""
# white
wget -nc -O connector/keystone-PN5272.STEP "https://www.keyelco.com/stepdown.cfm?p=14619&k=C50C9A96-91B4-4138-817D-FD08B8CE2903"
#wget -nc -O connector/keystone-PN5007.STEP ""
# orange
wget -nc -O connector/keystone-PN5273.STEP "ihttps://www.keyelco.com/stepdown.cfm?p=14620&k=41E472F1-C1CC-47AF-B45A-8A11BC98AB2C"
#wget -nc -O connector/keystone-PN5008.STEP ""
# yellow
#wget -nc -O connector/keystone-PN5274.STEP ""
#wget -nc -O connector/keystone-PN5009.STEP ""
# brown
#wget -nc -O connector/keystone-PN5275.STEP ""
#wget -nc -O connector/keystone-PN5120.STEP ""
# green
#wget -nc -O connector/keystone-PN5276.STEP ""
#wget -nc -O connector/keystone-PN5121.STEP ""
# blue
#wget -nc -O connector/keystone-PN5277.STEP ""
#wget -nc -O connector/keystone-PN5122.STEP ""
# grey
#wget -nc -O connector/keystone-PN5278.STEP ""
#wget -nc -O connector/keystone-PN5123.STEP ""
# purple
#wget -nc -O connector/keystone-PN5279.STEP ""
#wget -nc -O connector/keystone-PN5124.STEP ""

## spring contact
mkdir -p test
wget -nc -P test https://cdn.harwin.com/pdfs/S25-XX2.pdf
wget -nc -P test https://cdn.harwin.com/pdfs/P25-XX23.pdf
wget -nc -P test https://cdn.harwin.com/cads/s25-022.zip

## Cable
mkdir -p cable
wget -nc -P cable http://www.tensility.com/pdffiles/30-00217.pdf
