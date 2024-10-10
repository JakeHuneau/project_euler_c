#include <math.h>
#include <stdio.h>

int main() {
  unsigned long long sol = 600851475143;
  unsigned long long i;

  // Remove smallest prime factors by working way up
  for (i = 2; i < sqrt(sol) / 2; i++) {
    while (sol % i == 0) {
      printf("%llu /= %llu -> %llu\n", sol, i, sol / i);
      sol /= i;
    }
  }
  printf("%llu", sol);
  return 0;
}
