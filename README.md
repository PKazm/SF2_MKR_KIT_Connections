# SF2_MKR_KIT_Connections
I consider this a "blinking led" project but for every peripheral and connection on the Smartfusion2 Maker Kit board all at once.

# Softconsole project setup
I follow this guide when creating the Softconsole project:

https://github.com/tstana/M2S010-MKR-KIT_FirstProj/wiki

# Connections implemented

* MSS_UART <-> USB <-> Desktop (Python)
* MSS_GPIO -> Board_LEDs
* FIC_0 -> fab_CorePWM -> Board_LEDs/Board_J8
* FIC_0 -> fab_Nokia5110_Driver -> Board_J7
* MSS_SPI <-> SPI Serial Flash Memory
* MSS_MAC <-> PHY <-> USB Ethernet Dongle (Python)
* MSS_I2C <-> Light Sensor

# Nokia5110_Driver

This custom FPGA fabric core drives an SPI connection to a Nokia 5110 LCD connected to the J7 set of pins on the board (pin headers soldered on). This core connects to the MSS via an APB3 bus interface. I am using this core as an avenue to write ARM firmware as well as provide output from the device. The VDHL could use a rewrite but it works perfectly as far as I can tell.

# CorePWM

This is an official FPGA core provided by Microsemi. It provides a way to check APB connections with an official and presumably guaranteed to work core (spoiler, it does work) as well as provides brightness control for all the LEDs.

# Ethernet and UART data transfer

Both UART and Ethernet tests have their own Python script to stream data representing a SIN wave into the device. The Python scripts do not listen for return responses from the Smartfusion2 device. UART messages sent from the Smartfusion2 are read using PUTTY. Similarly, Ethernet messages sent from the Smartfusion2 are interpretted using Wireshark.

Since both PUTTY and the Python script require exclusive access to the COM port each program was manually started and stopped depending on what I was attempting to look at. Good enough for proving the connections work.

There's been instances when MAC initializing took a long time, several seconds, unsure as to the cause, it happened with the ethernet cable unplugged. I think all of the slow initializations occured after some aspect of my code required a hard reset though.
