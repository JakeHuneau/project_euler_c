// prime.c
#include <prime.h>
#include <math.h>
#include <stdlib.h>

// Gets nth prime with sieve of Eratosthenes
unsigned long get_nth_prime(unsigned long n) {
  // n * (log(n) + log(log(n)) - 1) is a good approximation of Nth prime.
  // Take of the -1 to be a little bigger and save
  unsigned long sieve_size = n * (log(n) + log(log(n))); 
  // big sieve so need to use heap
  int *sieve = (int *)malloc(sieve_size * sizeof(int));

  for (int i = 0; i < sieve_size; i++) {
    sieve[i] = 1; // Start by assuming everything is a prime
  }

  for (unsigned long i = 2; i < sqrt(sieve_size); i++) {
    unsigned long current_value = i;
    while(1) {
      current_value += i;
      if (current_value >= sieve_size) {
        break;
      }
      sieve[current_value] = 0;
    }
  }

  unsigned long count = 1;
  unsigned long current_prime = 0;

  for (unsigned long i = 3; i < sieve_size; i++) {
    if (sieve[i] == 1) {
      current_prime = i;
      count += 1;
    }
    if (count == n) {
      break;
    }
  }

  free(sieve);

  return current_prime;
  
}

