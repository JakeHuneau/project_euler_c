#include "bignum.h"

int main() {
  BigNum bn1 = bignum_from_string("1", 1);
  BigNum bn2 = bignum_from_string("1", 1);
  BigNum bn_temp = bignum_from_string("1", 1);
  int solution = 2;
  while (1) {
    bn_temp = bn2;
    bn2 = add_bignum(bn1, bn2);
    bn1 = bn_temp;
    solution++;
    if (bn2.num_digits == 1000) {
      break;
    }
  }

  return solution != 4782;
}
