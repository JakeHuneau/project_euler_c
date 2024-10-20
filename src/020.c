#include "bignum.h"
#include <stdio.h>

int main() {
  BigNum sol = bignum_from_string("1", 1);
  for (int i = 2; i < 100; i++) {
    char n[3];
    char n_len = sprintf(n, "%d", i);
    BigNum mult_bignum = bignum_from_string(n, n_len);
    sol = multiplay_bignum(sol, mult_bignum);
  }
  unsigned long sum = 0;
  for (int i = 0; i < sol.num_digits; i++) {
    sum += sol.digits[i];
  }
  printf("%lu\n", sum);
  return 0;
}
