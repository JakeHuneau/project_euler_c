#include <util.h>

enum NumberType { DEFICIENT, PERFECT, ABUNDANT };

enum NumberType get_number_type(unsigned long num) {
  Factors factors = get_factors(num);
  unsigned long sum = 0;
  for (int i = 0; i < factors.size; i++) {
    if (factors.array[i] != num) {
      sum += factors.array[i];
    }
  }
  if (sum < num) {
    return DEFICIENT;
  } else if (sum == num) {
    return PERFECT;
  }
  return ABUNDANT;
}

int main() {
  enum { MAX = 28123 };
  enum NumberType num_types[MAX];
  for (int i = 2; i < MAX; i++) {
    num_types[i] = get_number_type(i);
  }

  int is_sum[MAX] = {0};
  int num_abundants = 0;
  for (long i = 2; i < MAX; i++) {
    if (num_types[i] == ABUNDANT) {
      for (long j = 3; j < MAX; j++) {
        if (num_types[j] == ABUNDANT) {
          long sum = i + j;
          if (sum < MAX) {
            is_sum[sum] = 1;
          }
        }
      }
    }
  }

  unsigned long solution = 0;
  for (int i = 1; i < MAX; i++) {
    if (is_sum[i] == 0) {
      solution += i;
    }
  }

  return solution != 4179871;
}
