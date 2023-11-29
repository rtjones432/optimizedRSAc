#ifndef KEYGEN_H
#define KEYGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include <unistd.h>

const char* PUBLIC_KEY_FILE = "id_rsa.pub";
const char* PRIVATE_KEY_FILE = "id_rsa";
const int DEFAULT_BIT_LENGTH = 2048;

void usage();
void keygen(mpz_t n, mpz_t e, mpz_t e, unsigned int bit_length);
void write_to_file(mpz_t n, mpz_t e, mpz_t d);

#endif