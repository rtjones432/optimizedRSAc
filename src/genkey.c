#include "keygen.h"
int main(int argc, char *argv[]) {
  unsigned long bit_length = DEFAULT_BIT_LENGTH;

  int op = 0;
  while ((op = getopt(argc, argv, "l:")) != -1) {
    switch (op) {
    case 'l':
      bit_length = atoi(optarg);
      break;
    default:
      usage();
    }
  }

  mpz_t n, e, d;
  mpz_init(n);
  mpz_init(e);
  mpz_init(d);

  keygen(n, e, d, bit_length);
  write_to_file(n, e, d);

  printf("[!] Done.\n");

  return 0;
}
