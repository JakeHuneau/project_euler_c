#include "prime.h"
#include <stdlib.h>

int main() {
  int max_prime = 2000000;
  int *sieve = create_prime_sieve(max_prime);
  unsigned long sum = 0;

  for (unsigned long i = 2; i < max_prime; i++) {
    if (sieve[i] == 1) {
      sum += i;
    }
  }

  free(sieve);

  return sum != 142913828922;
}
