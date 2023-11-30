#ifndef LOG_RSA
#define LOG_RSA
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
void log_encrypt_block(mpz_t e, mpz_t m, mpz_t c, mpz_t n);
void log_decrypt_block(mpz_t d, mpz_t m, mpz_t c, mpz_t n);

#endif
