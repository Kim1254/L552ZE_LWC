#include <string.h>

#include "test_present.h"

// https://github.com/kurtfu/present/blob/master/test/test_main.c

/*****************************************************************************/
/* PLAIN TEXT EXAMPLES                                                       */
/*****************************************************************************/

static uint8_t text_1[] = {0x00u, 0x00u, 0x00u, 0x00u, \
                           0x00u, 0x00u, 0x00u, 0x00u};

static uint8_t text_2[] = {0x00u, 0x00u, 0x00u, 0x00u, \
                           0x00u, 0x00u, 0x00u, 0x00u};

static uint8_t text_3[] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, \
                           0xFFu, 0xFFu, 0xFFu, 0xFFu};

static uint8_t text_4[] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, \
                           0xFFu, 0xFFu, 0xFFu, 0xFFu};

/*****************************************************************************/
/* CIPHER KEY EXAMPLES                                                       */
/*****************************************************************************/

static uint8_t const key_1[] = {0x00u, 0x00u, 0x00u, 0x00u, 0x00u, \
                                0x00u, 0x00u, 0x00u, 0x00u, 0x00u};

static uint8_t const key_2[] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, \
                                0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu};

static uint8_t const key_3[] = {0x00u, 0x00u, 0x00u, 0x00u, 0x00u, \
                                0x00u, 0x00u, 0x00u, 0x00u, 0x00u};

static uint8_t const key_4[] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, \
                                0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu};

/*****************************************************************************/
/* CIPHERED TEXT EXAMPLES                                                    */
/*****************************************************************************/

static uint8_t cipher_1[] = {0x45u, 0x84u, 0x22u, 0x7Bu, \
                             0x38u, 0xC1u, 0x79u, 0x55u};

static uint8_t cipher_2[] = {0x49u, 0x50u, 0x94u, 0xF5u, \
                             0xC0u, 0x46u, 0x2Cu, 0xE7u};

static uint8_t cipher_3[] = {0x7Bu, 0x41u, 0x68u, 0x2Fu, \
                             0xC7u, 0xFFu, 0x12u, 0xA1u};

static uint8_t cipher_4[] = {0xD2u, 0x10u, 0x32u, 0x21u, \
                             0xD3u, 0xDCu, 0x33u, 0x33u};

/*****************************************************************************/
/* DECIPHERED TEXT EXAMPLES                                                  */
/*****************************************************************************/

static uint8_t const decipher_1[] = {0x00u, 0x00u, 0x00u, 0x00u, \
                                     0x00u, 0x00u, 0x00u, 0x00u};

static uint8_t const decipher_2[] = {0x00u, 0x00u, 0x00u, 0x00u, \
                                     0x00u, 0x00u, 0x00u, 0x00u};

static uint8_t const decipher_3[] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, \
                                     0xFFu, 0xFFu, 0xFFu, 0xFFu};

static uint8_t const decipher_4[] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, \
                                     0xFFu, 0xFFu, 0xFFu, 0xFFu};

void present_test()
{
	/* test_encrypt() */
	present_encrypt(text_1, key_1);
    present_encrypt(text_2, key_2);
    present_encrypt(text_3, key_3);
    present_encrypt(text_4, key_4);

	printf("Encryption Test:\n");
	printf("Cmp with cipher text: %d\n", memcmp(cipher_1, text_1, sizeof(cipher_1)));
	printf("Cmp with cipher text: %d\n", memcmp(cipher_2, text_2, sizeof(cipher_2)));
	printf("Cmp with cipher text: %d\n", memcmp(cipher_3, text_3, sizeof(cipher_3)));
	printf("Cmp with cipher text: %d\n", memcmp(cipher_4, text_4, sizeof(cipher_4)));
	
	/* test_decrypt() */
	present_decrypt(cipher_1, key_1);
    present_decrypt(cipher_2, key_2);
    present_decrypt(cipher_3, key_3);
    present_decrypt(cipher_4, key_4);

	printf("Decryption Test:\n");
	printf("Cmp with decipher text: %d\n", memcmp(cipher_1, decipher_1, sizeof(decipher_1)));
	printf("Cmp with decipher text: %d\n", memcmp(cipher_2, decipher_2, sizeof(decipher_2)));
	printf("Cmp with decipher text: %d\n", memcmp(cipher_3, decipher_3, sizeof(decipher_3)));
	printf("Cmp with decipher text: %d\n", memcmp(cipher_4, decipher_4, sizeof(decipher_4)));
}