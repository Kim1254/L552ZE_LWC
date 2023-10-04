/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define BAUDRATE 115200
BufferedSerial pc(USBTX, USBRX, BAUDRATE);

#ifdef AES_CRYPTO

#include "aes_test.h"
#define test_crypto() aes_test()

#elif PRESENT_CRYPTO

#include "test_present.h"
#define test_crypto() present_test()

#elif CLEFIA_CRYPTO

#include "clefia_test.h"
#define test_crypto() clefia_test()

#elif LEA_CRYPTO

#include "lea_test.h"
#define test_crypto() lea_test()

#elif ENOCORO_CRYPTO

#include "enocoro_test.h"
#define test_crypto() enocoro_test()

#elif TRIVIUM_CRYPTO

#include "trivium_test.h"
#define test_crypto() trivium_test()

#else
	
#define test_crypto() {}

#endif

// Override console to BufferedSerial (make printf use serial)
FileHandle *mbed::mbed_override_console(int fd)
{
    return &pc;
}

int main()
{
	test_crypto();
	return 0;
}