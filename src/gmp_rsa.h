#ifndef GMP_RSA
#define GMP_RSA
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void gmp_encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n);
#endif
