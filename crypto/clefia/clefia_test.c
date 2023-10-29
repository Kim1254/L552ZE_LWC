#include <string.h>

#include "clefia_test.h"
#include "util.h"

// https://github.com/fedescarpa/clefia/blob/master/clefia.c

void clefia_test(uint8_t* plain, uint8_t* key, uint8_t* iv) {
#if 1
	// Print arguments
	print_hex(plain, 64);
#endif
	
	uint8_t cipher[64];
	
	//// Do encryption ////
	clefia_cbc_128_enc(plain, cipher, 64, (uint32_t*)iv, (uint32_t*)key);
	
	//// Do decryption ////
	clefia_cbc_128_dec(plain, cipher, 64, (uint32_t*)iv, (uint32_t*)key);
	
#if 1
	// Print results
	print_hex(cipher, 64);
	print_hex(plain, 64);
#endif
}
