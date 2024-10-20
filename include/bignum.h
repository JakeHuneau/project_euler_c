// bignum.h
#ifndef BIGNUM_H
#define BIGNUM_H

typedef struct {
  // digits will be backwards, so if the number is 123 then
  // digits looks like [3,2,1]
  unsigned int *digits;
  unsigned int num_digits;
} BigNum;
BigNum add_bignum(BigNum, BigNum);
BigNum multiplay_bignum(BigNum, BigNum);
BigNum new_bignum(unsigned int);
BigNum bignum_from_string(char[], unsigned int length);
BigNum carryover_bignum(BigNum);
void print_bignum(BigNum*);

#endif

