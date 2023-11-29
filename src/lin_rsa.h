#ifndef LIN_RSA
#define LIN_RSA
#include <gmp.h>
#include <stdlib.h>
void lin_encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n);
void lin_decrypt_block(mpz_t d, mpz_t m, mpz_t *c, mpz_t n);
#endif
