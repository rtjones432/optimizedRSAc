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
  mpz_set_str(m, argv[1], 16);
  FILE *key_file = fopen(PUBLIC_KEY_FILE, "r");
  mpz_inp_str(e, key_file, 16);
  mpz_inp_str(n, key_file, 16);
  log_encrypt_block(e, m, c, n);
  mpz_out_str(stdout, 16, c);

  return EXIT_SUCCESS;
}
