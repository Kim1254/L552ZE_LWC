#include <string.h>
#include <time.h>

#include "trivium_test.h"
#include "util.h"

/*
https://github.com/wuhanstudio/trivium/blob/master/trivium-c/examples/trivium_encrypt.c
https://github.com/wuhanstudio/trivium/blob/master/trivium-c/examples/trivium_decrypt.c
*/

void trivium_test(uint8_t* plain, uint8_t* key, uint8_t* iv)
{
	print_hex(plain, 64);
	
	//// TEST ////
	
	uint8_t i;
	uint8_t keystream[64] = {0};
	
	//// Initialization ////
	trivium_ctx* ctx = trivium_init(key, iv);
	
	//// Stream generation ////
	for (i = 0; i < 64; i++)
		keystream[i] = trivium_gen_keystream(ctx);
	
	// encryption
	for (i = 0; i < 64; i++)
		plain[i] ^= keystream[i];
	
	// decryption
	for (i = 0; i < 64; i++)
		plain[i] ^= keystream[i];
	
	//// TEST ENDS ////
	
	print_hex(keystream, 64);
	print_hex(plain, 64);
}