#include <stdio.h>
#include <util.h>

long sum_factors(int num) {
  Factors factors = get_factors(num);
  long sum = 0;
  for (int i = 0; i < factors.size; i++) {
    if (factors.array[i] != num) {
      sum += factors.array[i];
    }
  }
  return sum;
}

int main() {
  long sum = 0;
  for (int i = 1; i < 10000; i++) {
    long sf1 = sum_factors(i);
    if (i != sf1 && i == sum_factors(sf1)) {
      sum += sf1;
    }
  }
  printf("%lu", sum);
  return 0;
}
