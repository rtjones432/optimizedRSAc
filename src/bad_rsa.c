#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

// encrypts a single block
void encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n) {
  mpz_set_ui(*c, 1);

  if (mpz_tstbit(e, 0)) {
    mpz_mul(*c, *c, m);
    mpz_mod(*c, *c, n);
  }
  while (mpz_sgn(e)) {
    mpz_fdiv_q_2exp(e, e, 1);
    mpz_mul(m, m, m);
    mpz_mod(m, m, n);

    if (mpz_tstbit(e, 0)) {
      mpz_mul(*c, *c, m);
      mpz_mod(*c, *c, n);
    }
  }
}

void decrypt_block(mpz_t d, mpz_t m, mpz_t *c, mpz_t n) {
  encrypt_block(d, m, c, n);
}

void encrypt_hex_str(mpz_t e, char *message, char *cipher_text, mpz_t n) {
  mpz_t m, c;
  mpz_init_set_str(m, message, 16);
  mpz_init(c);

  encrypt_block(e, m, &c, n);

  mpz_clear(m);
  mpz_get_str(cipher_text, 16, c);
  mpz_clear(c);
}

void decrypt_hex_str(mpz_t d, char *message, char *cipher_text, mpz_t n) {
  encrypt_hex_str(d, message, cipher_text, n);
}
