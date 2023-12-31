#include "log_rsa.h"

// encrypts a single block
void log_encrypt_block(mpz_t e, mpz_t m, mpz_t c, mpz_t n) {
  mpz_t te, tm;
  mpz_set_ui(c, 1);
  mpz_init_set(te, e);
  mpz_init_set(tm, m);
#ifdef DEBUG
  mpz_out_str(stdout, 10, m);
  printf("^");
  mpz_out_str(stdout, 10, e);
  printf(" mod ");
  mpz_out_str(stdout, 10, n);
  printf("\n");
#endif

  if (mpz_tstbit(te, 0)) {
    mpz_mul(c, c, tm);
    mpz_mod(c, c, n);
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

  while (mpz_sgn(te)) {
    mpz_fdiv_q_2exp(te, te, 1);
    mpz_mul(m, m, m);
    mpz_mod(m, m, n);

    if (mpz_tstbit(te, 0)) {
      mpz_mul(c, c, m);
      mpz_mod(c, c, n);
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

void log_decrypt_block(mpz_t d, mpz_t m, mpz_t c, mpz_t n) {
  log_encrypt_block(d, m, c, n);
}

void encrypt_hex_str(mpz_t e, char *message, char *cipher_text, mpz_t n) {
  mpz_t m, c;
  mpz_init_set_str(m, message, 16);
  mpz_init(c);

  log_encrypt_block(e, m, c, n);

  mpz_clear(m);
  mpz_get_str(cipher_text, 16, c);
  mpz_clear(c);
}

void decrypt_hex_str(mpz_t d, char *message, char *cipher_text, mpz_t n) {
  encrypt_hex_str(d, message, cipher_text, n);
}
