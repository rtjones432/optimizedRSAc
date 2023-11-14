#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define block_size 64

// encrypts a single block
void encrypt_block(long e, long m, long *c, long n) {
  *c = 0;

  if (e & 1) {
    *c += m;
    *c = *c % n;
  }

  while (e) {
    e >>= 1;
    m *= m;
    m = m % n;

    if (e & 1) {
      *c *= m;
      *c = *c % n;
    }
  }
}

// decrypt a single block
void decrypt_block(long d, long c, long n) { return; }

void encrypt(void *p, void *c, int len, long e, long n) {
  int i;
#pragma omp parrallel for
  for (i = 0; i < len; i += block_size) {
    encrypt_block(e, *((long *)p + i), c + i, n);
  }
  return;
}

int main(int argc, char *argv[]) {
  long c;
  encrypt_block(7, 88, &c, 187);
  printf("c= %ld \n\r", c);

  return EXIT_SUCCESS;
}
