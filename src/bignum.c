// bignum.c
#include "bignum.h"
#include <stdio.h>
#include <stdlib.h>

// Prints things backwards to go in correct order
void print_bignum(BigNum *bignum) {
  for (int i = bignum->num_digits - 1; i >= 0; i--) {
    printf("%u", bignum->digits[i]);
  }
  printf("\n");
}

// Creates a new bignum with all 0
BigNum new_bignum(unsigned int num_digits) {
  BigNum bignum;
  bignum.num_digits = num_digits;
  bignum.digits = (unsigned int *)malloc(num_digits * sizeof(unsigned int));

  // initialize all the digits with 0
  for (int i = 0; i < num_digits; i++) {
    bignum.digits[i] = 0;
  }
  return bignum;
}

// Creates a bignum from a string
BigNum bignum_from_string(char num_string[], unsigned int length) {
  BigNum bignum = new_bignum(length);
  for (int i = length - 1; i >= 0; i--) {
    int digit = num_string[i] - '0'; // '0' = 48
    bignum.digits[length - i - 1] = digit;
  }
  return bignum;
}

// Carrys over all digits to make sure everything is single digits
BigNum carryover_bignum(BigNum bignum) {
  // Give room in case it grew
  BigNum return_bignum = new_bignum(bignum.num_digits + 1);

  for (int i = 0; i < bignum.num_digits; i++) {
    int carry = (bignum.digits[i] + return_bignum.digits[i]) / 10;
    int remainder = (bignum.digits[i] + return_bignum.digits[i]) % 10;
    return_bignum.digits[i] = remainder;
    return_bignum.digits[i + 1] = carry;
  }

  while (return_bignum.digits[return_bignum.num_digits - 1] == 0) {
    // Didn't have a final carryover
    return_bignum.num_digits--;
    return_bignum.digits = (unsigned int *)realloc(
        return_bignum.digits, return_bignum.num_digits * sizeof(unsigned int));
  }

  free(bignum.digits);
  return return_bignum;
}

BigNum add_bignum(BigNum bignum1, BigNum bignum2) {
  // Use whichever number is bigger
  unsigned int sum_length = (bignum1.num_digits > bignum2.num_digits)
                                ? bignum1.num_digits
                                : bignum2.num_digits;
  BigNum sum_bignum = new_bignum(sum_length);
  for (int i = 0; i < sum_length; i++) {
    if (i < bignum1.num_digits) {
      sum_bignum.digits[i] += bignum1.digits[i];
    }
    if (i < bignum2.num_digits) {
      sum_bignum.digits[i] += bignum2.digits[i];
    }
  }
  return carryover_bignum(sum_bignum);
}

BigNum multiplay_bignum(BigNum bignum1, BigNum bignum2) {
  // 99 * 99 = 9801 => Length can be sum of both parts size
  BigNum prod_bignum = new_bignum(bignum1.num_digits + bignum2.num_digits);

  // ex: bignum1 = 12, bignum2 = 34
  //   12
  //  x45
  //  ---
  //   60
  // +480
  // ----
  //  540
  //
  // So this is really (12 * 5) + (12 * 40)
  // And (12 * 5) is really (10 * 5) + (2 * 5) = (50 + 10)
  // {2, 1} * {5, 4}
  // {10, 5, 0} + {0, 8, 4} = {10, 13, 4} = {0, 14, 4} = {0, 4, 5}
  for (int i = 0; i < bignum1.num_digits; i++) {
    for (int j = 0; j < bignum2.num_digits; j++) {
      prod_bignum.digits[i + j] += bignum1.digits[i] * bignum2.digits[j];
    }
  }
  return carryover_bignum(prod_bignum);
}
