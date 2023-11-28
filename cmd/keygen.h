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
void write_to_file(mpz_t, mpz_t, mpz_t);
int main(int argc, char *argv[]);

#endif