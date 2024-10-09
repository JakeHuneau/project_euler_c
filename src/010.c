#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main() {
  int max_prime = 2000000;
  int* sieve = create_prime_sieve(max_prime);
  unsigned long sum = 0;

  for (unsigned long i = 2; i < max_prime; i++) {
    if (sieve[i] == 1) {
      sum += i;
    }
  }

  free(sieve);

  printf("%lu\n", sum);
  
  return 0;
}
