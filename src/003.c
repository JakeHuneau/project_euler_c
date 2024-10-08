#include <stdio.h>

int main() {
  unsigned long long sol = 13195;//600851475143;
  unsigned long long i;
  
  for (i = 2; i < sol / 2; i++) {
    while (sol % i == 0) {
      printf("%llu /= %llu -> %llu\n", sol, i, sol / i);
      sol /= i;
    }
  }
  printf("%llu", sol);
  return 0;
}
