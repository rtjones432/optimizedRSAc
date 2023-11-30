#include "keygen.h"

int main(int argc, char *argv[]) {
  unsigned long key_length = DEFAULT_KEY_LENGTH;

  int op = 0;
  while ((op = getopt(argc, argv, "l:")) != -1) {
    switch (op) {
    case 'l':
      key_length = atoi(optarg);
      break;
    default:
      usage();
    }
  }

  mpz_t n, e, d;
  mpz_init(n);
  mpz_init(e);
  mpz_init(d);

  keygen(n, e, d, key_length);
  write_to_file(n, e, d);

  return EXIT_SUCCESS;
}
