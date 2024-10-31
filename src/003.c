#include <math.h>

int main() {
  unsigned long long sol = 600851475143;
  unsigned long long i;

  // Remove smallest prime factors by working way up
  for (i = 2; i < sqrt(sol) / 2; i++) {
    while (sol % i == 0) {
      sol /= i;
    }
  }
  return sol != 6857;
}
