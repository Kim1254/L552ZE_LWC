/*

	AES128 TEST
	
	Keysize: 16 bytes
	Textsize: 64 bytes
	Round: 10

*/

#include <string.h>

#include "aes_test.h"
#include "util.h"

// https://github.com/kokke/tiny-AES-c/blob/master/test.c

#define STRING_LENGTH 64

// NUM_ENC = STRING_LENGTH / 4
#define NUM_ENC 4

void aes_test(uint8_t* plain, uint8_t* key) {
#if 1
	// Print arguments
	print_hex(plain, STRING_LENGTH);
#endif

	uint8_t i;
	
	//// Initialization ////
	struct AES_ctx ctx;
	AES_init_ctx(&ctx, key);
	
	//// Encryption ////
	for (i = 0; i < NUM_ENC; ++i)
		AES_ECB_encrypt(&ctx, plain + (i * 16));
	
	//// Decryption ////
	for (i = 0; i < NUM_ENC; ++i)
		AES_ECB_decrypt(&ctx, plain + (i * 16));
	
#if 1
	print_hex(plain, STRING_LENGTH);
#endif
}
