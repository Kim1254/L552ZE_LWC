#ifndef _TESTMACRO_INCLUDED

#define _TESTMACRO_INCLUDED

#ifdef AES_CRYPTO

// Do AES cryptography test
#include "aes_test.h"

// Macros
#define DO_TEST aes_test(g_plain_text, g_key)

// end of AES.

#elif defined PRESENT_CRYPTO

// Do PRESENT cryptography test
#include "test_present.h"

// Marcos
#define DO_TEST present_test(g_plain_text, g_key)

// end of PRESENT.

#elif defined CLEFIA_CRYPTO

// Do CLEFIA cryptography test
#include "clefia_test.h"

// Marcos
#define IV_REQUIRED
#define DO_TEST clefia_test(g_plain_text, g_key, g_iv)

// end of CLEFIA.

#elif defined LEA_CRYPTO

// Do LEA cryptography test
#include "lea_test.h"

// Marcos
#define DO_TEST lea_test()

// end of LEA.

#elif defined ENOCORO_CRYPTO

// Do PRESENT cryptography test
#include "enocoro_test.h"

// Marcos
#define IV_REQUIRED
#define DO_TEST enocoro_test(g_plain_text, g_key, g_iv)

// end of PRESENT.

#elif defined TRIVIUM_CRYPTO

// Do PRESENT cryptography test
#include "trivium_test.h"

// Marcos
#define IV_REQUIRED
#define DO_TEST trivium_test(g_plain_text, g_key, g_iv)

// end of PRESENT.

#else

// Nothing to do.
#define DO_TEST {}

#endif

//// VARIABLE

uint8_t g_plain_text[64] = {
	(uint8_t) 0x6b, (uint8_t) 0xc1, (uint8_t) 0xbe, (uint8_t) 0xe2,
	(uint8_t) 0x2e, (uint8_t) 0x40, (uint8_t) 0x9f, (uint8_t) 0x96,
	(uint8_t) 0xe9, (uint8_t) 0x3d, (uint8_t) 0x7e, (uint8_t) 0x11,
	(uint8_t) 0x73, (uint8_t) 0x93, (uint8_t) 0x17, (uint8_t) 0x2a,
	(uint8_t) 0xae, (uint8_t) 0x2d, (uint8_t) 0x8a, (uint8_t) 0x57,
	(uint8_t) 0x1e, (uint8_t) 0x03, (uint8_t) 0xac, (uint8_t) 0x9c,
	(uint8_t) 0x9e, (uint8_t) 0xb7, (uint8_t) 0x6f, (uint8_t) 0xac,
	(uint8_t) 0x45, (uint8_t) 0xaf, (uint8_t) 0x8e, (uint8_t) 0x51,
	(uint8_t) 0x30, (uint8_t) 0xc8, (uint8_t) 0x1c, (uint8_t) 0x46,
	(uint8_t) 0xa3, (uint8_t) 0x5c, (uint8_t) 0xe4, (uint8_t) 0x11,
	(uint8_t) 0xe5, (uint8_t) 0xfb, (uint8_t) 0xc1, (uint8_t) 0x19,
	(uint8_t) 0x1a, (uint8_t) 0x0a, (uint8_t) 0x52, (uint8_t) 0xef,
	(uint8_t) 0xf6, (uint8_t) 0x9f, (uint8_t) 0x24, (uint8_t) 0x45,
	(uint8_t) 0xdf, (uint8_t) 0x4f, (uint8_t) 0x9b, (uint8_t) 0x17,
	(uint8_t) 0xad, (uint8_t) 0x2b, (uint8_t) 0x41, (uint8_t) 0x7b,
	(uint8_t) 0xe6, (uint8_t) 0x6c, (uint8_t) 0x37, (uint8_t) 0x10
};

// ENOCORO128 16
// TRIVIUM 10
uint8_t g_key[16] = {
	(uint8_t) 0x5d, (uint8_t) 0x6e, (uint8_t) 0x7f, (uint8_t) 0x80,
	(uint8_t) 0x91, (uint8_t) 0xa2, (uint8_t) 0xb3, (uint8_t) 0xc4,
	(uint8_t) 0xd5, (uint8_t) 0xe6, (uint8_t) 0xf7, (uint8_t) 0x08,
	(uint8_t) 0x19, (uint8_t) 0x2a, (uint8_t) 0x3b, (uint8_t) 0x4c
};

#ifdef IV_REQUIRED

// CLEFIA 16
// ENOCORO 8
// TRIVIUM 10
uint8_t g_iv[16] = {
	(uint8_t) 0x01, (uint8_t) 0x23, (uint8_t) 0x45, (uint8_t) 0x67,
	(uint8_t) 0x89, (uint8_t) 0xab, (uint8_t) 0xcd, (uint8_t) 0xef,
	(uint8_t) 0x01, (uint8_t) 0x23, (uint8_t) 0x45, (uint8_t) 0x67,
	(uint8_t) 0x89, (uint8_t) 0xab, (uint8_t) 0xcd, (uint8_t) 0xef
};

#endif

#endif