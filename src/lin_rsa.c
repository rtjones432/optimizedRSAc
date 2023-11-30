#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

// encrypts a single block
void lin_encrypt_block(mpz_t e, mpz_t m, mpz_t c, mpz_t n) {
  mpz_t te;
  mpz_init_set(te, e);
  mpz_set_ui(c, 1);
  while (mpz_sgn(te)) {
    mpz_mul(c, c, m);
    mpz_mod(c, c, n);
    mpz_sub_ui(te, te, 1);
  }
}

void lin_decrypt_block(mpz_t d, mpz_t m, mpz_t c, mpz_t n) {
  lin_encrypt_block(d, m, c, n);
}
