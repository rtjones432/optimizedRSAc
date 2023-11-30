#include <stdio.h>
#include <stdlib.h>

// encrypts a single block
void simple_encrypt_block(long e, long m, long *c, long n) {
  *c = 1;

  if (e & 1) {
    *c *= m;
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
