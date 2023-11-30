#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TEST_NUMBER = 10;
const int MAX_TRIES = 100;

typedef struct Params {
  unsigned long p;
  unsigned long q;
  unsigned long n;
  unsigned long e;
  unsigned long d;
} Params;

bool is_prime(unsigned long, int);
int count_bits(unsigned long);
void gcd(unsigned long, unsigned long, unsigned long*, unsigned long*);
void print(Params*);
unsigned long fast_mod(unsigned long, unsigned long, unsigned long);
unsigned long get_inverse(unsigned long, unsigned long);
unsigned long get_prime_number();
Params* params_generator();

#endif