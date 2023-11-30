#include "keygen.h"
#include "log_rsa.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  mpz_t d, n, m, c;
  mpz_init(d);
  mpz_init(n);
  mpz_init(m);
  mpz_init(c);
  mpz_set_str(m, argv[1], 16);
  FILE *key_file = fopen(PRIVATE_KEY_FILE, "r");
  mpz_inp_str(d, key_file, 16);
  mpz_inp_str(n, key_file, 16);
  log_encrypt_block(d, m, c, n);
  mpz_out_str(stdout, 16, c);

  return EXIT_SUCCESS;
}
