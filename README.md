# WIP-TS5634N151-Encoder-Interface
Work-In-Progress: Code for Teensy 4.1 to convert Tamagawa TS5634N151 encoder data into TS5669N100 encoder data format

This is a project to convert encoder data from one serial + quadrature format to another. 
The TS5643N151 encoder is the encoder used inside Panasonic brand motors on a Denso VS-6354CM industrial robot
The TS5669N100 encoder is compatible (when properly programmed) with several Rockwell Automation Kinetix family AC servo drives
This hardware interface will *hopefully* allow use of the robot's motors paired with Kinetix 2000 series servo drives.

The Teensy, paired with receiving, level shifting, and transmitting hardware will convert the encoder data in real time to the drive's accepted format.
The Teensy will also emulate the EEPROM data typically stored in the TS5669N100 encoder. This EEPROM data contains motor catalog information programmed by the OEM.
This EEPROM data is required when using the Kinetix 2000 AC servo drive
