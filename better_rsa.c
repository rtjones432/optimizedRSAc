#include <gmp.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define block_size 64

void pmenc(mpz_t m, mpz_t e, mpz_t n, mpz_t c) {
  mpz_out_str(stdout, 10, m);
  printf("^");
  mpz_out_str(stdout, 10, e);
  printf("mod");
  mpz_out_str(stdout, 10, n);
  printf("=");
  mpz_out_str(stdout, 10, c);
  printf("\n");
}

// encrypts a single block
void encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n) {
  mpz_set_ui(*c, 1);

  if (mpz_tstbit(e, 0)) {
    mpz_mul(*c, *c, m);
    mpz_mod(*c, *c, n);
  }
  pmenc(m, e, n, *c);
  while (mpz_sgn(e)) {
    mpz_fdiv_q_2exp(e, e, 1);
    mpz_mul(m, m, m);
    mpz_mod(m, m, n);

    if (mpz_tstbit(e, 0)) {
      mpz_mul(*c, *c, m);
      mpz_mod(*c, *c, n);
    }
    pmenc(m, e, n, *c);
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
  mpz_init_set_ui(e, 7);
  mpz_init_set_ui(n, 77);
  char str[10] = "9";
  char ct[10];
  encrypt_hex(e, str, ct, n);
  printf("ct: %s", ct);
  mpz_clear(e);
  mpz_clear(n);
  return EXIT_SUCCESS;
}
