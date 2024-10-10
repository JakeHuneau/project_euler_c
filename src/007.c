#include "prime.h"
#include <stdio.h>

int main() {

  unsigned long prime = get_nth_prime(10001);

  printf("\n%lu\n", prime);

  return 0;
}
