#include <string.h>

#include "clefia_test.h"
#include "util.h"

// https://github.com/fedescarpa/clefia/blob/master/clefia.c

const unsigned int key_128[4] = {0x01234567, 0x89abcdef, 0x01234567, 0x89abcdef};
const unsigned int iv_128[4] = {0x01234567, 0x89abcdef, 0x01234567, 0x89abcdef};

const char* plain_text = "Heelo This text is a test plain text.";

void clefia_test() {
	printf("Key:\n");
	print_hex(key_128, 32);
	
	printf("IV:\n");
	print_hex(iv_128, 32);
	
	printf("Plain Text:\n%s\n", plain_text);
	
	char plain[128], cipher[128];
	strcpy(plain, plain_text);
	unsigned char realSize = strlen(plain_text);
	
	clefia_cbc_128_enc(plain, cipher, realSize, iv_128, key_128);
	
	printf("Cipher Text:\n");
	print_hex(cipher, 32);
	
	clefia_cbc_128_dec(plain, cipher, 128, iv_128, key_128);
	printf("Plain Text:\n%s\n", plain);
}
