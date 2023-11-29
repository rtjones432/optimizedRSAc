#ifndef GMP_RSA
#define GMP_RSA
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

void gmp_encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n);
#endif
