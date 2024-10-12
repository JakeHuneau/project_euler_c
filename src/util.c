// util.c
#include "util.h"
#include <math.h>
#include <stdlib.h>

int is_even(int num) { return num % 2 == 0; }

// Gets all the factors of <num> and returns an array with the factors.
Factors get_factors(unsigned long num) {
  Factors result;
  result.array = (unsigned long *)malloc(num * sizeof(unsigned long));
  result.size = 0;
  for (unsigned long i = 1; i <= sqrt(num); i++) {
    if (num % i == 0) {
      result.array[result.size] = i;
      result.array[result.size + 1] = num / i; // Add other side too
      result.size += 2;
    }
  }

  result.array = (unsigned long *)realloc(result.array,
                                          result.size * sizeof(unsigned long));

  return result;
}

unsigned long long get_triangle_number(unsigned long num) {
  // (n * (n+1)) / 2
  return (num * (num + 1)) / 2;
}

unsigned long long get_next_collatz(unsigned long long current_num) {
  // n -> n / 2 (even n)
  // n -> 3n + 1 (odd n)
  if (is_even(current_num)) {
    return current_num / 2;
  }
  return 3 * current_num + 1;
}
