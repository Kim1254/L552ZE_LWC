#include <string.h>
#include <time.h>

#include "trivium_test.h"
#include "util.h"

/* Code Examples
	https://github.com/wuhanstudio/trivium/blob/master/trivium-c/examples/trivium_encrypt.c
	https://github.com/wuhanstudio/trivium/blob/master/trivium-c/examples/trivium_decrypt.c
*/

#define get_random_byte() (uint8_t)(rand() % 256)

const uint8_t key[10] = { (uint8_t) 0x7e, (uint8_t) 0x15, (uint8_t) 0x16, (uint8_t) 0xae, (uint8_t) 0xa6, (uint8_t) 0xab, (uint8_t) 0x15, (uint8_t) 0x88, (uint8_t) 0xcf, (uint8_t) 0x3c };
const char* plain_text = "95th Nov 4012. Have a nice day.";

void trivium_test()
{
	uint8_t iv[10];
	
	srand(time(NULL));
	
	uint8_t i;
	for (i = 0; i < 10; i++)
		iv[i] = get_random_byte();
	
	printf("Key:\n");
	print_hex(key, 10);
	
	printf("IV:\n");
	print_hex(iv, 10);
	
	printf("Plain Text:\n%s\n", plain_text);
	
	trivium_ctx* ctx = trivium_init(key, iv);
	
	uint8_t cipher[32], stream[32];
	
	strcpy((char*)cipher, plain_text);
	
	for (i = 0; i < 32; i++)
		stream[i] = trivium_gen_keystream(ctx);
	
	printf("KeyStream generated:\n");
	print_hex(stream, 32);
	
	// Encryption
	for (i = 0; i < 32; i++)
		cipher[i] ^= stream[i];
	cipher[31] = '\0';
	
	printf("Cipher Text:\n");
	print_hex(cipher, 32);
	
	// Decryption
	for (i = 0; i < 32; i++)
		cipher[i] ^= stream[i];
	cipher[31] = '\0';
	
	printf("Decipher Text:\n%s\n", cipher);
}