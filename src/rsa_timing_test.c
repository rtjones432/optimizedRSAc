#include "gmp_rsa.h"
#include "keygen.h"
#include "lin_rsa.h"
#include "log_rsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
int main(int argc, char *argv[]) {
  clock_t start, stop;
  // TODO: write timing functions for each
  mpz_t m, c, e, d, n;
  mpz_init(m);
  mpz_init(c);
  mpz_init(e);
  mpz_init(d);
  mpz_init(n);
  unsigned long size_list[8] = {16, 32, 64, 128, 256, 512, 1024, 2048};
  gmp_randstate_t state;
  gmp_randinit_default(state);
  for (int i = 0; i < sizeof(size_list) / sizeof(unsigned long); i++) {
    printf("\ntesting on keysize and block size of %lu\n", size_list[i]);
    start = clock();
    keygen(n, e, d, size_list[i]);
    stop = clock();
    // mpz_out_str(stdout, 10, n);
    // mpz_out_str(stdout, 10, e);
    // mpz_out_str(stdout, 10, d);
    printf("in ticks %ld\n", stop - start);
    mpz_urandomb(m, state, size_list[i]);
    if (i == 0) {
      start = clock();
      lin_encrypt_block(e, m, c, n);
      stop = clock();
      printf("loop method clocks: %ld time: %ld\n", stop - start,
             (stop - start) / CLOCKS_PER_SEC);
    } else {
      printf("loop method clocks: --- time: ---\n");
    }

    start = clock();
    log_encrypt_block(e, m, c, n);
    stop = clock();
    printf("log method clocks %ld time %ld\n", stop - start,
           (stop - start) / CLOCKS_PER_SEC);

    // start timer
    start = clock();
    gmp_encrypt_block(e, m, c, n);
    // stop timer
    stop = clock();
    printf("gmp method clocks %ld time %ld\n", stop - start,
           (stop - start) / CLOCKS_PER_SEC);
  }
  return EXIT_SUCCESS;
}
