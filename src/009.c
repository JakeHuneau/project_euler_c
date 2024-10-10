#include <stdio.h>

int main() {
  // euclid's formula
  // a^2 + b^2 = c^2
  // for m, n where m > n > 0
  // a = m^2 - n^2, b = 2mn, c = m^2 + n^2
  // a + b + c = 1000
  // (m^2 - n^2) + 2mn + (m^2 + n^2) = 1000
  // 2m^2 + 2mn = 1000
  // m^2 + mn = 500
  // m(m+n) = 500
  // m = (sqrt(n^2 + 2000) - n) / 2
  // Only solution to this is m = 20, n = 5
  int m = 20;
  int n = 5;
  unsigned long a = m * m - n * n;
  unsigned long b = 2 * m * n;
  unsigned long c = m * m + n * n;
  printf("%lu\n", a * b * c);

  return 0;
}
