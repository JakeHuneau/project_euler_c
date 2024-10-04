#include <stdio.h>
#include "util.h"

int main() {
  int solution = 0;

  int fib1 = 1;
  int fib2 = 2;
  int temp_fib = 1;

  int MAX = 4000000;

  while (fib2 < MAX) {
    if (is_even(fib2)) {
      solution += fib2;
    }

    temp_fib = fib1;
    fib1 = fib2;
    fib2 += temp_fib;

  }

  printf("%i\n", solution);
}
