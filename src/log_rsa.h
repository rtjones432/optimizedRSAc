#ifndef LOG_RSA
#define LOG_RSA
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
void encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n);
void decrypt_block(mpz_t d, mpz_t m, mpz_t *c, mpz_t n);

void encrypt_hex_str(mpz_t e, char *message, char *cipher_text, mpz_t n);
void decrypt_hex_str(mpz_t d, char *message, char *cipher_text, mpz_t n);
#endif
