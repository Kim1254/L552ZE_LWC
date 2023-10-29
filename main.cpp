/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "main.h"

#define BAUDRATE 115200
BufferedSerial pc(USBTX, USBRX, BAUDRATE);

// Override console to BufferedSerial (make printf use serial)
FileHandle *mbed::mbed_override_console(int fd)
{
    return &pc;
}

int main()
{
	DO_TEST;
	return 0;
}