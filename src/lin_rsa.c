#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

// encrypts a single block
void lin_encrypt_block(mpz_t e, mpz_t m, mpz_t *c, mpz_t n) {
  mpz_set_ui(*c, 1);
#ifdef DEBUG
  mpz_out_str(stdout, 10, m);
  printf("^");
  mpz_out_str(stdout, 10, e);
  printf(" mod ");
  mpz_out_str(stdout, 10, n);
  printf("\n");
#endif

  if (mpz_tstbit(e, 0)) {
    mpz_mul(*c, *c, m);
    mpz_mod(*c, *c, n);
  }
#ifdef DEBUG
  int pow = 1;
  printf("pow table\n");
  printf("pow: %d m: ", pow);
  mpz_out_str(stdout, 10, m);
  printf(" bit: %d c: ", mpz_tstbit(e, 0));
  mpz_out_str(stdout, 10, c);
  printf("\n");
#endif

  while (mpz_sgn(e)) {
    mpz_fdiv_q_2exp(e, e, 1);
    mpz_mul(m, m, m);
    mpz_mod(m, m, n);

    if (mpz_tstbit(e, 0)) {
      mpz_mul(*c, *c, m);
      mpz_mod(*c, *c, n);
    }
#ifdef DEBUG
    pow *= 2;
    printf("pow: %d m: ", pow);
    mpz_out_str(stdout, 10, m);
    printf(" bit: %d c: ", mpz_tstbit(e, 0));
    mpz_out_str(stdout, 10, c);
    printf("\n");
#endif
  }
}

void lin_decrypt_block(mpz_t d, mpz_t m, mpz_t *c, mpz_t n) {
  lin_encrypt_block(d, m, c, n);
}
