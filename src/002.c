#include <stdio.h>

int main() {
  int solution = 2; // Initialize with first value (2)

  int fib1 = 1;
  int fib2 = 2;
  int temp_fib = 1;

  int MAX = 4000000;

  while (fib2 < MAX) {
    temp_fib = fib1;
    fib1 = fib2;
    fib2 += temp_fib;

    if (fib2 % 2 == 0) {
      solution += fib2;
    }
  }

  printf("%i\n", solution);
}
