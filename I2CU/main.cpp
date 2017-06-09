// I2CU - Search for devices on an I2C bus
// Copyright (c) 2009, sford
// Released under the MIT License: http://mbed.org/license/mit
//
// Goes through each device address, seeing if it gets a response
//  - for every device if finds, it prints the 8-bit address
//  - if the program hangs, the bus isn't working (check pull-ups etc)
//  - if it doesn't find your device, check power/bus wiring etc
 
#include "mbed.h"

I2C i2c(p9, p10); // sda, scl

int main() {
    printf("I2CU! Searching for I2C devices...\n");

    int count = 0;
    for (int address=0; address<256; address+=2) {
        if (!i2c.write(address, NULL, 0)) { // 0 returned is ok
            printf(" - I2C device found at address 0x%02X\n", address);
            count++;
        }
    }
    printf("%d devices found\n", count);
}
