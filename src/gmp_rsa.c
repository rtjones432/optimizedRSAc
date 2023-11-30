#include "gmp_rsa.h"

// encrypts a single block
void gmp_encrypt_block(mpz_t e, mpz_t m, mpz_t c, mpz_t n) {
  mpz_powm(c, m, e, n);
}
