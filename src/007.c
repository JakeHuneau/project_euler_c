#include <stdio.h>
#include "prime.h"

int main() {

  unsigned long prime = get_nth_prime(10001);

  printf("\n%lu\n", prime);
  
  return 0;
}
