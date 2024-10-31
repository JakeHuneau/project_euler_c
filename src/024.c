// See this for info:
// https://stemhash.com/efficient-permutations-in-lexicographic-order/

#include <math.h>

int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  int res = 1;
  for (int i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}

void shift_array_left(int *arr, int array_size, int start_index) {
  for (int i = start_index; i < array_size - 1; i++) {
    arr[i] = arr[i + 1];
  }
}

int main() {
  int values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  long solution = 0;
  // Want the millionth so starting number is 1000000 - 1 = 999999
  long current = 999999;

  for (int i = 0; i <= 9; i++) {
    int divisor = factorial(9 - i);
    int index = (current / divisor) % (10 - i);
    int value = values[index];
    // Need to shift everything left to get right value
    shift_array_left(values, 10, index);
    // Build up the number from the biggest down
    solution += value * pow(10, 9 - i);
    current %= divisor;
  }

  return solution != 2783915460;
}
