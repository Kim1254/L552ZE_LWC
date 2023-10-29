/*

	PRESENT TEST
	
	Keysize: 16 bytes
	Textsize: 64 bytes
	Round: 10

*/

#include <string.h>

#include "test_present.h"
#include "util.h"

// https://github.com/kurtfu/present/blob/master/test/test_main.c

void present_test(uint8_t* plain, uint8_t* key)
{
#if 1
	print_hex(plain, 64);
#endif
	
	/* test_encrypt() */
	present_encrypt(plain, key);
	
	/* test_decrypt() */
	present_decrypt(plain, key);
	
#if 1
	print_hex(plain, 64);
#endif
}