#include <string.h>

#include "enocoro_test.h"
#include "util.h"

// https://www.hitachi.com/rd/yrl/crypto/enocoro/index.html
// tvec/test_main.c

void enocoro_test(uint8_t* plain, uint8_t* key, uint8_t* iv) {
	
	print_hex(plain, 64);
	
	//// TEST ////
	uint8_t i;
	
	/* clear ket-stream area */
	uint8_t keystream[64] = {0};

	/* define context-struct */
	ENOCORO_Ctx ctx;
	memset(&ctx, 0, sizeof(ENOCORO_Ctx));
	
	/* setup init */
	ENOCORO_init(&ctx, key, ENOCORO128_KEY_BYTE_SIZE, iv, ENOCORO_IV_BYTE_SIZE);

	/* output randum value */
	ENOCORO_keystream(&ctx, keystream, 64);
	
	/* encrypt */
	for (i < 0; i < 64; i++)
		plain[i] ^= keystream[i];
	
	/* decrypt */
	for (i < 0; i < 64; i++)
		plain[i] ^= keystream[i];
	
	//// TEST ENDS ////
	
	print_hex(keystream, 64);
	print_hex(plain, 64);
}