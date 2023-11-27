#include <gmp.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define block_size 64

// encrypts a single block
void encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n) {
  mpz_set_ui(*c, 0);

  if (mpz_tstbit(e, 0)) {
    mpz_add(*c, *c, m);
    mpz_mod(*c, *c, n);
  }

  while (e) {
    mpz_fdiv_q_2exp(e, e, 1);
    mpz_mul(m, m, m);
    mpz_mod(m, m, n);

    if (mpz_tstbit(e, 0)) {
      mpz_add(*c, *c, m);
      mpz_mod(*c, *c, n);
    }
  }
}

void encrypt_hex(mpz_t e, char *message, char *cipher_text, mpz_t n) {
  mpz_t m, c;
  mpz_init_set_str(m, message, 16);
  mpz_init(c);

  encrypt_block(e, m, &c, n);

  mpz_clear(m);
  mpz_get_str(cipher_text, 16, c);
  mpz_clear(c);
}

int main(int argc, char *argv[]) {
  mpz_t e, n;
  char str[10] = "hi";
  char ct[10];
  encrypt_hex(e, str, ct, n);
  printf("ct: %s", ct);
  mpz_clear(e);
  mpz_clear(n);
  return EXIT_SUCCESS;
}
