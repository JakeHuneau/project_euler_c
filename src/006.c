#include <stdio.h>

int main() {
  unsigned long long sum_of_squares = 0;
  unsigned long long square_of_sums = 0;

  for (int i = 0; i <= 100; i++) {
    sum_of_squares += i * i;
    square_of_sums += i;
  }
  square_of_sums *= square_of_sums;

  unsigned long long diff = square_of_sums - sum_of_squares;

  printf("%llu", diff);

  return 0;
}
