#ifndef KEYGEN_H
#define KEYGEN_H
#define PUBLIC_KEY_FILE "id_rsa.pub"
#define PRIVATE_KEY_FILE "id_rsa"
#define DEFAULT_BIT_LENGTH 2048

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include <unistd.h>

void usage();
void keygen(mpz_t n, mpz_t e, mpz_t d, unsigned int bit_length);
void write_to_file(mpz_t n, mpz_t e, mpz_t d);

#endif
