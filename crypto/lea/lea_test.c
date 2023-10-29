#include <string.h>
#include <stdint.h>

#include "lea_test.h"
#include "util.h"

#define MAX_BLK 1

#define lea_encrypt_1block lea_encrypt
#define lea_decrypt_1block lea_decrypt

#include "lea.h"
#include "lea_locl.h"
#include "lea_cbc.h"

void lea_test(uint8_t* plain, uint8_t* key, uint8_t* iv) {
	
#if 1
	print_hex(plain, 64);
#endif
	
	LEA_KEY lea_key;

	/* set LEA key */
	lea_set_key(&lea_key, key, 16);

	/* encryption */
	lea_cbc_enc(plain, plain, 64, iv, &lea_key);

	/* decryption */
	lea_cbc_dec(plain, plain, 64, iv, &lea_key);
	
#if 1
	print_hex(plain, 64);
#endif
}

