#include "generator.h"

// miller rabin test
bool is_prime(unsigned long n, int k) {
  if (n == 2 || n == 3) return true;
  if (!(n & 1) || n == 1) return false;

  unsigned long d = n - 1;
  while (d % 2 == 0) d >>= 1;

  for (int i = 0; i < k; ++i) {
    unsigned long a = 2 + rand() % (n - 3);
    unsigned long x = fast_mod(a, d, n);

    if (x == 1 || x == n - 1) continue;

    for (int r = 0; r < count_bits(n - 1); ++r) {
      x = fast_mod(x, 2, n);

      if (x == 1) return false;
      if (x == n - 1) break;
    }

    if (x != n - 1) return false;
  }

  return true;
}

int count_bits(unsigned long n) {
  int count = 0;
  while (n) {
    count++;
    n >>= 1;
  }

  return count;
}

void gcd(unsigned long a, unsigned long b, unsigned long* x, unsigned long* y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
  } else {
    unsigned long t_x, t_y;
    gcd(b % a, a, &t_x, &t_y);
    *x = t_y - (b / a) * t_x;
    *y = t_x;
  }
}

void print(Params* p) {
  printf("p: %lu\n", p->p);
  printf("q: %lu\n", p->q);
  printf("n: %lu\n", p->n);
  printf("e: %lu\n", p->e);
  printf("d: %lu\n", p->d);
}

// x ^ y % p
unsigned long fast_mod(unsigned long x, unsigned long y, unsigned long p) {
  unsigned long res = 1;

  x %= p;

  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }

  return res;
}

unsigned long get_inverse(unsigned long e, unsigned long r) {
  unsigned long x = 0, y = 0;
  gcd(e, r, &x, &y);

  return x % r;
}

unsigned long get_prime_number() {
  unsigned long n = 0;
  int tries = 0;

  do {
    n = rand();

    if (tries++ > MAX_TRIES) {
      printf("Exceeded maximum number of tries.\n");
      exit(-1);
    }
  } while (!is_prime(n, TEST_NUMBER));

  return n;
}

Params* params_generator() {
  Params* p = (Params*)malloc(sizeof(Params));
  if (p == NULL) {
    exit(-1);
  }

  p->p = get_prime_number();
  p->q = get_prime_number();
  p->n = p->p * p->q;

  unsigned long r = (p->p - 1) * (p->q - 1);
  p->e = get_prime_number();
  p->d = get_inverse(p->e, r);

  return p;
}

int main() {
  time_t t;
  srand((unsigned)time(&t));
  Params* p = params_generator();
  print(p);
  free(p);

  return EXIT_SUCCESS;
}
