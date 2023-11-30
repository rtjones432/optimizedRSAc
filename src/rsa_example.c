#define DEBUG
#include "keygen.h"
#include "log_rsa.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  mpz_t e, n, m, c;
  mpz_init(e);
  mpz_init(n);
  mpz_init(m);
  mpz_init(c);
  mpz_set_str(m, argv[1], 10);
  mpz_set_str(e, argv[2], 10);
  mpz_set_str(n, argv[3], 10);
  log_encrypt_block(e, m, c, n);
  mpz_out_str(stdout, 10, c);

  return EXIT_SUCCESS;
}
