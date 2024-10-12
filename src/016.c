#include "bignum.h"
#include <stdio.h>

int main() {
  BigNum num = bignum_from_string("1", 1);

  for (int i = 0; i < 1000; i++) {
    num = add_bignum(num, num);
  }
  int sum = 0;

  for (int i = 0; i < num.num_digits; i++) {
    sum += num.digits[i];
  }

  printf("%i\n", sum);

  return 0;
}
